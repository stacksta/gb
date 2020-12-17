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
        void setPC(uint16_t address);

        uint16_t getSP();
        void setSP(uint16_t address);

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
        bool flag_n {};
        bool flag_add_sub {};
        bool flag_half_carry {};
        bool flag_carry {};


        Bus *bus = nullptr;

        /*stack functions*/
        void push(uint8_t value);
        uint8_t pop();
        /*stack functions*/


        /*addressing modes*/
        void immediate();
        /*addressing modes*/

        /*instructions*/
        //8bit load
        void ld_nn(uint8_t *reg);//ld nn, n
        void ld_r(uint8_t *r1, uint8_t r2);//ld r1, r2; ld r1, (r2)
        void ld_mem_r(uint16_t *r1, uint8_t r2);//ld (r1), r2
        void ld_a(uint16_t value);//ld A, (r2)
        void ld_n(uint8_t *reg);// ld reg, A; ld (reg), A

        //16bit load
        void ld_nn(uint16_t *reg, uint16_t value);//ld 16 bit reg, 16 bit value 
        
        //8 bit ALU
        void add_byte(uint8_t reg, bool carry);// add A, reg; adc A, reg
        void sub_byte(uint8_t reg, bool carry);// sub reg; A -> A - reg; sbc reg; A -> A - reg - carry; A -> A - (reg+carry);

        void and_byte(uint8_t reg);// A & reg;
        void or_byte(uint8_t reg);// A | reg;
        void xor_byte(uint8_t reg);// A ^ reg;

        void cp_byte(uint8_t reg);// compare A with n (A - reg)
        void inc_byte(uint8_t *reg);// increment reg
        void dec_byte(uint8_t *reg);// decrement reg

        //16 bit ALU
        void add_word(uint16_t value);// ADD HL, reg;
        
        /*instructions*/
};



#endif