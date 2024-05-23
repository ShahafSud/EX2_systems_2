#209374487
CXX = clang++
FLG = -Wall -g

all: demo.exe test.exe Demo2.exe

test.exe: Test.o TestCounter.o
	$(CXX) $(FLG) -o test.exe Test.o TestCounter.o Graph.o Algorithms.o



demo.exe: demo.o Graph.o Algorithms.o
	$(CXX) $(FLG) -o demo.exe demo.o Graph.o Algorithms.o

Demo2.exe: Demo2.o Graph.o Algorithms.o
	$(CXX) $(FLG) -o Demo2.exe Demo2.o Graph.o Algorithms.o


demo.o: demo.cpp
	$(CXX) $(FLG) -c demo.cpp -o demo.o

Demo2.o: Demo2.cpp
	$(CXX) $(FLG) -c Demo2.cpp -o Demo2.o


Test.o: Test.cpp doctest.h Graph.hpp Algorithms.hpp
	$(CXX) $(FLG) -c Test.cpp -o Test.o

TestCounter.o: TestCounter.cpp doctest.h
	$(CXX) $(FLG) -c TestCounter.cpp -o TestCounter.o



Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(FLG) -c Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(FLG) -c Algorithms.cpp -o Algorithms.o


.PHONY: clean all

clean:
	rm -f *.o demo.exe test.exe
