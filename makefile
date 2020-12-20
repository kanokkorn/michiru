cc = gcc
cflags = --std=c17 -Wall -Wextra -Ofast
libs = -lm

michiru: main.c
	$(cc) main.c $(cflags) $(libs) -o michiru
clean:
	rm main.o michiru
