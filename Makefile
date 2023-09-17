CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: OneginRes.exe

OneginRes.exe: ReadData.o PrintRes.o Sort.o Free.o
	$(CC) ReadData.o PrintRes.o Sort.o Free.o -o OneginRes.exe

ReadData.o: ReadData.cpp ReadData.h
	$(CC) $(CFLAGS) ReadData.cpp

PrintRes.o: PrintRes.cpp PrintRes.h ReadData.h Sort.h
	$(CC) $(CFLAGS) PrintRes.cpp

Sort.o: Sort.cpp Sort.h
	$(CC) $(CFLAGS) Sort.cpp

Free.o: Free.cpp Free.h
	$(CC) $(CFLAGS) Free.cpp 

.PHONY: all clean 

 	

