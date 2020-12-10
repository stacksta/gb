#include "mmu.h"

MMU::MMU()
{
    prg.resize(0xFFFF);
}

uint8_t MMU::read(uint16_t address)
{
    return prg[address];
}

void MMU::write(uint16_t address, uint8_t value)
{
    prg[address] = value;
}