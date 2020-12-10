#include "cpu.h"

CPU::CPU(Bus *b)
{
    bus = b;
}

uint16_t CPU::getPC()
{
    return reg_pc.reg;
}

void CPU::setPC(uint16_t address)
{
    reg_pc.reg = address;
}

void CPU::execute(uint8_t opcode)
{
    switch(opcode)
    {
        case 0x06:
                {
                    immediate();
                    ld_nn(&reg_bc.hi);

                    uint8_t temp = reg_pc.reg - 1;
                    fmt::print(fg(fmt::color::forest_green), "LD B, {0:#x}\n", temp);
                }
                break;
        case 0x0E:
                {
                    immediate();
                    ld_nn(&reg_bc.lo);

                    uint8_t temp = reg_pc.reg - 1;
                    fmt::print(fg(fmt::color::dark_green), "LD C, {0:#x}\n", temp);
                }
                break;
        case 0x16:
                {
                    immediate();
                    ld_nn(&reg_de.hi);

                    uint8_t temp = reg_pc.reg - 1;
                    fmt::print(fg(fmt::color::dark_green), "LD D, {0:#x}\n", temp);                   
                }
                break;
                
        case 0x1E:
                {
                    immediate();
                    ld_nn(&reg_de.lo);

                    uint8_t temp = reg_pc.reg - 1;
                    fmt::print(fg(fmt::color::dark_green), "LD E, {0:#x}\n", temp);
                }
                break;
        case 0x26:
                {
                    immediate();
                    ld_nn(&reg_hl.hi);

                    uint8_t temp = reg_pc.reg - 1;
                    fmt::print(fg(fmt::color::dark_green), "LD H, {0:#x}\n", temp);
                }
                break;
        case 0x2E:
                {
                    immediate();
                    ld_nn(&reg_hl.lo);

                    uint8_t temp = reg_pc.reg - 1;
                    fmt::print(fg(fmt::color::dark_green), "LD L, {0:#x}\n", temp);  
                }
                break;

        
        case 0x7F:
                {
                    ld_r(&reg_af.hi, reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD A, A\n");
                }
                break;
        case 0x78:
                {
                    ld_r(&reg_af.hi, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD A, B\n");
                }
                break;
        case 0x79:
                {
                    ld_r(&reg_af.hi, reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD A, C\n");
                }
                break;
        case 0x7A:
                {
                    ld_r(&reg_af.hi, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD A, D\n");
                }
                break;
        case 0x7B:
                {
                    ld_r(&reg_af.hi, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD A, E\n");
                }
                break;
        case 0x7C:
                {
                    ld_r(&reg_af.hi, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD A, H\n");
                }
                break;
        case 0x7D:
                {
                    ld_r(&reg_af.hi, reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD A, L\n");
                }
                break;
        case 0x7E:
                {
                    //takes 8 cycles
                    ld_r(&reg_af.hi, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD A, (HL)\n");
                }
                break;
        case 0x40:
                {
                    ld_r(&reg_bc.hi, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD B, B\n");
                }
                break;
        case 0x41:
                {
                    ld_r(&reg_bc.hi, reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD B, C\n");
                }
                break;
        case 0x42:
                {
                    ld_r(&reg_bc.hi, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD B, D\n");
                }
                break;
        case 0x43:
                {
                    ld_r(&reg_bc.hi, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD B, e\n");
                }
                break;
        case 0x44:
                {
                    ld_r(&reg_bc.hi, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD B, H\n");
                }
                break;
        case 0x45:
                {
                    ld_r(&reg_bc.hi, reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD B, L\n");
                }
                break;
        case 0x46:
                {
                    //takes 8 cycles
                    ld_r(&reg_bc.hi, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD B, (HL)\n");
                }
                break;
        case 0x48:
                {
                    ld_r(&reg_bc.lo, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD C, B\n");
                }
                break;
        case 0x49:
                {
                    ld_r(&reg_bc.lo, reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD C, C\n");
                }
                break;
        case 0x4A:
                {
                    ld_r(&reg_bc.lo, reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD C, L\n");
                }
                break;
        case 0x4B:
                {
                    ld_r(&reg_bc.lo, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD C, D\n");  
                }
                break;
        case 0x4C:
                {
                    ld_r(&reg_bc.lo, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD C, H\n");  
                }
                break;
        case 0x4D:
                {
                    ld_r(&reg_bc.lo, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD C, L\n");  
                }
                break;
        case 0x4E:
                {
                    //takes 8 cycles
                    ld_r(&reg_bc.lo, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD C, (HL)\n");  
                }
                break;
        case 0x50:
                {
                    ld_r(&reg_de.hi, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD D, B\n");  
                }
                break;
        case 0x51:
                {
                    ld_r(&reg_de.hi, reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD D, C\n");  
                }
                break;
        case 0x52:
                {
                    ld_r(&reg_de.hi, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD D, D\n");  
                }
                break;
        case 0x53:
                {
                    ld_r(&reg_de.hi, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD D, E\n");  
                }
                break;
        case 0x54:
                {
                    ld_r(&reg_de.hi, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD D, H\n");  
                }
                break;
        case 0x55:
                {
                    ld_r(&reg_de.hi, reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD D, L\n");  
                }
                break;
        case 0x56:
                {
                    //takes 8 cycles
                    ld_r(&reg_de.hi, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD D, D\n");  
                }
                break;
        case 0x58:
                {
                    ld_r(&reg_de.lo, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD E, B\n");  
                }
                break;
        case 0x59:
                {
                    ld_r(&reg_de.lo, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD E, C\n");  
                }
                break;
        case 0x5A:
                {
                    ld_r(&reg_de.lo, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD E, D\n");  
                }
                break;
        case 0x5B:
                {
                    ld_r(&reg_de.lo, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD E, E\n");  
                }
                break;
        case 0x5C:
                {
                    ld_r(&reg_de.lo, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD E, H\n");  
                }
                break;
        case 0x5D:
                {
                    ld_r(&reg_de.lo, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD E, L\n");  
                }
                break;
        case 0x5E:
                {
                    //takes 8 cycles
                    ld_r(&reg_de.lo, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD E, (HL)\n");  
                }
                break;
        case 0x60:
                {
                    ld_r(&reg_hl.hi, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD H, B\n");  
                }
                break;
        case 0x61:
                {
                    ld_r(&reg_hl.hi, reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD H, C\n");  
                }
                break;
        case 0x62:
                {
                    ld_r(&reg_hl.hi, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD H, D\n");  
                }
                break;
        case 0x63:
                {
                    ld_r(&reg_hl.hi, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD H, E\n");  
                }
                break;
        case 0x64:
                {
                    ld_r(&reg_hl.hi, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD H, H\n");  
                }
                break;
        case 0x65:
                {
                    ld_r(&reg_hl.hi, reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD H, B\n");  
                }
                break;
        case 0x66:
                {
                    //takes 8 cycles
                    ld_r(&reg_hl.hi, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD H, (HL)\n");  
                }
                break;
        case 0x68:
                {
                    ld_r(&reg_hl.lo, reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD L, B\n");  
                }
                break;
        case 0x69:
                {
                    ld_r(&reg_hl.lo, reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD L, C\n");  
                }
                break;
        case 0x6A:
                {
                    ld_r(&reg_hl.lo, reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD L, D\n");  
                }
                break;
        case 0x6B:
                {
                    ld_r(&reg_hl.lo, reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD L, E\n");  
                }
                break;
        case 0x6C:
                {
                    ld_r(&reg_hl.lo, reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD L, H\n");  
                }
                break;
        case 0x6D:
                {
                    ld_r(&reg_hl.lo, reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD L, L\n");  
                }
                break;
        case 0x6E:
                {
                    //takes 8 cycles
                    ld_r(&reg_hl.lo, bus->read(reg_hl.reg));
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD L, (HL)\n");  
                }
                break;
        // case 0x70:
        //         {
        //             //takes 8 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             ld_r(&val, reg_bc.hi);
        //             cycles += 4;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), B\n");  
        //         }
        //         break;
        // case 0x71:
        //         {
        //             //takes 8 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             ld_r(&val, reg_bc.lo);
        //             cycles += 4;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), C\n");  
        //         }
        //         break;
        // case 0x72:
        //         {
        //             //takes 8 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             ld_r(&val, reg_de.hi);
        //             cycles += 4;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), D\n");  
        //         }
        //         break;
        // case 0x73:
        //         {
        //             //takes 8 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             ld_r(&val, reg_de.lo);
        //             cycles += 4;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), E\n");  
        //         }
        //         break;
        // case 0x74:
        //         {
        //             //takes 8 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             ld_r(&val, reg_hl.hi);
        //             cycles += 4;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), H\n");  
        //         }
        //         break;
        // case 0x75:
        //         {
        //             //takes 8 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             ld_r(&val, reg_hl.lo);
        //             cycles += 4;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), L\n");  
        //         }
        //         break;
        // case 0x36:
        //         {
        //             //takes 12 cycles
        //             uint8_t val = bus->read(reg_hl.reg);
        //             reg_pc.reg++;
        //             uint8_t n = bus->read(reg_pc.reg);
        //             ld_r(&val, n);
        //             cycles += 8;

        //             fmt::print(fg(fmt::color::dark_green), "LD (HL), n\n");  
        //         }
        //         break;
            


        case 0x0A:
                {
                    //takes 8 cycles
                    ld_a(reg_bc.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD A, (BC)\n");
                }
                break;


        default:
            {
                fmt::print(fg(fmt::color::crimson), "Opcode {0:#x} not implemented!\n", opcode);
                reg_pc.reg++;
            }
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

//LD r1, r2
void CPU::ld_r(uint8_t *r1, uint8_t r2)
{
    *r1 = r2;
    cycles += 4;
    reg_pc.reg++;
}

//LD A,n
void CPU::ld_a(uint8_t value)
{
    reg_af.hi = value;
    cycles += 4;
    reg_pc.reg++;
}
/*instructions*/