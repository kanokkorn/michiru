cc = cc
cflags = -std=c99 -Wall -Wextra -Ofast -pthread
libs = -lm

michiru: main.c michiru.h
	$(cc) main.c $(cflags) $(libs) -o michiru
clean:
	rm michiru
