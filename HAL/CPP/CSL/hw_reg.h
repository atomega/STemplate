#ifndef CSL_HWREG_H_
#define CSL_HWREG_H_

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


	private:
		
};


} // namespace csl
#endif // CSL_HWREG_H_
