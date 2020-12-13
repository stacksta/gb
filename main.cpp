#include <fmt/core.h>
#include <iostream>
#include "bus.h"
#include "cpu.h"

int main(int argc, char *argv[])
{
    Bus bus;
    bus.loadROM("roms/cpu_instrs.gb");

    CPU cpu(&bus);

    char step {};

    uint8_t opcode{};

    cpu.setPC(0x100);
    cpu.setSP(0xFFFE);
    
    do {
        //fetch
        opcode = bus.read(cpu.getPC());

        fmt::print("{0:#x}: ", opcode);

        cpu.execute(opcode);

        std::cin>>step;

    }while(step!='e');

    return 0;
}