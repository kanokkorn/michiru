CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Os -s -pedantic
LIBS = -lm
PROJECT = michiru

$(PROJECT): main.c
	$(CC) $(CFLAGS) $(LIBS) $< -o $@
clean:
	rm $(PROJECT)

.SILENT: clean
