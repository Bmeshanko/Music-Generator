CC = g++

all: music learntheneck

music: note.hh sequence.cc
	$(CC) -o music note.hh sequence.cc

learntheneck: learntheneck.cc
	$(CC) -o ltn learntheneck.cc

clean:
	rm music