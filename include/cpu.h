#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <fmt/core.h>
#include <fmt/color.h>
#include "bus.h"

union Register
{
    struct
    {
        uint8_t hi;
        uint8_t lo;
    };
    uint16_t reg;
};

class CPU
{
    public:
        CPU(Bus *b);
        ~CPU() {}

        void execute(uint8_t opcode);

        int cycles {};

        uint16_t getPC();
    private:
        /*registers*/
        Register reg_af {};
        Register reg_bc {};
        Register reg_de {};
        Register reg_hl {};
        Register reg_sp {};
        Register reg_pc {};

        /*flags*/
        bool flag_zero {};
        bool flag_add_sub {};
        bool flag_half_carry {};
        bool flag_carry {};


        Bus *bus = nullptr;

        /*addressing modes*/
        void immediate();
        /*addressing modes*/

        /*instructions*/
        void ld_nn(uint8_t *reg);//ld nn, n
        /*instructions*/
};



#endif