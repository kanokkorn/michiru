cc = cc
cflags = -std=c99 -Wall -Wextra -Wconversion\
         -Wshadow -O3 -s -pedantic
libs = -lm
project = example

$(project): example.c
	$(cc) $(cflags) $< -o $@ $(libs)
clean:
	$(RM) $(project)

.SILENT: clean
