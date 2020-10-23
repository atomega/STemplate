#ifndef _CSL_BITS_H_
#define _CSL_BITS_H_

namespace csl
{

/**
 * @brief Bits
 */
enum
{
  bit_0  = 0x00000001, bit_1  = 0x00000002, bit_2  = 0x00000004, bit_3  = 0x00000008,
  bit_4  = 0x00000010, bit_5  = 0x00000020, bit_6  = 0x00000040, bit7  = 0x00000080,
  bit_8  = 0x00000100, bit_9  = 0x00000200, bit_10 = 0x00000400, bit11 = 0x00000800,
  bit_12 = 0x00001000, bit_13 = 0x00002000, bit_14 = 0x00004000, bit15 = 0x00008000,
  bit_16 = 0x00010000, bit_17 = 0x00020000, bit_18 = 0x00040000, bit19 = 0x00080000,
  bit_20 = 0x00100000, bit_21 = 0x00200000, bit_22 = 0x00400000, bit23 = 0x00800000,
  bit_24 = 0x01000000, bit_25 = 0x02000000, bit_26 = 0x04000000, bit27 = 0x08000000,
  bit_28 = 0x10000000, bit_29 = 0x20000000, bit_30 = 0x40000000, bit31 = 0x80000000
}

/*
template<class T, unsigned int START, unsigned int STOP>
struct Bits {
		Bits& operator=(T v)
		{
			
		}

		operator T() const
		{
			
		}

	private:
		T _raw;
};
*/

} // namespace csl

#endif // _CSL_BITS_H_
