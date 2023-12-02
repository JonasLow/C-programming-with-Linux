CC = gcc

CCFLAGS = std=c11 -Wall -fmax-errors=10 -Wextra

LFLAGS = -L.

LIBS = -lweather

OBJFILES = program.o

MAIN = program

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) $(LFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

launch: program
	./program

clean:
	rm -f $(OBJFILES) $(MAIN)