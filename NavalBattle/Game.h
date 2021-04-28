
#include"Board.h"
#include"Player.h"

class Game
{
private:
	Player p1, p2;
	Board board_game;
public:
	Game(Board b1, Player p);
	Game(Board b1, string n, int plays);      //para o single player
	Game(Board b2, string n1, string n2, int plays);     // para o multiplayer
	virtual ~Game() { };

	void Set_Board(Board b1) { board_game = b1; }
	Board Get_Board() { return board_game; }

	void Help();
	void Start_Game_Single_Player();
	void Start_Game_Multiplayer();
	void Start_Game();
	
	int Menu();
};


