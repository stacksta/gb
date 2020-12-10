#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include "bus.h"

class CPU
{
    public:
        CPU(Bus *b);
        ~CPU() {}

    private:
        /*registers*/
        uint16_t reg_af {};
        uint16_t reg_bc {};
        uint16_t reg_de {};
        uint16_t reg_hl {};
        uint16_t reg_sp {};
        uint16_t reg_pc {};

        /*flags*/
        bool flag_zero {};
        bool flag_add_sub {};
        bool flag_half_carry {};
        bool flag_carry {};


        Bus *bus = nullptr;
};



#endif