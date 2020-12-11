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

    private:
        std::vector<uint8_t> RAM;
        std::vector<uint8_t> VRAM;

        std::vector<uint8_t> cartridge;
};
#endif 