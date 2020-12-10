#ifndef BUS_H
#define BUS_H

#include "mmu.h"

class Bus
{
    public:
        Bus();
        ~Bus() {}

        uint8_t read(uint16_t address);
        void write(uint16_t address, uint8_t value);

        void loadROM(std::string path);

    private:
        MMU mem {};
};



#endif