# The following rule means: "if ltest does not exist, or
# is older than ltest.o or list.o,
# then link ltest".

# Targets
PROGS =  htmltest primeTest

all: $(PROGS)


htmltest: tagremover.o htmltest.o
	g++ -o htmltest htmltest.o tagremover.o

primeTest: primeTest.o prime.o
	g++ -o primetest primetest.o prime.o

dateTest: date_test.o date.o 
	g++ -o dateTest date_test.o date.o

date: date.o
	g++ -o date date.o

toString: toString.o date.o
	g++ -o toString toString.o date.o

# Rules to create the object files.
tagremover.o: TagRemover.cc TagRemover.h
	g++ -c TagRemover.cc -std=c++11

htmltest.o: htmlTest.cc TagRemover.h
	g++ -c htmlTest.cc -std=c++11

prime.o: prime.cc prime.h
	g++ -c prime.cc -std=c++11

primeTest.o: primeTest.cc prime.h
	g++ -c primeTest.cc -std=c++11

date_test.o: date_test.cc date.h
	g++ -c date_test.cc -std=c++11

date.o: date.cc date.h
	g++ -c date.cc -std=c++11

toString.o: toString.cc
	g++ -c toString.cc -std=c++11


clean:
	rm *.o htmltest primeTest
	rm *.exe htmltest