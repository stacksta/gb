#include "mmu.h"

MMU::MMU()
{
    cartridge.resize(0xFFFF);
}

uint8_t MMU::read(uint16_t address)
{
    return cartridge[address];
}

void MMU::write(uint16_t address, uint8_t value)
{
    cartridge[address] = value;
}


void MMU::loadROM(std::string path)
{
    std::ifstream rom(path, std::ios::in | std::ios::binary);

    if(rom.is_open())
    {
        rom.read(reinterpret_cast<char*>(&cartridge[0]), 0xFFFF);

        //CE ED 66 66 CC 0D -> logo
        if(cartridge[0x104] == 0xCE && cartridge[0x105] == 0xED && cartridge[0x106] == 0x66 && cartridge[0x106] == 0x66)
        {
            fmt::print("Valid GB cartridge!\n");
        }
        else 
            fmt::print("Invalid GB cartridge!\n");

        //0x134-0x143 -> title
        fmt::print("ROM Name: ");
        for(auto i=0x134;i<=0x143;i++)
        {
            fmt::print("{:c}", cartridge[i]);
        }
        fmt::print("\n");

        //0x147 -> cartridge type
        fmt::print("Cartridge Type: ");
        switch(cartridge[0x147])
        {
            case 0x00:  fmt::print("{0:#x} ROM only\n", cartridge[0x147]); break;
            case 0x01:  fmt::print("{0:#x} MBC1\n", cartridge[0x147]); break;
            case 0x02:  fmt::print("{0:#x} MBC1+RAM\n", cartridge[0x147]); break;
            default: fmt::print("{0:#x} Not supported currently!\n", cartridge[0x147]);
        }

        //0x148 -> ROM size
        fmt::print("ROM size: ");
        switch(cartridge[0x148])
        {
            case 0x00: fmt::print("32kB, 2 Banks\n"); break;
            case 0x01: fmt::print("64kB, 4 Banks\n"); break;
            case 0x02: fmt::print("128kB, 8 Banks\n"); break;
            default: fmt::print("{0:#x} Not supported currently!\n", cartridge[0x148]);
        }

        //0x149 -> RAM size
        fmt::print("RAM size: ");
        switch(cartridge[0x149])
        {
            case 0x00: fmt::print("None\n"); break;
            case 0x01: fmt::print("2kB\n"); break;
            case 0x02: fmt::print("8kB\n"); break;
            case 0x03: fmt::print("32kB (4 Banks of 8kB each)\n"); break;
            case 0x04: fmt::print("128kB (16 Banks of 8kB each)\n"); break;
            case 0x05: fmt::print("64kB (8 Banks of 8kB each)\n"); break;
            default: fmt::print("{0:#x} Invalid RAM size code!\n", cartridge[0x149]);
        }

        //0x14A -> Destination code (region)
        fmt::print("Region: ");
        if(cartridge[0x14A])
            fmt::print("Non-Japanese\n");
        else 
            fmt::print("Japanese\n");
    }
}