CC=gcc
CFLAGS =-c -Wall
CPPFLAGS = -MMD
EXECUTABLE = chessviz
SRCDIR=src/
SOURCES=$(SRCDIR)main.c $(SRCDIR)Chess_Game.c $(SRCDIR)Board.c $(SRCDIR)Error_Message.c $(SRCDIR)IO.c $(SRCDIR)Moving.c $(SRCDIR)Rules.c
OBJECTS=$(SOURCES: .c = .o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o: 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm –rf *.o *.exe
