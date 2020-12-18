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
        /*8 bit loads*/
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
        
        case 0x70:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_bc.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), B\n");  
                }
                break;
        case 0x71:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_bc.lo);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), C\n");  
                }
                break;
        case 0x72:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_de.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), D\n");  
                }
                break;
        case 0x73:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_de.lo);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), E\n");  
                }
                break;
        case 0x74:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_hl.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), H\n");  
                }
                break;
        case 0x75:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_hl.lo);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), L\n");  
                }
                break;
        case 0x36:
                {
                    //takes 12 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    ld_mem_r(&reg_hl.reg, n);
                    cycles += 8;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), n\n");  
                }
                break;
            


        case 0x0A:
                {
                    //takes 8 cycles
                    ld_a(reg_bc.reg);

                    fmt::print(fg(fmt::color::dark_green), "LD A, (BC)\n");
                }
                break;
        case 0x1A:
                {
                    //takes 8 cycles
                    ld_a(reg_de.reg);

                    fmt::print(fg(fmt::color::dark_green), "LD A, (DE)\n");                
                }
                break;
        case 0xFA:
                {
                    //take 16 cycles
                    reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t address = (hi<< 8) | lo;

                    ld_a(address);
                    cycles += 8;

                    fmt::print(fg(fmt::color::dark_green), "LD A, (nn)\n");                
                }
                break;
        case 0x3E:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    reg_af.hi = bus->read(reg_pc.reg);  
                    cycles += 8;

                    fmt::print(fg(fmt::color::dark_green), "LD A, #\n");                
                }
                break;

        case 0x47:
                {
                    ld_n(&reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD B, A\n");                
                }
                break;
        case 0x4F:
                {
                    ld_n(&reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD C, A\n");                
                }
                break;
        case 0x57:
                {
                    ld_n(&reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD D, A\n");                
                }
                break;
        case 0x5F:
                {
                    ld_n(&reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD E, A\n");                
                }
                break;
        case 0x67:
                {
                    ld_n(&reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "LD H, A\n");                
                }
                break;
        case 0x6F:
                {
                    ld_n(&reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "LD L, A\n");                
                }
                break;

        case 0x02:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_bc.reg, reg_af.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (BC), A\n");                
                }
                break;
        case 0x12:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_de.reg, reg_af.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (DE), A\n");                
                }
                break;
        case 0x77:
                {
                    //takes 8 cycles
                    ld_mem_r(&reg_hl.reg, reg_af.hi);
                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL), A\n");                
                }
                break;
        case 0xEA:
                {
                    //takes 16 cycles
                    reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t address = (hi << 8) | lo;

                    ld_mem_r(&address, reg_af.hi);
                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD (nn), A\n");                
                }
                break;


        case 0xF2:
                {
                    //takes 8 cycles
                    //put value at address $FF00 + C into A
                    uint8_t value = bus->read(0xF00 + reg_bc.hi);
                    reg_af.hi = value;

                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD A, ($FF00 + C)\n");  
                }
                break;

        case 0xE2:
                {
                    //takes 8 cycles
                    //put A into address $FF00 + C
                    bus->write(0xFF00 + reg_bc.hi, reg_af.hi);
                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD ($FF00 + C), A\n");
                }
                break;

        case 0x3A:
                {
                    //takes 8 cycles
                    //put value at address HL into A. Decrement HL.
                    uint8_t value = bus->read(reg_hl.reg);
                    reg_af.hi = value;

                    reg_hl.reg -= 1;

                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD A, (HL-) \n");                   
                }   
                break;

        case 0x32:
                {
                    //takes 8 cycles
                    //put A into memory address HL. Decrement HL.
                    bus->write(reg_hl.reg, reg_af.hi);
                    reg_hl.reg -= 1;

                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL-), A\n");
                }
                break;

        case 0x2A:
                {
                    //takes 8 cycles
                    //put value at address HL into A. Increment HL.
                    uint8_t value = bus->read(reg_hl.reg);
                    reg_af.hi = value;

                    reg_hl.reg += 1;

                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD A, (HL+)\n");
                }
                break;

        case 0x22:
                {
                    //takes 8 cycles
                    //put A into memory address HL. Increment HL.
                    bus->write(reg_hl.reg, reg_af.hi);
                    reg_hl.reg += 1;

                    cycles += 8;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD (HL+), A\n");
                }   
                break;


        case 0xE0:
                {
                    //takes 12 cycles
                    //put A into memory address $FF00+n
                    immediate();
                    uint8_t n = bus->read(reg_pc.reg);
                    bus->write(0xFF00 + n, reg_af.hi);

                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD ($FF00+n), A\n");     
                }
                break;

        case 0xF0:
                {
                    //takes 12 cycles
                    //put memory address $FF00+n into A
                    immediate();
                    uint8_t n = bus->read(reg_pc.reg);

                    uint8_t value = bus->read(0xFF00 + n);
                    reg_af.hi = n;


                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD A, ($FF00+n)\n");     
                }
                break;

        /*16 bit loads*/

        case 0x01:
                {
                    //takes 12 cycles
                    reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t nn = (hi << 8) | lo;

                    ld_nn(&reg_bc.reg, nn);

                    cycles += 12;

                    fmt::print(fg(fmt::color::dark_green), "LD BC, nn\n");     
                }
                break;
        case 0x11:
                {
                    //takes 12 cycles
                     reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t nn = (hi << 8) | lo;

                    ld_nn(&reg_de.reg, nn);

                    cycles += 12;

                    fmt::print(fg(fmt::color::dark_green), "LD DE, nn\n");                        
                }
                break;
        case 0x21:
                {
                    //takes 12 cycles
                     reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t nn = (hi << 8) | lo;

                    ld_nn(&reg_hl.reg, nn);

                    cycles += 12;

                    fmt::print(fg(fmt::color::dark_green), "LD HL, nn\n");                        
                }
                break;
        case 0x31:
                {
                    //takes 12 cycles
                    reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t nn = (hi << 8) | lo;

                    ld_nn(&reg_sp.reg, nn);

                    cycles += 12;

                    fmt::print(fg(fmt::color::dark_green), "LD SP, nn\n");                        
                }
                break;

        case 0xF9:
                {
                    //takes 8 cycles
                    ld_nn(&reg_sp.reg, reg_hl.reg);
                    cycles += 8;

                    fmt::print(fg(fmt::color::dark_green), "LD SP, HL\n");                                    
                }
                break;

        case 0xF8:
                {
                    //takes 12 cycles
                    immediate();
                    uint16_t n = bus->read(reg_pc.reg);

                    reg_hl.reg = reg_sp.reg + n;

                    flag_zero = false;
                    flag_n = false;

                    if(reg_hl.reg > 0xFFFF)
                    {
                        flag_carry = true;
                    }
                    else
                        flag_carry = false;

                    //H indicates carry for lower 4bits of the result?
                    if((reg_hl.lo & 0xF) + (n & 0xF) > 0xF)
                    {
                        flag_half_carry = true;
                    }
                    else 
                        flag_half_carry = false;

                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LDHL SP, n\n");                                    
                }
                break;
        
        case 0x08:
                {
                    //takes 20 cycles!
                    reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);

                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t nn = (hi << 8) | lo;

                    bus->write(nn, reg_sp.lo);
                    nn += 1;
                    bus->write(nn, reg_sp.hi);

                    cycles += 20;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "LD (nn), SP\n");                                                     
                }
                break;

        /*stack push opcodes*/
        case 0xF5:
                {
                    //takes 16 cycles!
                    push(reg_af.hi);
                    push(reg_af.lo);

                    cycles += 16;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "PUSH AF\n");                                    
                }
                break;
        case 0xC5:
                {
                    //takes 16 cycles!
                    push(reg_bc.hi);
                    push(reg_bc.lo);

                    cycles += 16;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "PUSH BC\n");                 
                }
                break;
        case 0xD5:
                {
                    //takes 16 cycles!
                    push(reg_de.hi);
                    push(reg_de.lo);

                    cycles += 16;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "PUSH DE\n");                 
                }
                break;
        case 0xE5:
                {
                    //takes 16 cycles!
                    push(reg_hl.hi);
                    push(reg_hl.lo);

                    cycles += 16;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "PUSH HL\n");                 
                }
                break;

        /*stack pop opcodes*/
        case 0xF1:
                {
                    //takes 12 cycles
                    reg_af.lo = pop();
                    reg_af.hi = pop();

                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "POP AF\n");                 
                }
                break;
        case 0xC1:
                {
                    //takes 12 cycles
                    reg_bc.lo = pop();
                    reg_bc.hi = pop();

                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "POP BC\n");                 
                }
                break;
        case 0xD1:
                {
                    //takes 12 cycles
                    reg_de.lo = pop();
                    reg_de.hi = pop();

                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "POP DE\n");                 
                }
                break;
        case 0xE1:
                {
                    //takes 12 cycles
                    reg_hl.lo = pop();
                    reg_hl.hi = pop();

                    cycles += 12;

                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "POP HL\n");                 
                }
                break;

        /*8 bit ALU*/
        //8 bit add opcodes
        case 0x87: 
                {
                    add_byte(reg_af.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, A\n");                 
                }
                break;
        case 0x80: 
                {
                    add_byte(reg_bc.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, B\n");                 
                }
                break;
        case 0x81: 
                {
                    add_byte(reg_bc.lo, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, C\n");                 
                }
                break;
        case 0x82: 
                {
                    add_byte(reg_de.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, D\n");                 
                }
                break;
        case 0x83: 
                {
                    add_byte(reg_de.lo, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, E\n");                 
                }
                break;
        case 0x84: 
                {
                    add_byte(reg_hl.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, H\n");                 
                }
                break;
        case 0x85: 
                {
                    add_byte(reg_hl.lo, false);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, L\n");                 
                }
                break;
        case 0x86: 
                {
                    //takes 8 cycles
                    add_byte(bus->read(reg_hl.reg), false);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "ADD A, (HL)\n");                 
                }
                break;
        case 0xC6: 
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    add_byte(n, false);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "ADD A, {0:#x}\n", n);                 
                }
                break;

        //8 bit adc opcodes
        case 0x8F:
                {
                    add_byte(reg_af.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "ADC A, A\n");                                   
                }
                break;
        case 0x88:
                {
                    add_byte(reg_bc.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, B\n");                 
                }
                break;
        case 0x89:
                {
                    add_byte(reg_bc.lo, true);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, C\n");                 
                }
                break;
        case 0x8A:
                {
                    add_byte(reg_de.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, D\n");                 
                }
                break;
        case 0x8B:
                {
                    add_byte(reg_de.lo, true);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, E\n");                 
                }
                break;
        case 0x8C:
                {
                    add_byte(reg_hl.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, H\n");                 
                }
                break;
        case 0x8D:
                {
                    add_byte(reg_hl.lo, true);

                    fmt::print(fg(fmt::color::dark_green), "ADD A, L\n");                 
                }
                break;
        case 0x8E:
                {
                    //takes 8 cycles
                    add_byte(bus->read(reg_hl.reg), true);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "ADD A, (HL)\n");                 
                }
                break;
        case 0xCE:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    add_byte(n, true);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "ADD A, {0:#x}\n", n);                 
                }
                break;

        //8 bit sub opcodes
        case 0x97:
                {
                    sub_byte(reg_af.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB A\n");                 
                }
                break;
        case 0x90:
                {
                    sub_byte(reg_bc.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB B\n");                 
                }
                break;
        case 0x91:
                {
                    sub_byte(reg_bc.lo, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB C\n");                 
                }
                break;
        case 0x92:
                {
                    sub_byte(reg_de.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB D\n");                 
                }
                break;
        case 0x93:
                {
                    sub_byte(reg_de.lo, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB E\n");                 
                }
                break;
        case 0x94:
                {
                    sub_byte(reg_hl.hi, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB H\n");                 
                }
                break;
        case 0x95:
                {
                    sub_byte(reg_hl.lo, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB L\n");                 
                }
                break;
        case 0x96:
                {
                    //takes 8 cycles
                    sub_byte(bus->read(reg_hl.reg), false);

                    cycles += 4;
                    
                    fmt::print(fg(fmt::color::dark_green), "SUB (HL)\n");                 
                }
                break;
        case 0xD6:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    sub_byte(n, false);

                    fmt::print(fg(fmt::color::dark_green), "SUB {0:#x}\n", n);                 
                }
                break;

        
        //8 bit subc opcodes
        case 0x9F:
                {
                    sub_byte(reg_af.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC A\n");                     
                }
                break;
        case 0x98:
                {
                    sub_byte(reg_bc.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC B\n");                 
                }
                break;
        case 0x99:
                {
                    sub_byte(reg_bc.lo, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC C\n");                 
                }
                break;
        case 0x9A:
                {
                    sub_byte(reg_de.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC D\n");                 
                }
                break;
        case 0x9B:
                {
                    sub_byte(reg_de.lo, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC E\n");                 
                }
                break;
        case 0x9C:
                {
                    sub_byte(reg_hl.hi, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC H\n");                 
                }
                break;
        case 0x9D:
                {
                    sub_byte(reg_hl.lo, true);

                    fmt::print(fg(fmt::color::dark_green), "SBC L\n");                 
                }
                break;
        case 0x9E:
                {
                    //takes 8 cycles
                    sub_byte(bus->read(reg_hl.reg), true);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "SBC (HL)\n");                 
                }
                break;

        //8 bit AND opcodes
        case 0xA7:
                {
                    and_byte(reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "AND A\n");                             
                }
                break;
        case 0xA0:
                {
                    and_byte(reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "AND B\n");                             
                }
                break;
        case 0xA1:
                {
                    and_byte(reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "AND C\n");                             
                }
                break;
        case 0xA2:
                {
                    and_byte(reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "AND D\n");                             
                }
                break;
        case 0xA3:
                {
                    and_byte(reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "AND E\n");                             
                }
                break;
        case 0xA4:
                {
                    and_byte(reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "AND H\n");                             
                }
                break;
        case 0xA5:
                {
                    and_byte(reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "AND L\n");                             
                }
                break;
        case 0xA6:
                {
                    //takes 8 cycles
                    and_byte(bus->read(reg_hl.reg));

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "AND (HL)\n");                             
                }
                break;
        case 0xE6:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    and_byte(n);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "AND {0:#x}\n", n);                             
                }
                break;

        //8 bit OR opcodes
        case 0xB7:
                {
                    or_byte(reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "OR A\n");                             
                }
                break;
        case 0xB0:
                {
                    or_byte(reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "OR B\n");                             
                }
                break;
        case 0xB1:
                {
                    or_byte(reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "OR C\n");                             
                }
                break; 
        case 0xB2:
                {
                    or_byte(reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "OR D\n");                             
                }
                break; 
        case 0xB3:
                {
                    or_byte(reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "OR E\n");                             
                }
                break;
        case 0xB4:
                {
                    or_byte(reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "OR H\n");                             
                }
                break;
        case 0xB5:
                {
                    or_byte(reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "OR L\n");                             
                }
                break;
        case 0xB6:
                {
                    //takes 8 cycles
                    or_byte(bus->read(reg_hl.reg));

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "OR (HL)\n");                             
                }
                break;
        case 0xF6:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    or_byte(reg_af.hi);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "OR {0:#x}\n", n);                             
                }
                break;

        //8 bit XOR opcodes
        case 0xAF:
                {
                    xor_byte(reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "XOR A\n");   
                }
                break;
        case 0xA8:
                {
                    xor_byte(reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "XOR B\n");   
                }
                break;
        case 0xA9:
                {
                    xor_byte(reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "XOR C\n");   
                }
                break;
        case 0xAA:
                {
                    xor_byte(reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "XOR D\n");   
                }
                break;
        case 0xAB:
                {
                    xor_byte(reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "XOR E\n");   
                }
                break;
        case 0xAC:
                {
                    xor_byte(reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "XOR H\n");   
                }
                break;
        case 0xAD:
                {
                    xor_byte(reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "XOR L\n");   
                }
                break;
        case 0xAE:
                {
                    //takes 8 cycles
                    xor_byte(bus->read(reg_hl.hi));

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "XOR (HL)\n");   
                }
                break;
        case 0xEE:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    xor_byte(n);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "XOR {0:#x}\n", n);   
                }
                break;

        //8 bit compare opcodes
        case 0xBF:
                {
                    cp_byte(reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "CP A\n");   
                }
                break;
        case 0xB8:
                {
                    cp_byte(reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "CP B\n");   
                }
                break;
        case 0xB9:
                {
                    cp_byte(reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "CP C\n");   
                }
                break;
        case 0xBA:
                {
                    cp_byte(reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "CP D\n");   
                }
                break;
        case 0xBB:
                {
                    cp_byte(reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "CP E\n");   
                }
                break;
        case 0xBC:
                {
                    cp_byte(reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "CP H\n");   
                }
                break;
        case 0xBD:
                {
                    cp_byte(reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "CP L\n");   
                }
                break;
        case 0xBE:
                {
                    //takes 8 cycles
                    cp_byte(bus->read(reg_hl.reg));

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "CP (HL)\n");   
                }
                break;
        case 0xFE:
                {
                    //takes 8 cycles
                    reg_pc.reg++;
                    uint8_t n = bus->read(reg_pc.reg);
                    cp_byte(n);

                    cycles += 4;

                    fmt::print(fg(fmt::color::dark_green), "CP {0:#x}\n", n);   
                }
                break;

        //8 bit inc opcodes
        case 0x3C:
                {
                    inc_byte(&reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "INC A\n");
                }
                break;
        case 0x04:
                {
                    inc_byte(&reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "INC B\n");
                }
                break;
        case 0x0C:
                {
                    inc_byte(&reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "INC C\n");
                }
                break;
        case 0x14:
                {
                    inc_byte(&reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "INC D\n");
                }
                break;
        case 0x1C:
                {
                    inc_byte(&reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "INC E\n");
                }
                break;
        case 0x24:
                {
                    inc_byte(&reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "INC H\n");
                }
                break;
        case 0x2C:
                {
                    inc_byte(&reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "INC L\n");
                }
                break;
        case 0x34:
                {
                    //takes 12 cycles
                    uint8_t value = bus->read(reg_hl.reg);
                    inc_byte(&value);
                    bus->write(reg_hl.reg, value);

                    cycles += 8;

                    fmt::print(fg(fmt::color::dark_green), "INC (HL)\n");
                }
                break;

        //8 bit dec opcodes
        case 0x3D:
                {
                    dec_byte(&reg_af.hi);

                    fmt::print(fg(fmt::color::dark_green), "DEC A\n");     
                }
                break;
        case 0x05:
                {
                    dec_byte(&reg_bc.hi);

                    fmt::print(fg(fmt::color::dark_green), "DEC B\n");     
                }
                break;
        case 0x0D:
                {
                    dec_byte(&reg_bc.lo);

                    fmt::print(fg(fmt::color::dark_green), "DEC C\n");     
                }
                break;
        case 0x15:
                {
                    dec_byte(&reg_de.hi);

                    fmt::print(fg(fmt::color::dark_green), "DEC D\n");     
                }
                break;
        case 0x1D:
                {
                    dec_byte(&reg_de.lo);

                    fmt::print(fg(fmt::color::dark_green), "DEC E\n");     
                }
                break;
        case 0x25:
                {
                    dec_byte(&reg_hl.hi);

                    fmt::print(fg(fmt::color::dark_green), "DEC H\n");     
                }
                break;
        case 0x2D:
                {
                    dec_byte(&reg_hl.lo);

                    fmt::print(fg(fmt::color::dark_green), "DEC L\n");     
                }
                break;
        case 0x35:
                {
                    //takes 12 cycles
                    uint8_t value = bus->read(reg_hl.reg);
                    dec_byte(&value);
                    bus->write(reg_hl.reg, value);

                    cycles += 8;

                    fmt::print(fg(fmt::color::dark_green), "DEC (HL)\n");     
                }
                break;

        //16 bit ADD opcodes
        case 0x09:
                {
                    add_word(reg_bc.reg);

                    fmt::print(fg(fmt::color::dark_green), "ADD HL, BC\n");     
                }
                break;
        case 0x19:
                {
                    add_word(reg_de.reg);

                    fmt::print(fg(fmt::color::dark_green), "ADD HL, DE\n");     
                }
                break;
        case 0x29:
                {
                    add_word(reg_hl.reg);

                    fmt::print(fg(fmt::color::dark_green), "ADD HL, HL\n");     
                }
                break;
        case 0x39:
                {
                    add_word(reg_sp.reg);

                    fmt::print(fg(fmt::color::dark_green), "ADD HL, SP\n");     
                }
                break;

        case 0xE8:
                {
                    //takes 16 cycles
                    immediate();
                    uint16_t n = bus->read(reg_pc.reg);

                    reg_sp.reg = reg_sp.reg + n;

                    flag_zero = false;
                    flag_n = false;

                    if((reg_sp.reg & 0xF) + (n & 0xF) > 0xF)
                        flag_half_carry = true;
                    else 
                        flag_half_carry = false;

                    if((reg_sp.reg & 0xFF) + (n & 0xFF) > 0xFF)
                        flag_carry = true;
                    else 
                        flag_carry = false;

                    cycles += 16;

                    fmt::print(fg(fmt::color::dark_green), "ADD SP, {0:#x}\n", n);     
                }
                break;

        //16 bit increment opcodes
        case 0x03:
                {
                    inc_word(&reg_bc.reg);

                    fmt::print(fg(fmt::color::dark_green), "INC BC\n");     
                }
                break;
        case 0x13:
                {
                    inc_word(&reg_de.reg);

                    fmt::print(fg(fmt::color::dark_green), "INC DE\n");     
                }
                break;
        case 0x23:
                {
                    inc_word(&reg_hl.reg);

                    fmt::print(fg(fmt::color::dark_green), "INC HL\n");     
                }
                break;
        case 0x33:
                {
                    inc_word(&reg_sp.reg);

                    fmt::print(fg(fmt::color::dark_green), "INC SP\n");     
                }
                break;

        //16 bit decrement opcodes
        case 0x0B:
                {
                    dec_word(&reg_bc.reg);

                    fmt::print(fg(fmt::color::dark_green), "DEC BC\n");     
                }
                break;
        case 0x1B:
                {
                    dec_word(&reg_de.reg);

                    fmt::print(fg(fmt::color::dark_green), "DEC DE\n");     
                }
                break;
        case 0x2B:
                {
                    dec_word(&reg_hl.reg);

                    fmt::print(fg(fmt::color::dark_green), "DEC HL\n");     
                }
                break;
        case 0x3B:
                {
                    dec_word(&reg_sp.reg);

                    fmt::print(fg(fmt::color::dark_green), "DEC SP\n");     
                }
                break;


        //DAA opcode
        case 0x27:
                {
                    daa();

                    fmt::print(fg(fmt::color::dark_green), "DAA\n");     
                }
                break;

        //CPL (complement A register)
        case 0x2F:
                {
                    reg_af.hi = ~reg_af.hi;

                    flag_n = true;
                    flag_half_carry = true;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "CPL\n");      
                }
                break;
        //CCF (complement carry flag)
        case 0x3F:  
                {
                    flag_n = false;
                    flag_half_carry = false;
                    flag_carry = !flag_carry;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "CCF\n");      
                }   
                break;
        //SCF (set carry flag)
        case 0x37: 
                {
                    flag_n = false;
                    flag_half_carry = false;
                    flag_carry = true;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "SCF\n");      
                }   
                break;
        //NOP
        case 0x00:
                {
                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "NOP\n");      
                }
                break;
        //HALT
        case 0x76:
                {
                    //TODO
                    halt = true;

                    cycles += 4;
                    reg_pc.reg++;
                
                    fmt::print(fg(fmt::color::dark_green), "HALT\n");      
                }
                break;
        //STOP
        case 0x10:
                {
                    //TODO

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "STOP\n");      
                }
                break;
        //DI (disable interrupts after DI is executed)
        case 0xF3:
                {
                    flag_IME = false;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "DI\n");       
                }
                break;
        //EI (enable interrupts after EI is executed)
        case 0xFB:
                {
                    flag_IME = true;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "EI\n");
                }
                break;

        //Rotates and shifts
        //RLCA (rotate A left)
        case 0x07:
                {
                    flag_carry = reg_af.hi & 80; // 0x80 -> 1000'0000
                    reg_af.hi = reg_af.hi << 1;

                    if(reg_af.hi == 0)
                        flag_zero = true;
                    else 
                        flag_zero = false;

                    flag_n = false;
                    flag_half_carry = false;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "RLCA\n");
                }
                break;
        //RLA (rotate A left through carry flag)
        case 0x17:
                {
                    bool msb = reg_af.hi & 0x80; // 0x80 -> 1000'0000
                    reg_af.hi = (reg_af.hi << 1) + flag_carry;

                    flag_carry = msb;

                    if(reg_af.hi == 0)
                        flag_zero = true;
                    else 
                        flag_zero = false;

                    flag_n = false;
                    flag_half_carry = false;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "RLA\n");
                }
                break;
        //RRCA (rotate A right)
        case 0x0F:
                {
                    bool lsb = reg_af.hi & 0x1;
                    reg_af.hi = reg_af.hi >> 1;

                    flag_carry = lsb;

                    if(reg_af.hi == 0)
                        flag_zero = true;
                    else 
                        flag_zero = false;

                    flag_n = false;
                    flag_half_carry = false;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "RRCA\n");
                }
                break;
        //RRA (rotate A right through carry flag)
        case 0x1F:
                {
                    bool lsb = reg_af.hi & 0x1;
                    reg_af.hi = (reg_af.hi >> 1) + flag_carry;

                    flag_carry = lsb;

                    if(reg_af.hi == 0)
                        flag_zero = true;
                    else 
                        flag_zero = false;

                    flag_n = false;
                    flag_half_carry = false;

                    cycles += 4;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "RRA\n");  
                }  
                break;

        //jump opcodes
        //JP nn
        case 0xC3:
                {
                    reg_pc.reg++;
                    uint16_t lo = bus->read(reg_pc.reg);
                    reg_pc.reg++;
                    uint16_t hi = bus->read(reg_pc.reg);

                    uint16_t addr = (hi << 8) | lo;

                    jump(addr);

                    fmt::print(fg(fmt::color::dark_green), "JP {0:#x}\n", addr);   
                }
                break;
        //JP cc, nn opcodes
        case 0xC2:
                {
                    uint16_t addr {};
                    if(!flag_zero)
                    {
                        reg_pc.reg++;
                        uint16_t lo = bus->read(reg_pc.reg);
                        reg_pc.reg++;
                        uint16_t hi = bus->read(reg_pc.reg);

                        uint16_t addr = (hi << 8) | lo;

                        jump(addr);

                        fmt::print(fg(fmt::color::dark_green), "JP NZ, {0:#x}; true\n", addr);   
                    }
                    else 
                    {
                        reg_pc.reg++;
                        fmt::print(fg(fmt::color::dark_green), "JP NZ, {0:#x}; false\n", addr);   
                    }
                }
                break;
        case 0xCA:
                {
                    uint16_t addr {};
                    if(flag_zero)
                    {
                        reg_pc.reg++;
                        uint16_t lo = bus->read(reg_pc.reg);
                        reg_pc.reg++;
                        uint16_t hi = bus->read(reg_pc.reg);

                        addr = (hi << 8) | lo;

                        jump(addr);

                        fmt::print(fg(fmt::color::dark_green), "JP Z, {0:#x}; true\n", addr);   
                    }
                    else 
                    {
                        reg_pc.reg++;
                        fmt::print(fg(fmt::color::dark_green), "JP Z, {0:#x}; false\n", addr);   
                    }
                }
                break;
        case 0xD2:
                {
                    uint16_t addr {};
                    if(!flag_carry)
                    {
                        reg_pc.reg++;
                        uint16_t lo = bus->read(reg_pc.reg);
                        reg_pc.reg++;
                        uint16_t hi = bus->read(reg_pc.reg);

                        uint16_t addr = (hi << 8) | lo;

                        jump(addr);

                        fmt::print(fg(fmt::color::dark_green), "JP NC, {0:#x}; true\n", addr);   
                    }
                    else 
                    {
                        reg_pc.reg++;
                        fmt::print(fg(fmt::color::dark_green), "JP NC, {0:#x}; false\n", addr);   
                    }
                }
                break;
        case 0xDA:
                {
                    uint16_t addr {};
                    if(flag_carry)
                    {
                        reg_pc.reg++;
                        uint16_t lo = bus->read(reg_pc.reg);
                        reg_pc.reg++;
                        uint16_t hi = bus->read(reg_pc.reg);

                        uint16_t addr = (hi << 8) | lo;

                        jump(addr);

                        fmt::print(fg(fmt::color::dark_green), "JP C, {0:#x}; true\n", addr);   
                    }
                    else 
                    {
                        reg_pc.reg++;
                        fmt::print(fg(fmt::color::dark_green), "JP C, {0:#x}; false\n", addr);   
                    }
                }
                break;
        case 0xE9:
                {
                    //takes only 4 cycles!
                    jump(reg_hl.reg);

                    cycles -= 8;
                    reg_pc.reg++;

                    fmt::print(fg(fmt::color::dark_green), "JP (HL)\n");   
                }
                break;
        


        default:
            {
                fmt::print(fg(fmt::color::crimson), "Opcode {0:#x} not implemented!\n", opcode);
                reg_pc.reg++;
            }
    }
}

