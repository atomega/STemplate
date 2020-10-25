#ifndef _PIN_H_
#define _PIN_H_

#include "bits.h"
#include "HwReg.h"
#include "Port.h"

namespace csl{
namespace pin{


enum Mode{
    INPUT_MODE,
    GENERAL_PURPOUSE_OUTPUT_MODE,
    ALTERNATE_FUNCTION_MODE,
    ANALOG_MODE
};

enum {
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