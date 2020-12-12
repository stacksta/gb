#include "mmu.h"

MMU::MMU()
{
    cartridge.resize(0xFFFF);
}

void MMU::init()
{
    if(type == MBC::none) 
        return;
    if(type == MBC::mbc1)
    {
        if(cartridge.size() < 0x100000)// <1MB 32 Banks
            zero_bank = 0;
        if(cartridge.size() == 0x100000)// == 1MB 64 Banks
        {

        }
    }
}

uint8_t MMU::read(uint16_t address)
{
    if(type == MBC::none)
        return cartridge[address];

    //MBC1
    if(type == MBC::mbc1)
    {
        if(address >= 0x0000 && address < 0x4000)
        {
            if(!mode_flag) //if mode flag is 0
                return cartridge[address];
            else 
            {
                //TODO
                //get zero bank number and return value
                //0x4000 * zero bank number + addr

                return 1;//temp
            }
        }

        if(address >= 0x4000 && address < 0x8000)
        {
            //TODO
            //0x4000 * high bank number + (addr - 0x4000)

            return 1;//temp
        }

        if(address >= 0xA000 && address < 0xC000)
        {
            //TODO

            return 1;//temp
        }
    }
}

void MMU::write(uint16_t address, uint8_t value)
{
    if(type == MBC::none)
        cartridge[address] = value;

    //MBC1
    if(type == MBC::mbc1)
    {
        if(address >= 0x0000 && address < 0x2000)
        {
            if(value & 0xF == 0xA) 
            {
                //enable ram
            }
        }
        if(address >= 0x2000 && address < 0x4000)
        {
            //set rom bank number
        }
        if(address >= 0x4000 && address < 0x6000)
        {

        }
        if(address >= 0x6000 && address < 0x8000)
        {
            //set mode flag to the lsb of value
            mode_flag = value & 0x1;
        }
        if(address >= 0xA000 && address < 0xC000)
        {
            //write to external ram if enabled
        }
    }
}


void MMU::loadROM(std::string path)
{
    std::ifstream rom(path, std::ios::in | std::ios::binary);

    if(rom.is_open())
    {
        rom.read(reinterpret_cast<char*>(&cartridge[0]), 0xFFFF);

        //CE ED 66 66 CC 0D -> logo
        if(cartridge[0x104] == 0xCE && cartridge[0x105] == 0xED && cartridge[0x106] == 0x66 && cartridge[0x107] == 0x66)
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
            case 0x00:  fmt::print("{0:#x} ROM only\n", cartridge[0x147]); type = MBC::none; break;
            case 0x01:  fmt::print("{0:#x} MBC1\n", cartridge[0x147]); type = MBC::mbc1; break;
            case 0x02:  fmt::print("{0:#x} MBC1+RAM\n", cartridge[0x147]); type = MBC::mbc1_ram; break;
            case 0x03:  fmt::print("{0:#x} MBC1+RAM+BATTERY\n", cartridge[0x147]); type = MBC::mbc1_ram_battery; break;
            default: fmt::print("{0:#x} Not supported currently!\n", cartridge[0x147]);
        }

        //0x148 -> ROM size
        fmt::print("ROM size: ");
        switch(cartridge[0x148])
        {
            case 0x00: fmt::print("32kB, 2 Banks\n"); rom_size = 0x8000; break;
            case 0x01: fmt::print("64kB, 4 Banks\n"); rom_size = 0xFFFF; break;
            case 0x02: fmt::print("128kB, 8 Banks\n"); rom_size = 0x20000; break;
            case 0x03: fmt::print("256kB, 16 Banks\n"); rom_size = 0x40000; break;
            default: fmt::print("{0:#x} Not supported currently!\n", cartridge[0x148]);
        }

        //0x149 -> RAM size
        fmt::print("RAM size: ");
        switch(cartridge[0x149])
        {
            case 0x00: fmt::print("None\n"); break;
            case 0x01: fmt::print("2kB\n"); ram_size = 0x800; break;
            case 0x02: fmt::print("8kB\n"); ram_size = 0x2000; break;
            case 0x03: fmt::print("32kB (4 Banks of 8kB each)\n"); ram_size = 0x8000; break;
            case 0x04: fmt::print("128kB (16 Banks of 8kB each)\n"); ram_size = 0x20000; break;
            case 0x05: fmt::print("64kB (8 Banks of 8kB each)\n"); ram_size = 0xFFFF; break;
            default: fmt::print("{0:#x} Invalid RAM size code!\n", cartridge[0x149]);
        }

        ROM.resize(rom_size);
        RAM.resize(ram_size);

        //0x14A -> Destination code (region)
        fmt::print("Region: ");
        if(cartridge[0x14A])
            fmt::print("Non-Japanese\n");
        else 
            fmt::print("Japanese\n");
    }
}