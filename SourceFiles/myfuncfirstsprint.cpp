#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

void getMaxCoord(int &x, int &y){

	getmaxyx(stdscr,y,x);

	y=y-1;
	x=x-1;



}

void AddScore(int Score){

	ofstream fout;
	fout.open ("./Leaderboard",ios::app);

	fout << Score << endl;

	fout.close();


}

void StartGame(){

clear();
int x = 0;
int y = 5;
printw("(Schermata di gioco Bellissima)" );

y +=1;
mvprintw(y,x, "         ()-()");
y +=1;
mvprintw(y,x, "      .-(___)-.");
y +=1;
mvprintw(y,x, "       _<   >_");
y +=1;
mvprintw(y,x, "       |      |");

y +=1;

printw("(Stampa della griglia e delle altre robe)(Eventualemente alla fine ricordarsi di ritornale al menu)" );

}

int main() {
	initscr();

	int x,y;
	int c;
	getMaxCoord(x,y);
	x = x/2 -14;
	y /=2;

mvprintw(y,x, "(Schermata Principale bellissima)");
y+=1;
mvaddch(y,x,'>');


printw("Play(Premi z)");
while(getch() != 'z'){
	mvprintw(y+10,x, "(Ho detto z idiota)");
}

StartGame();

	//	HomePage();

	//AddScore(12);
	//AddScore(56);
	//AddScore(14);

	getch();

	endwin();
}
