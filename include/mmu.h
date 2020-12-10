#ifndef MMU_H
#define MMU_H

#include <cstdint>
#include <vector>


class MMU
{
    public:
        MMU();
        ~MMU() {}

    private:
        std::vector<uint8_t> RAM;
        std::vector<uint8_t> VRAM;
};
#endif 