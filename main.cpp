#include <iostream>
#include "mmu.h"
#include "bus.h"
#include "cpu.h"

int main(int argc, char *argv[])
{
    MMU mem;
    Bus bus(&mem);
    CPU cpu(&bus);

    return 0;
}