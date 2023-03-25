#ifndef MODEL_HPP
#define MODEL_HPP

#include "main.h"

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void updateDisplay();

    void saveCurrentScreenIndex(uint8_t cScreen);

    uint8_t getCurrentScreenIndex();

protected:
    ModelListener* modelListener;

    uint8_t currentScreenIndex;
};

#endif // MODEL_HPP
