// https://www.youtube.com/watch?v=TYqbgvHfxjM

template<class T, uint8_t START, uint8_t SIZE>
struct Bits {
    Bits& operator=(T v) {}

    operator T() const {}

    private:
    T _raw;
}


union Control {
    struct OPM{
        typedef Bits<uint16_t, 10, 2> Bits;
        enum { NO_CHANGE = 0, AS_STANDBY = 1};
    }
    struct CTRL_BR{
        enum { NO_CHANGE = 0, BRANCH_NORMAL = 1};
    }
    struct CTRL_BR1 : CTRL_BR{
        typedef Bits<uint16_t, 8, 2> Bits;
    }
    struct CTRL_BR2 : CTRL_BR{
        typedef Bits<uint16_t, 6, 2> Bits;
    }

    union Bits {
        Control::OPM::Bits OPM;
        Control::CTRL_BR::Bits CTRL_BR;
        Control::CTRL_BR1::Bits CTRL_BR1;
        Control::CTRL_BR2::Bits CTRL_BR2;
    } bits;
    uint16_t raw;
};

