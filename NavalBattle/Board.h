#pragma once
#include"Submarine.h"

class Board
{
private:
	char a[10][10]; // player 1
	char b[10][10]; // player2/bot
	Submarine s_a[4]; //submarinos do player
	Submarine s_b[4]; //submarinos do bot/player2
public:
	Board();
	~Board() {  }

	void Set_submarine_A(Submarine s[4], int n) { s_a[n]= s[n]; }
	void Set_submarine_B(Submarine s[4], int n) { s_b[n] = s[n]; }
	void Set_A_shot(int x, int y, char shot) { a[x][y] = shot; }
	void Set_B_shot(int x, int y, char shot) { b[x][y] = shot; }
	
	int transforms_chary_inty(char m_y);
	void Showsubmarine();

	Submarine Get_submarine_A(int n) { return s_a[n]; }
	Submarine Get_Submarine_B(int n) { return s_b[n]; }
	char Get_A_position(int x, int y) { return a[x][y]; }
	char Get_B_position(int x, int y) { return b[x][y]; }

	void Abc();
	void Top();
	void Titule();
	void Mid(char a[10][10], int numero_linha);
	void Bottom_Mid();
	void Bottom();
	void Lastline_Board();
	void Names_Tags();
	void Last_Line_Names();
	void Show();
	void Fill_Matriz();
	void Fill_Matriz_Multiplayer();
};

