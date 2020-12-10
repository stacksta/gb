#ifndef MMU_H
#define MMU_H

#include <cstdint>
#include <vector>


class MMU
{
    public:
        MMU();
        ~MMU() {}

        uint8_t read(uint16_t address);
        void write(uint16_t address, uint8_t value);

    private:
        std::vector<uint8_t> RAM;
        std::vector<uint8_t> VRAM;

        std::vector<uint8_t> prg;
};
#endif 