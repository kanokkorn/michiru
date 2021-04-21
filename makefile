CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Wconversion -Os -s -pedantic
LIBS = -lm
PROJECT = michiru

$(PROJECT): main.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
clean:
	rm $(PROJECT)

.SILENT: clean
