CC = g++

all: music

music: note.hh sequence.cc
	$(CC) -o music note.hh sequence.cc

clean:
	rm music