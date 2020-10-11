#ifndef _CSL_HWREG_H_
#define _CSL_HWREG_H_

#include "bits.h"

namespace csl
{

/**
 * @brief Abstraction of STM32 hardware registers.
 *
 * @param RegType register unsigned int type must 
 * match the used architecture bit width
 */
template<typename RegType>
class HWReg
{
	public:
		/**
		 *  @brief Sets bits into the register.
		 *
		 *  @param bits bits to set
		*/ 		  
		void setBits(const RegType& bits)
		{
			reg |= bits;
		}	

		/**
		 *  @brief Clears bits in the register.
		 *
		 *  @param bits bits to clear
		 */
		void clearBits(const RegType& bits)
		{
			reg &= bits;
		}

		/**
		 *  @brief Checks if the register matches bits.
		 *
		 *  @param bits bits to be checked
		 *
		 *  @return true if bit pattern matches bits and false if not.  
		 */
		bool areBitsSet(const RegType& bits)
		{
			return (reg & bits) == bits;
		}

		/**
		 * @brief Sets value into the register.
		 *
		 * @param value value to be set into the register
		 */
		void setValue(const RegType& value)
		{
			reg = value;
		}

		/**
		 * @brief Sets a sub-value in the register.
		 *
		 * @param bitWidth bit width of the sub-value
		 * @param shift shift for the sub-value
		 *
		 * @param value sub-value to be set
		 */
		 template<unsigned int bitWidth, unsigned int shift>
		 void setSubValue(const RegType&  value)
		 {
			clearBits(((static_cast<RegType>(1) << bitWidth) - static_cast<RegType>(1)) << shift);
			setBits(value << shift); 			 
		 }

	private:
		 /**
		  * @brief The destructor.
		  *
		  * @note Is set private to prevent destruction of directly mapped register. 
		  */
		~HWReg(); 		 

		/**
		 * @brief The copy constructor.
		 *
		 * @note Is set private to prevent copying of directly mapped register.
		 */
		HWReg(const  HWReg&);

		/**
		 * @brief The assignment operator.
		 *
		 * @note Is set private to prevent copying directly mapped register.
		 */
		HWReg& operator=(const HWReg&);
		
		volatile RegType reg; ///< register which is directly mapped to the register address
};


} // namespace csl
#endif // _CSL_HWREG_H_

_
