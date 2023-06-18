# FS_DISPLAY
This is the software of the display mounted on the dashboard of the MMR Combustion car, which runs on a STM32F769 microcontroller with a 480x272 display.  
This is an adaptation of the MMR Hybrid display.    
## Data  
Almost every single parameter is represented by the _Data_ struct, which contains:
 * **value**, which is the actual value
 *  **conversionFactor**, value needed to be multiplied when the data is read
 *  **isUpdated**, flag which indicates that the value is updated
 *  **priority**, priority assigned to the alarm in case it gets triggered
 *  **alarmStatus**, status of the alarm, to ensure that there isn't more than one alarm in queue that points to the same _Data_
 *  **max/minValue**, max/min value at which the alarm gets triggered, if this particular data does not trigger an alarm (ex. gear) then they can be set to _EMPTY_VALUE_
 *  **alarmDeactivationTime**, time in milliseconds when the corresponding alarm was deactivated (either by timeout or by the driver with the corresponding button)  

Most Data are read from the **CAN** bus through an interrupt, which calls _decodifyCan1Msg()_ or _decodifyCan2Msg()_ depending if the message is received from CAN1 or CAN2, while also checking if the values are in a _critical_ state, i.e. the corresponding alarm needs to be triggered.
There are 2 exceptions: 
 1. **tractionControl**, which is actually read from the **ADC3**, which has it's own thread **tractionAcquisition** dedicated to continously read from the ADC
 2. **map**, which can be either _BASE_ or _ECHO_, is toggled with the **mapBtn** button on the dashboard  
   
In both of these cases, when they change they send a notification to the display to inform the driver of the change.  

## Data Classes
Every _Data_ is grouped in a class, currently there are:
 * **DataThermalPressure**, which contains datas regarding thermals and pressure sensors
 * **DataMechanics**, which contains mechanical values of the car
 * **DataControls**, which containts values of the controls of the car (ex. tractionControl)

All of these classes are contained in the _Dataset_
##Dataset Class
It contains every single parameter, there is only _one_ global instance of this class which is initialized at the start of the main function, it contains:
* **Data classes** mentioned before
* **DataTyres**, which contains the thermal data of tyres, they are not represented by the _Data_ struct because of the particular way they are read
* **DataScreen**, which contains information about the screen
* **DataMessage[3]**, which are the **3** (as of now, more can be added) possible message that can be sent to the driver 
* **Buttons**, which represents the buttons that the driver can use, they are:
  1. **dispBtn**, which changes the screen displayed
  2. **okBtn**, used by the driver to remove the current pop-up
  3. **markBtn**, used to start the lap timer and set the current location as the start
  4. **mapBtn**, used to change the map
* **Lap Timer Variables**

## Tyres

The temperature of the single tyres is read with a thermal imager, the tyre is divided in 16 sectors, and the temperature is the mean value of the temperature of the single sectors. Because a CAN message can only contain 8 bytes, 2 messages are sent fot every tyre, with every single byte being the temperature of a single sector.  
In order to know the temperature of a single tyre, the software:
1. Reads 2 messages from CAN and stores them in a 16 byte array **tempSectors**, every time it updates a sector it sets the corresponding bit in a 16 bit variable called **tempSectorsUpdated**
2. Once every bit of **tempSectorsUpdated** is set, the software calculates the mean value of **tempSectors** and stores it in **temperature**, then it resets all bit of **tempSectorsUpdated**

## Buttons
Buttons are represented by their own struct, **Button**, which contains:
* **port**, the corresponding GPIO port
* **pin**, the corresponding GPIO pin
* **state**, the state of the button, can be _PRESSED_, _NOTPRESSED_ or _DISABLED_, the latter is used when the button's corresponding action has been done but the button is still pressed and we don't want to repeat the action unless the button is released
* **timeWhenPressed**, time in milliseconds when the button was pressed

They are handled in their own thread by the **buttonsHandler()** function, which checks if a button has been held for long enough for the corresponding action to be done, even if for something only the single press of the button is required (ex. to change screen), there is an anti-debounce time in which the button needs to be held down.

## Alarms
Alarms is a generic term to indicate something that needs to be communicated to the driver with a pop-up, which contains 2 fields:
 1. **name**, which is the name of the source of the alarm
 2. **value**, which is the actual "value" of the alarm (can either be the value of the corresponding _Data_ or additional information) 

They are represented by the **Alarm** struct:
 * **priority**, the priority of the alarm, goes from _0_ to _5_ with 0 being the highestand 5 being  simple notifications
 * **name**, name to be diplayed in the _name_ field
 * **contents**, _void*_ which points to the contents of the alarm
 * **type**, enum indicating the type of the content

The reason for the void* and the type is to have all of the possible alarms/notification unified so that they can all go in the same queue, even if the alarm is relative to a particular _Data_ or if it points to a string that tells the driver to stop. Because of this, there is also the possibility of adding additional types, as an example we could add software alarms for debug purposes to know when something goes wrong or when something is updated.
As mentioned in the last paragraph, all of the alarms go in the same **queue** with priority using the **insertAlarmInQueue()** function, which is a global matrix containings _Alarms_, the priority of the alarm determines the starting row where the _Alarm_ will be placed. To get alarms from the queue, we have 2 ways:
1. **extractAlarmFromQueue()**, which _removes_ the first Alarm from the highest priority row and returns it, after this operation the queue is updated, every Alarm gets moved forward by one place, if it's in the head of the row it gets "promoted" to the next higher priority row, by doing this we don't have the problem of lower priority alarms never getting shown because of the continous presence of higher-priority ones
2. **peekAlarmFromQueue()**, which returns the pointer to the first Alarm of the highest priority row _without_ removing it, whis is used just to check if there are active alarms

