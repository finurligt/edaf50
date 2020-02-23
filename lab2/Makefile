# The following rule means: "if ltest does not exist, or
# is older than ltest.o or list.o,
# then link ltest".
spell: dictionary.o word.o spell.o
	g++ -o spell dictionary.o word.o spell.o

# Rules to create the object files.
dictionary.o: dictionary.cc dictionary.h word.h
	g++ -c dictionary.cc -std=c++11
word.o: word.cc word.h
	g++ -c word.cc -std=c++11
spell.o: spell.cc dictionary.h
	g++ -c spell.cc -std=c++11


words: makeWords.o
	g++ -o words makeWords.o

makeWords.o: makeWords.cc 
	g++ -c makeWords.cc -std=c++11

clean:
	rm *.o spell