/*stack functions*/
void CPU::setSP(uint16_t address)
{
    reg_sp.reg = address;
}

uint16_t CPU::getSP()
{
    return reg_sp.reg;
}

void CPU::push(uint8_t value)
{
    bus->write(reg_sp.reg, value);
    reg_sp.reg -= 1;
}

uint8_t CPU::pop()
{
    reg_sp.reg += 1;
    return bus->read(reg_sp.reg);
}

/*stack functions*/

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
void CPU::ld_a(uint16_t value)
{
    reg_af.hi = bus->read(value);
    cycles += 8;
    reg_pc.reg++;
}

//LD n,A
void CPU::ld_n(uint8_t *reg)
{
    *reg = reg_af.hi;
    cycles += 4;
    reg_pc.reg++;
}

//LD (r1), r2
void CPU::ld_mem_r(uint16_t *r1, uint8_t r2)
{
    //temp
    bus->write(*r1, r2);
    cycles += 4;
    reg_pc.reg++;
}


//LD n, nn
void CPU::ld_nn(uint16_t *reg, uint16_t value)
{
    *reg = value;
    reg_pc.reg++;
}

//ADD A, reg
void CPU::add_byte(uint8_t reg, bool carry)
{

    if(reg_af.hi == 0x00)
        flag_zero = true;
    
    flag_n = false;

    if(!carry)
    {
        if((reg_af.hi & 0xF) + (reg & 0xF) > 0xF)
            flag_half_carry = true;
        else 
            flag_half_carry = false;

        if((reg_af.hi & 0xFF) + (reg & 0xFF) > 0xFF)
            flag_carry = true;
        else 
            flag_carry = false;

        reg_af.hi = reg_af.hi + reg;
    }
    else 
    {
        if((reg_af.hi & 0xF) + (reg & 0xF) + (flag_carry & 0xF)> 0xF)
            flag_half_carry = true;
        else 
            flag_half_carry = false;

        if((reg_af.hi & 0xFF) + (reg & 0xFF) + (flag_carry & 0xFF) > 0xFF)
            flag_carry = true; 
        else 
            flag_carry = false; 

        reg_af.hi = reg_af.hi + reg + flag_carry;
    }


    cycles += 4;
    reg_pc.reg++;
}

