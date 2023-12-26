main: main.o tools.o Menu.o Tetrafrog.o Leaderboard.o Map.o
	g++ -o a.out main.o Menu.o Tetrafrog.o Map.o Leaderboard.o tools.o -lncurses

main.o: main.cpp Menu.hpp
	g++ -c main.cpp -lncurses

Map.o: Map.cpp Map.hpp tools.h
	g++ -c Map.cpp -lncurses

Menu.o: Menu.cpp Menu.hpp Tetrafrog.hpp Leaderboard.hpp
	g++ -c Menu.cpp -lncurses

Tetrafrog.o: Tetrafrog.cpp Tetrafrog.hpp
	g++ -c Tetrafrog.cpp -lncurses

Leaderboard.o: Leaderboard.cpp Leaderboard.hpp tools.h
	g++ -c Leaderboard.cpp -lncurses

tools.o: tools.cpp tools.h
	g++ -c tools.cpp

# Richiamarlo con "make clean"
clean:
	rm *.o a.out

