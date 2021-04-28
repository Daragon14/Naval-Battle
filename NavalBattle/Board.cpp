#include "Board.h"
#include <iostream>
#define ANSI_COLOR_BLUE     "\u001b[96m"
#define ANSI_COLOR_DARKBLUE  "\u001b[94m"
#define ANSI_COLOR_RESET     "\x1b[0m"

using namespace std;

Board::Board(){
	
}
void Board::Abc(void) {
	int l;
	for (l = 65; l <= 74; l++) {
		if (l == 65) {
			cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_BLUE << "       " << char(65) << ANSI_COLOR_RESET;
		}
		else {
			cout << "   " << ANSI_COLOR_BLUE << char(l) << ANSI_COLOR_RESET;
		}
	}cout << "            ";
}

void Board::Top() {
	int i;
	cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << "     " << ANSI_COLOR_BLUE << char(201);
	for (i = 1; i < 40; i++) {
		if (i % 4 == 0) {
			cout << char(203);
		}
		else {
			cout << char(205);
		}
	}
	cout << char(187) << ANSI_COLOR_RESET;
	cout << "          ";
}

void Board::Titule() {

	for (int z = 0; z <= 100; z++) {

		if (z == 49) {
			cout << ANSI_COLOR_DARKBLUE << char(218);
		}
		else if (z > 49 && z < 67) {
			cout << char(196);
		}
		else if (z == 67) {
			cout << char(191);
		}
		else {
			cout << " ";
		}
	}cout << endl;
	for (int z = 0; z <= 60; z++) {
		cout << " ";
		if (z == 48) {
			cout << char(179);
		}
		if (z == 50) {
			cout << ANSI_COLOR_RESET << "BATALHA NAVAL" << ANSI_COLOR_DARKBLUE;
		}
		if (z == 52) {
			cout << char(179);
		}
	}cout << endl;
	for (int z = 0; z < 110; z++) {
		if (z == 0) {
			cout << char(218);
		}
		cout << char(196);
		if (z == 54) {
			cout << char(194);
		}if (z == 63 || z == 47) {
			cout << char(193);
		}
		if (z == 109) {
			cout << char(191);
		}

	}
	cout << ANSI_COLOR_RESET << endl;

}
void Board::Mid(char a[10][10], int numero_linha) {
	int j;
	if (numero_linha + 1 == 10) {
		cout << ANSI_COLOR_DARKBLUE << char(179) << "   " << ANSI_COLOR_BLUE << numero_linha + 1;
		for (j = 0; j <= 40; j++) {
			if (j % 4 == 0 || j == 0 || j == 40) {
				cout << ANSI_COLOR_BLUE << char(186);
			}
			else if (j == 2) {
				cout << ANSI_COLOR_RESET << a[9][0];
			}
			else if ((j - 2) % 4 == 0) {
				cout << ANSI_COLOR_RESET << a[9][(j - 2) / 4];
			}
			else {
				cout << " ";
			}
		}
	}
	else {
		cout << ANSI_COLOR_DARKBLUE << char(179) << "   " << ANSI_COLOR_BLUE << numero_linha + 1 << " " << char(186);
		for (j = 1; j <= 40; j++) {
			if (j % 4 == 0) {
				cout << ANSI_COLOR_BLUE << char(186);
			}
			else if (j == 2) {
				cout << ANSI_COLOR_RESET << a[numero_linha][0];
			}
			else if ((j - 2) % 4 == 0) {
				cout << ANSI_COLOR_RESET << a[numero_linha][(j - 2) / 4];
			}
			else {
				cout << " ";
			}
		}
	}cout << ANSI_COLOR_RESET;
	cout << "          ";
}

void Board::Bottom_Mid() {
	int k;
	cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_BLUE << "     " << char(204);
	for (k = 1; k < 40; k++) {
		if (k % 4 == 0 && k != 0) {
			cout << char(206);
		}
		else {
			cout << char(205);
		}
	}cout << char(185);
	cout << "          ";
}

void Board::Bottom() {
	cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_BLUE << "     " << char(200);
	int l;
	for (l = 1; l < 40; l++) {
		if (l % 4 == 0 && l != 0) {
			cout << char(202);
		}
		else {
			cout << char(205);
		}
	}cout << char(188) << ANSI_COLOR_RESET;
	cout << "          ";
}


