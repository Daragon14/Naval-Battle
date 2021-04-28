#include"NavalPoint.h"
#include"Submarine.h"
#include"Board.h";
#include"Game.h"

#define ANSI_COLOR_BLUE     "\u001b[96m"
#define ANSI_COLOR_DARKBLUE  "\u001b[94m"
#define ANSI_COLOR_RESET     "\x1b[0m"

using namespace std;

int main(){
	Board b1;
	Player p1;
	Game g1(b1, p1);

	g1.Start_Game();
}