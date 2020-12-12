#ifndef MMU_H
#define MMU_H

#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include <fmt/core.h>


class MMU
{
    public:
        MMU();
        ~MMU() {}

        uint8_t read(uint16_t address);
        void write(uint16_t address, uint8_t value);

        void loadROM(std::string path);

        enum MBC
        {
            none = 0,
            mbc1 = 1,
            mbc1_ram = 2,
            mbc1_ram_battery = 3
        };
        
        MBC type;
    private:
        std::vector<uint8_t> RAM;
        std::vector<uint8_t> VRAM;

        std::vector<uint8_t> cartridge;

        bool mode_flag {};
};
#endif 