void Board::Lastline_Board() {
	for (int z = 0; z < 115; z++) {
		if (z == 0) {
			cout << ANSI_COLOR_DARKBLUE << char(192);
		}
		else if (z == 15 || z == 30 || z == 75 || z == 89) {
			cout << char(194);
		}
		else if (z == 57) {
			cout << char(193);
		}
		else if (z == 114) {
			cout << char(217);
		}
		else {
			cout << char(196);
		}
	}cout << ANSI_COLOR_RESET << endl;
}
void Board::Names_Tags() {
	char player[6] = { 'P', 'L', 'A', 'Y', 'E', 'R' };
	char bot[3] = { 'B', 'O', 'T' };

	for (int z = 0; z < 115; z++) {
		if (z == 15 || z == 30 || z == 75 || z == 89) {
			cout << ANSI_COLOR_DARKBLUE << char(179);
		}
		else if (z > 19 && z < 26) {
			cout << ANSI_COLOR_RESET << player[z - 20];
		}
		else if (z > 80 && z < 84) {
			cout << ANSI_COLOR_RESET << bot[z - 81];

		}
		else {
			cout << " ";
		}
	}cout << ANSI_COLOR_RESET << endl;
}

void Board::Last_Line_Names() {
	for (int z = 0; z < 115; z++) {
		if ((z > 75 && z < 89) || (z > 15 && z < 30)) {
			cout << ANSI_COLOR_DARKBLUE << char(196);
		}
		else if (z == 75 || z == 15) {
			cout << ANSI_COLOR_DARKBLUE << char(192);
		}
		else if (z == 89 || z == 30) {
			cout << char(217);
		}
		else {
			cout << ' ';
		}
	}cout << ANSI_COLOR_RESET;
	cout << endl;
}

void Board::Show() {
	Titule();

	Abc();
	Abc();
	cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << endl;

	Top();
	Top();
	cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << endl;

	for (int n = 0; n < 10; n++) {
		if (n + 1 == 10) {           ///last line
			Mid(a, n);
			Mid(b, n);

			cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << endl;

			Bottom();
			Bottom();
			cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << endl;
		}
		else {						 ///all the others lines
			Mid(a, n);
			Mid(b, n);

			cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << endl;

			Bottom_Mid();
			Bottom_Mid();
			cout << ANSI_COLOR_DARKBLUE << char(179) << ANSI_COLOR_RESET << endl;
		}
	}
	Lastline_Board();
	Names_Tags();
	Last_Line_Names();
};

void Board::Fill_Matriz() {

	for (int t = 0; t < 10; t++) {
		for (int q = 0; q < 10; q++) {
			a[t][q] = char(46);
			b[t][q] = char(46);
		}
	}
	for (int i = 0; i < 4; i++) {
		a[s_a[i].Get_NavalPoint().Get_x() - 1][s_a[i].Get_NavalPoint().Get_int_y(s_a[i].Get_NavalPoint().Get_y())] = 'O';
		b[s_b[i].Get_NavalPoint().Get_x() - 1][s_b[i].Get_NavalPoint().Get_int_y(s_b[i].Get_NavalPoint().Get_y())] = '.';
	}
}
void Board::Fill_Matriz_Multiplayer() {

	for (int t = 0; t < 10; t++) {
		for (int q = 0; q < 10; q++) {
			a[t][q] = char(46);
			b[t][q] = char(46);
		}
	}
	for (int i = 0; i < 4; i++) {
		a[s_a[i].Get_NavalPoint().Get_x() - 1][s_a[i].Get_NavalPoint().Get_int_y(s_a[i].Get_NavalPoint().Get_y())] = '.';
		b[s_b[i].Get_NavalPoint().Get_x() - 1][s_b[i].Get_NavalPoint().Get_int_y(s_b[i].Get_NavalPoint().Get_y())] = '.';
	}
}


void Board::Showsubmarine() {
	for (int i = 0; i < 4; i++) {
		s_a[i].Show_Submarine();
	}
}

int Board::transforms_chary_inty(char m_y) {
	char abc[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	for (int i = 0; i < 10; i++) {
		if (abc[i] == m_y) {
			return i;
		}
	}
}