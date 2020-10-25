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
    INPUT_MODE,
    GENERAL_PURPOUSE_OUTPUT_MODE,
    ALTERNATE_FUNCTION_MODE,
    ANALOG_MODE
};

/**
 * @brief Pin Speeds
 */
enum Speed{
    LOW,
    MEDIUM,
    HIGH,
    VERY_HIGH
};

/**
 * @brief Pin States.
 */
enum State{
    FLOATING,
    PULL_UP,
    PULL_DOWN
};

/**
 * @brief Pin Types.
 */
enum Type{
    PUSH_PULL,
    OPEN_DRAIN
};

enum AlternateFunction{
    AF_0,
    AF_1,
    AF_2,
    AF_3,
    AF_4,
    AF_5,
    AF_6,
    AF_7,
    AF_8,
    AF_9,
    AF_10,
    AF_11,
    AF_12,
    AF_13,
    AF_14,
    AF_15
};


/**
* @brief The STM32 pin base class.
*
* @param id port ID
*/
template<port::Id id>
class PinBase{
    public:

        PinBase();

};

}   // namespace pin
}   // namespace csl

#endif // _PIN_H_