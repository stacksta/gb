#include <fmt/core.h>
#include <iostream>
#include "mmu.h"
#include "bus.h"
#include "cpu.h"

int main(int argc, char *argv[])
{
    MMU mem;
    Bus bus;
    CPU cpu(&bus);


    char step {};

    uint8_t opcode{};
    do {
        //fetch
        opcode = bus.read(cpu.getPC());
        cpu.execute(opcode);

        std::cin>>step;

    }while(step!='e');

    return 0;
}