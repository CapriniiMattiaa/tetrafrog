main: main.o Menu.o Tetrafrog.o Leaderboard.o tools.o Map.o
	g++ -o a.out main.o Menu.o Tetrafrog.o Map.o Leaderboard.o tools.o -lncurses

Map.o: Map.cpp Map.hpp
	g++ -c Map.cpp -lncurses

main.o: main.cpp Menu.hpp
	g++ -c main.cpp -lncurses

Menu.o: Menu.cpp Menu.hpp Tetrafrog.hpp Leaderboard.hpp
	g++ -c Menu.cpp -lncurses

Tetrafrog.o: Tetrafrog.cpp Tetrafrog.hpp
	g++ -c Tetrafrog.cpp -lncurses

Leaderboard.o: Leaderboard.cpp Leaderboard.hpp tools.h
	g++ -c Leaderboard.cpp -lncurses

# Richiamarlo con "make clean"
clean:
	rm *.o a.out

