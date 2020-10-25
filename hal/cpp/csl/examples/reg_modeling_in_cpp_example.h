// https://www.youtube.com/watch?v=TYq bgvHfxjM

template<class T, uint8_t START, uint8_t SIZE>
struct Bits {
    Bits& operator=(T v) {}

    operator T() const {}

    private:
    T _raw;
};

union Control {
    struct OPM{
        typedef Bits<uint16_t, 10, 2> bits;
        enum { NO_CHANGE = 0, AS_STANDBY = 1};
    };
    struct CTRL_BR{
        enum { NO_CHANGE = 0, BRANCH_NORMAL = 1};
    };
    struct CTRL_BR1 : CTRL_BR{
        typedef Bits<uint16_t, 8, 2> bits;
    };
    struct CTRL_BR2 : CTRL_BR{
        typedef Bits<uint16_t, 6, 2> bits;
    };

    union Bits {
        Control::OPM::bits OPM;
        Control::CTRL_BR1::bits CTRL_BR1;
        Control::CTRL_BR2::bits CTRL_BR2;
    } bits;
    uint16_t raw;
};


Control r;

r.bits.OPM = Control::OPM::AS_STANDBY;


Control r;
device.read(r);

if(r.bits.OPM == Control::OPM::AS_STANDBY) {
	// ...
}