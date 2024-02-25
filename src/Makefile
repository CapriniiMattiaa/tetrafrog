main: main.o Menu.o Tetrimino.o Tetrafrog.o Score.o NextTetriminoViewer.o Leaderboard.o Map.o  I.o O.o J.o L.o S.o Z.o T.o tools.o
	g++ -o a.out main.o Menu.o Score.o NextTetriminoViewer.o Tetrafrog.o Map.o Leaderboard.o I.o O.o J.o L.o S.o Z.o T.o tools.o -lncurses

main.o: main.cpp Menu.hpp
	g++ -c main.cpp -lncurses

Score.o: Score.cpp Score.hpp
	g++ -c Score.cpp -lncurses

NextTetriminoViewer.o: NextTetriminoViewer.cpp NextTetriminoViewer.hpp
	g++ -c NextTetriminoViewer.cpp -lncurses

Map.o: Map.cpp Map.hpp tools.h
	g++ -c Map.cpp -lncurses

Menu.o: Menu.cpp Menu.hpp Tetrafrog.hpp Leaderboard.hpp
	g++ -c Menu.cpp -lncurses

Tetrafrog.o: Tetrafrog.cpp Tetrafrog.hpp
	g++ -c Tetrafrog.cpp -lncurses

Leaderboard.o: Leaderboard.cpp Leaderboard.hpp tools.h
	g++ -c Leaderboard.cpp -lncurses

Tetrimino.o: Tetrimino.cpp Tetrimino.hpp tools.h
	g++ -c Tetrimino.cpp

I.o: tetriminos/I.cpp tetriminos/I.hpp Tetrimino.hpp
	g++ -c tetriminos/I.cpp

O.o: tetriminos/O.cpp tetriminos/O.hpp Tetrimino.hpp
	g++ -c tetriminos/O.cpp

J.o: tetriminos/J.cpp tetriminos/J.hpp Tetrimino.hpp
	g++ -c tetriminos/J.cpp

L.o: tetriminos/L.cpp tetriminos/L.hpp Tetrimino.hpp
	g++ -c tetriminos/L.cpp

S.o: tetriminos/S.cpp tetriminos/S.hpp Tetrimino.hpp
	g++ -c tetriminos/S.cpp

Z.o: tetriminos/Z.cpp tetriminos/Z.hpp Tetrimino.hpp
	g++ -c tetriminos/Z.cpp

T.o: tetriminos/T.cpp tetriminos/T.hpp Tetrimino.hpp
	g++ -c tetriminos/T.cpp

tools.o: tools.cpp tools.h
	g++ -c tools.cpp

# Richiamarlo con "make clean"
clean:
	rm *.o a.out

