INCDIR = include/
LDFLAGS = -lfmt

all:
	g++ -I ${INCDIR} ./src/mmu.cpp ./src/bus.cpp ./src/cpu.cpp main.cpp -o bin/gb.exe ${LDFLAGS}

clean:
	rm bin/gb.exe

run:
	bin/gb.exe