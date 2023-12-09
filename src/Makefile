main: main.o Menu.o Tetrafrog.o
	g++ -o a.out main.o Menu.o Tetrafrog.o -lncurses

main.o: main.cpp Menu.hpp
	g++ -c main.cpp -lncurses

Menu.o: Menu.cpp Menu.hpp Tetrafrog.hpp
	g++ -c Menu.cpp -lncurses

Tetrafrog.o: Tetrafrog.cpp Tetrafrog.hpp
	g++ -c Tetrafrog.cpp -lncurses

# Richiamarlo con "make clean"
clean:
	rm *.o a.out

