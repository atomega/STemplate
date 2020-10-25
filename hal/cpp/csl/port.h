#ifndef _CSL_PORT_H_
#define _CSL_PORT_H_

#include <stdint.h> // C2000 does not define <cstdint>

namespace csl
{

namespace port
{

enum
{
  numPins = 32 ///< number of pins per C2000 port
};

/**
 * @brief The port ID.
 */
enum Id
{
  A,B,C,D,E,F,G
};

enum {
	BASE_ADDRESS_PORT_A = 0x48000000,
	BASE_ADDRESS_PORT_B = 0x48000400,
	BASE_ADDRESS_PORT_C = 0x48000800,
	BASE_ADDRESS_PORT_D = 0x48000C00,
	BASE_ADDRESS_PORT_E = 0x48001000,
	BASE_ADDRESS_PORT_F = 0x48001400,
	BASE_ADDRESS_PORT_G = 0x48001800
};

/**
 * @brief The port register addresses.
 *
 * @tparam id port ID
 */
template<Id id>
struct GetAddrReg
{
  static const uintptr_t MODER;
  static const uintptr_t OTYPER;
  static const uintptr_t OSPEEDER;
  static const uintptr_t PUPDR;
  static const uintptr_t IDR;
  static const uintptr_t ODR;
  static const uintptr_t BSRR;
  static const uintptr_t LCKR;
  static const uintptr_t AFRL;
  static const uintptr_t AFRH;
  static const uintptr_t BRR;
};

/**
 * @brief Implementation of port A
 */
template<>
struct GetAddrReg<A>
{
  static const uintptr_t MODER = BASE_ADDRESS_PORT_A;
  static const uintptr_t OTYPER = MODER + 0x04;
  static const uintptr_t OSPEEDER = MODER + 0x08;
  static const uintptr_t PUPDR = MODER + 0x0C;
  static const uintptr_t IDR = MODER + 0x10;
  static const uintptr_t ODR = MODER + 0x14;
  static const uintptr_t BSRR = MODER + 0x18;
  static const uintptr_t LCKR = MODER + 0x1C;
  static const uintptr_t AFRL = MODER + 0x20;
  static const uintptr_t AFRH = MODER + 0x24;
  static const uintptr_t BRR = MODER + 0x28;
};

/**
 * @brief Implementation of port B
 */
template<>
struct GetAddrReg<B>
{
  static const uintptr_t MODER = BASE_ADDRESS_PORT_B;
  static const uintptr_t OTYPER = MODER + 0x04;
  static const uintptr_t OSPEEDER = MODER + 0x08;
  static const uintptr_t PUPDR = MODER + 0x0C;
  static const uintptr_t IDR = MODER + 0x10;
  static const uintptr_t ODR = MODER + 0x14;
  static const uintptr_t BSRR = MODER + 0x18;
  static const uintptr_t LCKR = MODER + 0x1C;
  static const uintptr_t AFRL = MODER + 0x20;
  static const uintptr_t AFRH = MODER + 0x24;
  static const uintptr_t BRR = MODER + 0x28;
};

/**
 * @brief Implementation of port C
 */
template<>
struct GetAddrReg<C>
{
  static const uintptr_t MODER = BASE_ADDRESS_PORT_C;
  static const uintptr_t OTYPER = MODER + 0x04;
  static const uintptr_t OSPEEDER = MODER + 0x08;
  static const uintptr_t PUPDR = MODER + 0x0C;
  static const uintptr_t IDR = MODER + 0x10;
  static const uintptr_t ODR = MODER + 0x14;
  static const uintptr_t BSRR = MODER + 0x18;
  static const uintptr_t LCKR = MODER + 0x1C;
  static const uintptr_t AFRL = MODER + 0x20;
  static const uintptr_t AFRH = MODER + 0x24;
  static const uintptr_t BRR = MODER + 0x28;
};


/**
 * @brief Abstracts C2000 ports.
 * 
 * @tparam id port ID
 */
template<Id id>
class Port
{
  public:
    /**
     * @brief Initializes the port to the preset sample period.
     *
     * @param initSamplePeriod initializes the sample period if set
     */
    Port(bool initSamplePeriod = false);
};


//
// implementation
//

template<Id id>
Port<id>::Port(bool initSamplePeriod)
{
  if(initSamplePeriod)
  {
    ProtHwRegAccess::allow();

    // Sets the sample period for the entire port to 510 * T_sysclk.
    // This is done, because the sample period cannot be set for each GIO pin separately.
    // More information can be found in the user manual of the C2000 DSP.
    if(!reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::ctrl)->areBitsSet(
        ~static_cast<uint32_t>(0)))
    {
      reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::ctrl)->setValue(
          ~static_cast<uint32_t>(0)); // sample period = 510 * T_sysclk
    }

    ProtHwRegAccess::disallow();
  }
}

} // namespace port

} // namespace csl

#endif _CSL_PORT_H_
