#include <fstream>
#include <iostream>
#include <ncurses.h>
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



int main() {
	initscr();

	//	HomePage();

	AddScore(12);
	AddScore(56);
	AddScore(14);

	getch();

	endwin();
}
