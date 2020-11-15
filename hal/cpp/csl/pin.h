#ifndef _PIN_H_
#define _PIN_H_

#include "bits.h"
#include "hw_reg.h"
#include "port.h"


// TODO: implement lock feature -> datasheet 9.4.8

namespace csl{
namespace pin{

enum
{
	noOfPins = 64
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
 * @brief Pin Modes.
 */
enum Mode{
    input_mode,
    general_purpouse_output_mode,
    alternate_function_mode,
    analog_mode
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
 * @brief Pin Speeds
 */
enum Speed{
    low,
    medium,
    high,
    very_high
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


constexpr port::Id pinMap[noOfPins] = 
{
port::XX,
port::C,
port::C,
port::C,
port::F,
port::F,
port::G,
port::C,
port::C,
port::C,
port::C,
port::A,
port::A,
port::A,
port::XX,
port::XX,
port::A,
port::A,
port::A,
port::A,
port::A,
port::C,
port::C,
port::B,
port::B,
port::B,
port::XX,
port::XX,
port::XX,
port::B,
port::XX,
port::XX,
port::B,
port::B,
port::B,
port::B,
port::B,
port::C,
port::C,
port::C,
port::C,
port::A,
port::A,
port::A,
port::A,
port::A,
port::XX,
port::XX,
port::A,
port::A,
port::A,
port::C,
port::C,
port::C,
port::D,
port::B,
port::B,
port::B,
port::B,
port::B,
port::B,
port::B,
port::XX,
port::XX
};







/**
* @brief The STM32 Pin Id "hardware dependent".
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
	pin_52,
	pin_53,
	pin_54,
	pin_55,
	pin_56,
	pin_57,
	pin_58,
	pin_59,
	pin_60,
	pin_61,
	pin_62,
	pin_63
};


/**
 * @brief Template meta programming to get the port ID derived from the pin ID.
 *
 * @tparam pinId pin ID
 */
template<Id pinId>
struct GetPort
{

	


  static const port::Id id = pinMap[pinId];

  //static const port::Id id = pinId < port::numPins ? port::a : port::b;
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
     * @param bitNr bit number
     * @param dir pin direction
     * @param mode Pin Mode
     * @param state Physical Pin State 
     * @param speed Physical Pin Speed 
     * @param af alternative function 
     */
    PinBase(unsigned int bitNr,
            Direction dir,
			Mode mode, 
			State state,
            Speed speed,
            AlternateFunction af);

    /**
     * @brief Sets the direction of the pin.
     *
     * @param bitNr bit number
     * @param dir pin direction
     */
    void setDirection(unsigned int bitNr, Direction dir);

private:
    static bool initDonePort; ///< port initialized flag
};



/**
 * @brief Abstracts C2000 pins.
 *
 * @tparam id pin ID
 */
template<Id id>
class Pin : public PinBase<GetPort<id>::id>
{

  public:

    /**
     * @brief Initializes the pin to the default configuration.
     *
     * @param dir pin direction (default: in)
     * @param af alternative function 
     * @param isPullupEn true if pull-up enabled (default: enabled)
     * @param sync sync to specified clock (default: sync to system clock)
     */
    /*
	  Pin(Direction dir = in,
        Mux mux = fun1,
        bool isPullupEn = true,
        Sync sync = syncToSysClk);
*/
    /**
     * @brief Sets the direction of the pin.
     *
     * @param dir pin direction
     */
    void setDirection(Direction dir);

    /**
     * @brief Sets the pin.
     */
    void set();

    /**
     * @brief Clears the pin.
     */
    void clear();

    /**
     * @brief Toggles the pin.
     */
    void toggle();

    /**
     * @brief Returns the state of the pin.
     *
     * @return pin state
     */
    bool get() const;
};

}   // namespace pin


}   // namespace csl




#endif // _PIN_H_
