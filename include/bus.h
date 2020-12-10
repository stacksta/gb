#ifndef BUS_H
#define BUS_H

#include "mmu.h"

class Bus
{
    public:
        Bus(MMU *m);
        ~Bus() {}

    private:
        MMU *mem = nullptr;
};



#endif