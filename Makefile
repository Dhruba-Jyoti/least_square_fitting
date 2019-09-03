CC = g++
CXX = g++
CXXFLAGS = -Wall -O3
LIBS = -lm

.PHONY: clean run

all: program

program: main.o solver.o progress.o sleep.o
	$(CXX) -o run main.o solver.o progress.o sleep.o $(LIBS)

%.o: %.cpp
	$(CXX) -c $<

run:
	./run

clean:
	rm -f *.o run