//SUB reg
void CPU::sub_byte(uint8_t reg, bool carry)
{
    uint8_t carry_val = 0;
    if(carry)
    {
        carry_val = (flag_carry) ? 1 : 0;
        reg = reg + carry;// A = A - (reg+carry)
    }


    if(reg_af.hi == 0)
        flag_zero = true;
    else 
        flag_zero = false;
    
    flag_n = true;

    if((reg & 0xF) > (reg_af.hi & 0xF))
        flag_half_carry = true;
    else 
        flag_half_carry = false;

    if(reg > reg_af.hi)
        flag_carry = true;
    else 
        flag_carry = false;

    reg_af.hi = reg_af.hi - reg;

    cycles += 4;
    reg_pc.reg++;
}

//AND reg
void CPU::and_byte(uint8_t reg)
{
    reg_af.hi = reg_af.hi & reg;

    if(reg_af.hi == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_n = false;

    flag_half_carry = true;

    flag_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//OR reg
void CPU::or_byte(uint8_t reg)
{
    reg_af.hi = reg_af.hi | reg;

    if(reg_af.hi == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_n = false;

    flag_half_carry = false;

    flag_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//XOR reg
void CPU::xor_byte(uint8_t reg)
{
    reg_af.hi = reg_af.hi ^ reg;

    if(reg_af.hi == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_n = false;

    flag_half_carry = false;

    flag_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//CP n
void CPU::cp_byte(uint8_t reg)
{
    uint8_t temp = reg_af.hi - reg;

    if(temp == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_n  = true;

    if((reg & 0xF) > (reg_af.hi & 0xF))
        flag_half_carry = true;
    else 
        flag_half_carry = false;

    if(reg > reg_af.hi)
        flag_carry = true;
    else 
        flag_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//INC n
void CPU::inc_byte(uint8_t *reg)
{
    *reg++;

    if(*reg == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_n = false;

    //                                        ----
    if((*reg & 0xF) == 0) // 1111 + 1 -> 0001 0000, we check if its zero
        flag_half_carry = true;
    else 
        flag_half_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//DEC n
void CPU::dec_byte(uint8_t *reg)
{
    *reg--;

    if(*reg == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_n = true;
    
    if((*reg & 0xF) == 0xF) // 1111 -> no borrow
        flag_half_carry = true;
    else 
        flag_half_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//ADD HL, reg
void CPU::add_word(uint16_t value)
{

    flag_n = false;

    //0111'1111'1111 -> 0 -> 11th bit
    if((reg_hl.reg & 0x0FFF) + (value & 0x0FFF) > 0x0FFF)
        flag_half_carry = true;
    else 
        flag_half_carry = false;

    if(reg_hl.reg + value > 0xFFFF)
        flag_carry = true;
    else 
        flag_carry = false;

    reg_hl.reg = reg_hl.reg + value;

    cycles += 8;
    reg_pc.reg++;
}

//INC nn
void CPU::inc_word(uint16_t *reg)
{
    *reg++;

    cycles += 8;
    reg_pc.reg++;
}

//DEC nn
void CPU::dec_word(uint16_t *reg)
{
    *reg--;

    cycles += 8;
    reg_pc.reg++;
}

//DAA
//https://forums.nesdev.com/viewtopic.php?t=15944
void CPU::daa()
{
    //after an addition, adjust if half carry occurred or if result is out of bounds
    if(!flag_n)
    {
        if(flag_carry || reg_af.hi > 0x99)
        {
            reg_af.hi = reg_af.hi + 0x60;
            flag_carry = true;
        }
        if(flag_half_carry || (reg_af.hi & 0xF) > 0x9)
            reg_af.hi = reg_af.hi + 0x6;
    }
    //after subtraction, only adjust if half carry occurred
    else 
    {
        if(flag_carry)
        {
            reg_af.hi = reg_af.hi - 0x60;
        }
        if(flag_half_carry)
        {
            reg_af.hi = reg_af.hi - 0x6;
        }
    }

    if(reg_af.hi == 0)
        flag_zero = true;
    else 
        flag_zero = false;

    flag_half_carry = false;

    cycles += 4;
    reg_pc.reg++;
}

//JP nn; JP cc, nn
void CPU::jump(uint16_t address)
{
    reg_pc.reg = address;

    cycles += 12;
    reg_pc.reg++;
}

/*instructions*/

/*interrupt*/
void CPU::interrupt_handler()
{

}
/*interrupt*/