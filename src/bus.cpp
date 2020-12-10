#include "bus.h"

Bus::Bus()
{

}

uint8_t Bus::read(uint16_t address)
{
    return mem.read(address);
}

void Bus::write(uint16_t address, uint8_t value)
{
    mem.write(address, value);
}

void Bus::loadROM(std::string path)
{
    mem.loadROM(path);
}