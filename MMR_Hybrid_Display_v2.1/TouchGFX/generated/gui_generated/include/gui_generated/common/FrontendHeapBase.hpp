/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDHEAPBASE_HPP
#define FRONTENDHEAPBASE_HPP

#include <common/Meta.hpp>
#include <common/Partition.hpp>
#include <mvp/MVPHeap.hpp>

#include <touchgfx/transitions/NoTransition.hpp>
#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>

#include <gui/race_screen/RACEView.hpp>
#include <gui/race_screen/RACEPresenter.hpp>
#include <gui/warmup_screen/WARMUPView.hpp>
#include <gui/warmup_screen/WARMUPPresenter.hpp>
#include <gui/set_screen/SETView.hpp>
#include <gui/set_screen/SETPresenter.hpp>
#include <gui/old_home_screen/OLD_HOMEView.hpp>
#include <gui/old_home_screen/OLD_HOMEPresenter.hpp>
#include <gui/old_race_screen/OLD_RACEView.hpp>
#include <gui/old_race_screen/OLD_RACEPresenter.hpp>
#include <gui/old_drag_screen/OLD_DRAGView.hpp>
#include <gui/old_drag_screen/OLD_DRAGPresenter.hpp>
#include <gui/old_endurance_screen/OLD_ENDURANCEView.hpp>
#include <gui/old_endurance_screen/OLD_ENDURANCEPresenter.hpp>
#include <gui/old_skidpad_screen/OLD_SKIDPADView.hpp>
#include <gui/old_skidpad_screen/OLD_SKIDPADPresenter.hpp>
#include <gui/old_setup_screen/OLD_SETUPView.hpp>
#include <gui/old_setup_screen/OLD_SETUPPresenter.hpp>


/**
 * This class provides the memory that shall be used for memory allocations
 * in the frontend. A single instance of the FrontendHeap is allocated once (in heap
 * memory), and all other frontend objects such as views, presenters and data model are
 * allocated within the scope of this FrontendHeap. As such, the RAM usage of the entire
 * user interface is sizeof(FrontendHeap).
 *
 * @note The FrontendHeap reserves memory for the most memory-consuming presenter and
 * view only. The largest of these classes are determined at compile-time using template
 * magic. As such, it is important to add all presenters, views and transitions to the
 * type lists in this class.
 *
 */
class FrontendHeapBase : public touchgfx::MVPHeap
{
public:
    /**
     * A list of all view types. Must end with meta::Nil.
     * @note All view types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< RACEView,
            touchgfx::meta::TypeList< WARMUPView,
            touchgfx::meta::TypeList< SETView,
            touchgfx::meta::TypeList< OLD_HOMEView,
            touchgfx::meta::TypeList< OLD_RACEView,
            touchgfx::meta::TypeList< OLD_DRAGView,
            touchgfx::meta::TypeList< OLD_ENDURANCEView,
            touchgfx::meta::TypeList< OLD_SKIDPADView,
            touchgfx::meta::TypeList< OLD_SETUPView,
            touchgfx::meta::Nil > > > > > > > >
            > GeneratedViewTypes;

    /**
     * Determine (compile time) the View type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedViewTypes >::type MaxGeneratedViewType;

    /**
     * A list of all presenter types. Must end with meta::Nil.
     * @note All presenter types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< RACEPresenter,
            touchgfx::meta::TypeList< WARMUPPresenter,
            touchgfx::meta::TypeList< SETPresenter,
            touchgfx::meta::TypeList< OLD_HOMEPresenter,
            touchgfx::meta::TypeList< OLD_RACEPresenter,
            touchgfx::meta::TypeList< OLD_DRAGPresenter,
            touchgfx::meta::TypeList< OLD_ENDURANCEPresenter,
            touchgfx::meta::TypeList< OLD_SKIDPADPresenter,
            touchgfx::meta::TypeList< OLD_SETUPPresenter,
            touchgfx::meta::Nil > > > > > > > >
            > GeneratedPresenterTypes;

    /**
     * Determine (compile time) the Presenter type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedPresenterTypes >::type MaxGeneratedPresenterType;

    /**
     * A list of all transition types. Must end with meta::Nil.
     * @note All transition types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< touchgfx::NoTransition,
            touchgfx::meta::Nil
            > GeneratedTransitionTypes;

    /**
     * Determine (compile time) the Transition type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedTransitionTypes >::type MaxGeneratedTransitionType;

    virtual void gotoStartScreen(FrontendApplication& app)
    {
        app.gotoOLD_HOMEScreenNoTransition();
    }
protected:
    FrontendHeapBase(touchgfx::AbstractPartition& presenters, touchgfx::AbstractPartition& views, touchgfx::AbstractPartition& transitions, FrontendApplication& app)
        : MVPHeap(presenters, views, transitions, app)
    {

    }

};

#endif // FRONTENDHEAPBASE_HPP
