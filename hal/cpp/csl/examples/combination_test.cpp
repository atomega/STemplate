

union MODER {
    struct MODES{
        enum { INPUT_MODE = 0,
               GENERAL_PURPOSE_OUTPUT_MODE = 1,
               ALTERNATIVE_FUNCTION_MODE = 2,
               ANALOG_MODE = 3};
    };
    struct MODE_0 : MODES{
        typedef Bits<uint32_t, 0, 2> bits;
    };
    struct MODE_1 : MODES{
        typedef Bits<uint32_t, 2, 2> bits;
    };
    struct MODE_2 : MODES{
        typedef Bits<uint32_t, 4, 2> bits;
    };
    struct MODE_3 : MODES{
        typedef Bits<uint32_t, 6, 2> bits;
    };
    struct MODE_4 : MODES{
        typedef Bits<uint32_t, 8, 2> bits;
    };
    struct MODE_5 : MODES{
        typedef Bits<uint32_t, 10, 2> bits;
    };
    struct MODE_6 : MODES{
        typedef Bits<uint32_t, 12, 2> bits;
    };
    struct MODE_7 : MODES{
        typedef Bits<uint32_t, 14, 2> bits;
    };
    struct MODE_8 : MODES{
        typedef Bits<uint32_t, 16, 2> bits;
    };
    struct MODE_9 : MODES{
        typedef Bits<uint32_t, 18, 2> bits;
    };
    struct MODE_10 : MODES{
        typedef Bits<uint32_t, 20, 2> bits;
    };
    struct MODE_11 : MODES{
        typedef Bits<uint32_t, 22, 2> bits;
    };
    struct MODE_12 : MODES{
        typedef Bits<uint32_t, 24, 2> bits;
    };
    struct MODE_13 : MODES{
        typedef Bits<uint32_t, 26, 2> bits;
    };
    struct MODE_14 : MODES{
        typedef Bits<uint32_t, 28, 2> bits;
    };
    struct MODE_15 : MODES{
        typedef Bits<uint32_t, 30, 2> bits;
    };

    union Bits {
        MODER::MODE_0::bits MODE_0;
        MODER::MODE_1::bits MODE_1;
        MODER::MODE_2::bits MODE_2;
        MODER::MODE_3::bits MODE_3;
        MODER::MODE_4::bits MODE_4;
        MODER::MODE_5::bits MODE_5;
        MODER::MODE_6::bits MODE_6;
        MODER::MODE_7::bits MODE_7;
        MODER::MODE_8::bits MODE_8;
        MODER::MODE_9::bits MODE_9;
        MODER::MODE_10::bits MODE_10;
        MODER::MODE_11::bits MODE_11;
        MODER::MODE_12::bits MODE_12;
        MODER::MODE_13::bits MODE_13;
        MODER::MODE_14::bits MODE_14;
        MODER::MODE_15::bits MODE_15;
    } bits;
    uint32_t raw;
};


template<Id id>
struct GetAddrReg
{
  static const uintptr_t ctrl;
};




MODER mode_reg = MODER::MODE_14::ANALOG_MODE;