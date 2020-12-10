#include "cpu.h"

CPU::CPU(Bus *b)
{
    bus = b;
}

uint16_t CPU::getPC()
{
    return reg_pc.reg;
}


void CPU::execute(uint8_t opcode)
{
    switch(opcode)
    {
        case 0x06:
                {
                    immediate();
                    ld_nn(&reg_bc.hi);
                }
                break;
        case 0x0E:
                {
                    immediate();
                    ld_nn(&reg_bc.lo);
                }
                break;
        case 0x16:
                {
                    immediate();
                    ld_nn(&reg_de.hi);
                }
                break;
        case 0x1E:
                {
                    immediate();
                    ld_nn(&reg_de.lo);
                }
                break;
        case 0x26:
                {
                    immediate();
                    ld_nn(&reg_hl.hi);
                }
                break;
        case 0x2E:
                {
                    immediate();
                    ld_nn(&reg_hl.lo);
                }
                break;

        default:
            fmt::print(fg(fmt::color::crimson), "Opcode {0:#x} not implemented!\n", opcode);
    }
}

/*addressing modes*/
void CPU::immediate()
{
    reg_pc.reg++;
}

/*addressing modes*/

/*instructions*/
//LD nn, n
void CPU::ld_nn(uint8_t *reg)
{
    uint8_t value = bus->read(reg_pc.reg);
    *reg = value; 
    cycles += 8;
    reg_pc.reg++;
}

/*instructions*/