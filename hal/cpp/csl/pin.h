#ifndef _PIN_H_
#define _PIN_H_

#include "bits.h"
#include "HwReg.h"
#include "Port.h"


// TODO: implement lock feature -> datasheet 9.4.8

namespace csl{
namespace pin{

/**
 * @brief Pin Modes.
 */
enum Mode{
    input_mode,
    general_purpouse_output_mode,
    alternate_function_mode,
    analog_mode
};

/**
 * @brief Pin Speeds
 */
enum Speed{
    low,
    medium,
    high,
    very_high
};

/**
 * @brief Pin States.
 */
enum State{
    floating,
    pull_up,
    pull_down,
    push_pull,
    open_drain
};

/**
 * @brief Pin Alternative funtion mapping.
 */
enum AlternateFunction{
    af_0,
    af_1,
    af_2,
    af_3,
    af_4,
    af_5,
    af_6,
    af_7,
    af_8,
    af_9,
    af_10,
    af_11,
    af_12,
    af_13,
    af_14,
    af_15
};



/**
 * @brief Pin Direction.
 */
enum Direction 
{
	in, 
	out
};


/**
* @brief The STM32 Id hardware dependent.
*
*/
enum Id 
{
	pin_0 = 0, // must be 0
	pin_1,
	pin_2,
	pin_3,
	pin_4,
	pin_5,
	pin_6,
	pin_7,
	pin_8,
	pin_9,
	pin_10,
	pin_11,
	pin_12,
	pin_13,
	pin_14,
	pin_15,
	pin_16,
	pin_17,
	pin_18,
	pin_19,
	pin_20,
	pin_21,
	pin_22,
	pin_23,
	pin_24,
	pin_25,
	pin_26,
	pin_27,
	pin_28,
	pin_29,
	pin_30,
	pin_31,
	pin_32,
	pin_33,
	pin_34,
	pin_35,
	pin_36,
	pin_37,
	pin_38,
	pin_39,
	pin_40,
	pin_41,
	pin_42,
	pin_43,
	pin_44,
	pin_45,
	pin_46,
	pin_47,
	pin_48,
	pin_49,
	pin_50,
	pin_51,
	pin_52
};


/**
* @brief The STM32 pin base class.
*
* @param id port ID
*/

template<port::Id id>
class PinBase
{
public:
    /**
     * @brief Initializes the port if required.
     *
     * @param mode Pin Mode
     * @param bitNr bit number
     * @param dir pin direction
     * @param af alternate alternative function 
     * @param state Physical Pin State 
     * @param speed Physical Pin Speed 
     */
    PinBase(unsigned int bitNr,
			Mode mode, 
            Direction dir,
            AlternateFunction af,
			State state,
            Speed speed);

    /**
     * @brief Sets the direction of the pin.
     *
     * @param bitNr bit number
     * @param dir pin direction
     */
    void setDirection(unsigned int bitNr, Direction dir);

private:
    enum
    {
      muxBitWidth = 2,  ///< bit width per mux setting
      syncBitWidth = 2, ///< bit width per sync setting
      pudBitWidth = 1   ///< bit width per pud setting
    };

    static bool initDonePort; ///< port initialized flag
};


}   // namespace pin


}   // namespace csl




#endif // _PIN_H_
