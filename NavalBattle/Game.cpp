#include "Game.h"
#include "Player.h"
#include<chrono>
#include<thread>


#define ANSI_COLOR_BLUE     "\u001b[96m"
#define ANSI_COLOR_DARKBLUE  "\u001b[94m"
#define ANSI_COLOR_RESET     "\x1b[0m"
#define ANSI_COLOR_RED       "\u001B[31m"
#define ANSI_COLOR_GREEN      "\u001B[32m"

using namespace std;

Game::Game(Board b1, Player p) {
	board_game = b1;
	p1.Set_name(p.Get_Name());
	p1.Set_plays(p.Get_Plays());
}

Game::Game(Board b2, string n1, string n2, int plays) {
	board_game = b2;
	p1.Set_name(n1);
	p2.Set_name(n2);
	p1.Set_plays(plays);
	
}

int Game::Menu(){
	int option;

	for (int i = 0; i <= 30; i++) {
		if (i == 0) {
			cout << ANSI_COLOR_DARKBLUE << char(218);
		}
		else if (i == 30) {
			cout << char(191) << endl;
		}
		else {
			cout << char(196);
		}
	}
	cout << char(179) << ANSI_COLOR_RESET << "      NAVAL BATTLE MENU      " << ANSI_COLOR_DARKBLUE << char(179) << endl;
	for (int i = 0; i <= 30; i++) {
		if (i == 0) {
			cout << char(195);
		}
		else if (i == 30) {
			cout << char(180) << endl;
		}
		else {
			cout << char(196);
		}
	}
	cout << char(179) << ANSI_COLOR_RESET << "  1.New game                 " << ANSI_COLOR_DARKBLUE << char(179) << endl;
	cout << char(179) << ANSI_COLOR_RESET << "  2.Load Game                " << ANSI_COLOR_DARKBLUE << char(179) << endl;
	cout << char(179) << ANSI_COLOR_RESET << "  3.Save Game                " << ANSI_COLOR_DARKBLUE << char(179) << endl;
	cout << char(179) << ANSI_COLOR_RESET << "  4.Help                     " << ANSI_COLOR_DARKBLUE << char(179) << endl;
	cout << char(179) << ANSI_COLOR_RESET << "  5.Exit                     " << ANSI_COLOR_DARKBLUE << char(179) << endl;
	for (int i = 0; i <= 30; i++) {
		if (i == 0) {
			cout << char(192);
		}
		else if (i == 30) {
			cout << char(217) << ANSI_COLOR_RESET << endl;
		}
		else {
			cout << char(196);
		}
	}
	cout << "Choose an option(1-5):  ";
	cin >> option;
	return option;
}


void Game::Start_Game(){
	int option_type = 1;
	switch (Menu()) {
	case 1:
		while (option_type != 1 || option_type != 2) {
			for (int i = 0; i <= 30; i++) {
				if (i == 0) {
					cout << ANSI_COLOR_DARKBLUE << char(218);
				}
				else if (i == 30) {
					cout << char(191) << endl;
				}
				else {
					cout << char(196);
				}
			}
			cout << char(179) << ANSI_COLOR_RESET << "1.Single Player              " << ANSI_COLOR_DARKBLUE << char(179) << endl;
			cout << char(179) << ANSI_COLOR_RESET << "2.Multiplayer                " << ANSI_COLOR_DARKBLUE << char(179) << endl;
			for (int i = 0; i <= 30; i++) {
				if (i == 0) {
					cout << char(192);
				}
				else if (i == 30) {
					cout << char(217) << endl;
				}
				else {
					cout << char(196);
				}
			}
			cout << ANSI_COLOR_RESET << "Choose a Type of Game(1-Single // 2-Multiplayer): ";
			cin >> option_type;
			cout << endl;

			if (option_type == 1) {

				cout << endl << endl << endl;
				cout << "Please wait for the game to load..." << endl;
				auto s = std::chrono::high_resolution_clock::now();
				std::this_thread::sleep_for(3000ms);
				auto e = std::chrono::high_resolution_clock::now();


				Start_Game_Single_Player();
			}
			else if (option_type == 2) {
				auto n = std::chrono::high_resolution_clock::now();
				std::this_thread::sleep_for(3000ms);
				auto m = std::chrono::high_resolution_clock::now();

				Start_Game_Multiplayer();

				break;
				break;
			}

		}
	case 2:
		//Load_Game();
		break;
	case 3:
		//Save_Game();
		break;
	case 4:
		Help();
		break;
	case 5:
		cout << "GAME OVER" << endl;
		cout << "Come back later :)" << endl;
		break;
	}
		
}


void Game::Start_Game_Single_Player() {
	Submarine s1[4], s2[4];
	int boats_dead_bot = 0, boats_dead_player = 0, plays = p1.Get_Plays();
	string auxx;

	cout << ANSI_COLOR_BLUE << "NAME: " << ANSI_COLOR_RESET;
	cin >> auxx;
	p1.Set_name(auxx);



	for (int i = 0; i < 30; i++) {
		if (i == 0) {
			cout <<ANSI_COLOR_DARKBLUE << char(201);
		}else if (i == 29) {
			cout << char(187) << endl;
		}
		else{
			cout << char(205);
		}
	}

	cout  <<char(186) << ANSI_COLOR_BLUE << "Please set your submarines: " <<  ANSI_COLOR_DARKBLUE << char(186) << endl;
	for (int i = 0; i < 30; i++) {
		if (i == 0) {
			cout << char(200);
		}
		else if (i == 29) {
			cout << char(188) << ANSI_COLOR_RESET << endl;
		}
		else {
			cout << char(205);
		}
	}
	
	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < 20; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == 19){
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}
		
		cout << char(179) << ANSI_COLOR_RESET << i + 1 << " Submarine:      " << ANSI_COLOR_DARKBLUE << char(179) << endl;
		
		for (int i = 0; i < 20; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == 19) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}

		s1[i].Ask_Set_Submarine();
		if (s1[i].Get_NavalPoint().IsValid() == true) {

			s1[i].transforms_abc_to_ABC(s1[i].Get_NavalPoint().Get_y());
			board_game.Set_submarine_A(s1, i);
		}
		else {
			cout <<ANSI_COLOR_RED << "Write the x between 1 to 10 and y between A to J please. Try again..." << ANSI_COLOR_RESET <<  endl;
			i--;
		}

		
	}
	cout << endl << endl;
	cout << "Submarines pointed: " << endl;
	for (int i = 0; i < 4; i++) {
		board_game.Get_submarine_A(i).Show_Submarine();
	}
	cout << endl;
	cout << "Setting the enemies submarines..." << endl;

	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		s2[i].Random_Point_Submarine();
		board_game.Set_submarine_B(s2, i);
	}
	

	cout << "Filling the sea with the boats..." << endl;
	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(7000ms);
	auto end = std::chrono::high_resolution_clock::now();
	
	board_game.Fill_Matriz();
	cout << "Starting game..." << endl;
	cout << "Wait a few seconds..."<< endl;

	auto strt = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(7000ms);
	auto ed = std::chrono::high_resolution_clock::now();


	while (boats_dead_bot != 4 && boats_dead_player != 4) {
		int aux = 0, bot_choice_x = 0, bot_choice_inty = 0;
		char auy = ' ', bot_choice_char = ' ', abc[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
		int size_of_name;

		size_of_name = p1.Get_Name().length();

		plays++;
		
		board_game.Show();
		
		cout << endl << endl;

		for (int i = 0; i < size_of_name+9; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == size_of_name+8) {
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << char(179) << ANSI_COLOR_BLUE << " " << p1.Get_Name() << " TURN " << ANSI_COLOR_DARKBLUE << char(179) << endl;

		for (int i = 0; i < size_of_name+9; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == size_of_name+8) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}

		
		cout << "Try to guess the enemy boat: " << endl;
		
		for (int u = 1; u < 4; u++) {
			int wrong = 0;
			
			cout << ">>> X(1-10): ";
			cin >> aux;
			cout << ">>> Y(A-J): ";
			cin >> auy;

			

			for (int i = 0; i < 4; i++) {

				board_game.Get_submarine_A(i).transforms_abc_to_ABC(auy);

				if (board_game.Get_Submarine_B(i).Get_NavalPoint().Get_x() == aux && board_game.Get_Submarine_B(i).Get_NavalPoint().Get_y() == auy) {
					if (board_game.Get_B_position(aux - 1, board_game.transforms_chary_inty(auy)) == char(176)){
						cout << "You already destroyed in here." << endl;
						cout << "You lost 1 play." << endl;
					}
					else {

						cout << ANSI_COLOR_GREEN << " You shot a enemy bot with sucess!!" << ANSI_COLOR_RESET << endl;

						boats_dead_bot++;

						board_game.Set_B_shot(aux - 1, board_game.transforms_chary_inty(auy), char(176));

						if (boats_dead_bot == 4) {
							break;
							break;
						}
					}
				}
				
				else if (board_game.Get_Submarine_B(i).Get_NavalPoint().Get_x() != aux || board_game.Get_Submarine_B(i).Get_NavalPoint().Get_y() != auy) {
					wrong++;
					
					if (wrong == 4) {
						if (board_game.Get_B_position(aux - 1, board_game.transforms_chary_inty(auy)) == ' ') {
							cout << "You already destroyed this place." << endl;
							cout << "You lost 1 play." << endl;
						}
						else {
							cout << ANSI_COLOR_RED << "You failed the submarine!!" << ANSI_COLOR_RESET << endl;

							board_game.Set_B_shot(aux - 1, board_game.transforms_chary_inty(auy), ' ');
							if (boats_dead_player == 4) {
								break;
								break;

							}
						}
					}
				}
			}
		}
		cout << endl << endl;

		for (int i = 0; i < 12; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == 11) {
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << char(179) << ANSI_COLOR_BLUE << " BOT TURN " << ANSI_COLOR_DARKBLUE << char(179) << endl;

		for (int i = 0; i < 12; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == 11) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}



		for (int u = 1; u < 4; u++) {
			int w = 0;

			bot_choice_x = rand() % 10;
			bot_choice_inty = rand() % 10;
			bot_choice_char = abc[bot_choice_inty];

			cout << "Bot choosed " << "(" << bot_choice_x + 1 << "," << bot_choice_char << ")" << endl;
			
			for (int i = 0; i < 4; i++) {
				if (board_game.Get_submarine_A(i).Get_NavalPoint().Get_x() == bot_choice_x + 1 && board_game.Get_submarine_A(i).Get_NavalPoint().Get_y() == bot_choice_char) {
					if (board_game.Get_A_position(bot_choice_x, bot_choice_inty) == char(176)) {
						cout << "This boat is already down" << endl;
						cout << "The bot lost 1 play;" << endl;
					}
					else {
						cout << ANSI_COLOR_RED << "The bot shot with sucess !!" << ANSI_COLOR_RESET << endl;

						boats_dead_player++;
						board_game.Set_A_shot(bot_choice_x, board_game.transforms_chary_inty(bot_choice_char), char(176));
					}
				}
				else if (board_game.Get_submarine_A(i).Get_NavalPoint().Get_x() != bot_choice_x + 1 || board_game.Get_submarine_A(i).Get_NavalPoint().Get_y() != bot_choice_char) {
					
					w++;
					
					if (w == 4) {
						if (board_game.Get_A_position(bot_choice_x, bot_choice_inty) == ' ') {
							cout << "The boat already destroyed this place" << endl;
							cout << "You lost 1 play" << endl;
						}
						else {
							cout << ANSI_COLOR_GREEN << "The bot missed the shot in your submarine!!" << ANSI_COLOR_RESET << endl;
							board_game.Set_A_shot(bot_choice_x, board_game.transforms_chary_inty(bot_choice_char), ' ');
						}
					}
				}
			}
			auto st = std::chrono::high_resolution_clock::now();
			std::this_thread::sleep_for(2000ms);
			auto ended = std::chrono::high_resolution_clock::now();
		}
	};

	cout << endl << endl;
	if (boats_dead_bot == 4) {
		cout << ANSI_COLOR_GREEN << "CONGRATS!! you won!!" << ANSI_COLOR_RESET;
		cout << "You won with " << plays << " plays" << endl;
	}
	else {
		cout << ANSI_COLOR_RED << "GAME OVER! YOU LOST!" << ANSI_COLOR_RESET << endl;
		cout << "The bot won with " << plays << " plays" << endl;
	}
	
}


void Game::Help() {
	cout << endl;
	cout << ANSI_COLOR_DARKBLUE << "           NAVAL BATTLE GUIDE               " << ANSI_COLOR_RESET << endl;
	
	cout << "The Naval Battle is a battle between two fleets of boats, that can be composed with 4 types of boat (submarines, destroyer, cruiser, battleship and aircraft carrier)" << endl;
	cout << "This game can be played Singleplayer (player vs bot) or Multiplayer (player vs player). Each player tries to destroy the boats of the other player. " << endl;
	cout << "The players play in turns of 3 throws. The player who needs less plays to take down all the boats of the other player is the winner." << endl;
	cout << "Each player/bot has a structer matrix 10x10, that in the beginning of the game the player has to put the coordinates X(1-10) and Y(A-J)" << endl << endl; 
	cout << ANSI_COLOR_BLUE << "SYMBOLS OF THE BOATS" << ANSI_COLOR_RESET << endl;
	cout << "- '.' Represents an empty space" << endl;
	cout << "- 'O' Represents an occuped boat" << endl;
	cout << "- 'T' Represents a destroyed Boat" << endl;
	cout << "- 'A' Represents a shot in a empty space" << endl << endl;

	cout << "Good luck with the games!!" << endl;

}

void Game::Start_Game_Multiplayer() {
	Submarine s1[4], s2[4];
	int boats_dead_player1 = 0, boats_dead_player2 = 0, plays_p1 = p1.Get_Plays(), plays_p2 = p2.Get_Plays(), size_name_p1, size_name_p2, plays = 0;;
	string aux_name_p1, aux_name_p2;

	cout << ANSI_COLOR_BLUE << "Name of the First Player: " << ANSI_COLOR_RESET;
	cin >> aux_name_p1;
	p1.Set_name(aux_name_p1);

	cout << ANSI_COLOR_BLUE << "Name of the Second Player: " << ANSI_COLOR_RESET;
	cin >> aux_name_p2;
	p2.Set_name(aux_name_p2);

	size_name_p1 = aux_name_p1.length();
	size_name_p2 = aux_name_p2.length();

	for (int i = 0; i < 31 + size_name_p1; i++) {
		if (i == 0) {
			cout << ANSI_COLOR_DARKBLUE << char(201);
		}
		else if (i == 30 + size_name_p1) {
			cout << char(187) << endl;
		}
		else {
			cout << char(205);
		}
	}
	cout << char(186) << ANSI_COLOR_BLUE << p1.Get_Name() << " please set your submarines: " << ANSI_COLOR_DARKBLUE << char(186) << endl;

	for (int i = 0; i < 31 + size_name_p1; i++) {
		if (i == 0) {
			cout << char(200);
		}
		else if (i == 30 + size_name_p1) {
			cout << char(188) << ANSI_COLOR_RESET << endl;
		}
		else {
			cout << char(205);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < 20; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == 19) {
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << char(179) << ANSI_COLOR_RESET << i + 1 << " Submarine:      " << ANSI_COLOR_DARKBLUE << char(179) << endl;

		for (int i = 0; i < 20; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == 19) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}

		s1[i].Ask_Set_Submarine();
		board_game.Set_submarine_A(s1, i);
	
	}
	cout << endl << endl;
	for (int i = 0; i < 31 + size_name_p2; i++) {
		if (i == 0) {
			cout << ANSI_COLOR_DARKBLUE << char(201);
		}
		else if (i == 30 + size_name_p2) {
			cout << char(187) << endl;
		}
		else {
			cout << char(205);
		}
	}
	cout << char(186) << ANSI_COLOR_BLUE << p2.Get_Name() << " please set your submarines: " << ANSI_COLOR_DARKBLUE << char(186) << endl;

	for (int i = 0; i < 31 + size_name_p2; i++) {
		if (i == 0) {
			cout << char(200);
		}
		else if (i == 30 + size_name_p2){
			cout << char(188) << ANSI_COLOR_RESET << endl;
		}
		else {
			cout << char(205);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < 20; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == 19) {
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << char(179) << ANSI_COLOR_RESET << i + 1 << " Submarine:      " << ANSI_COLOR_DARKBLUE << char(179) << endl;

		for (int i = 0; i < 20; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == 19) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}

		s2[i].Ask_Set_Submarine();
		board_game.Set_submarine_B(s2, i);

	}
	cout << endl << endl;
	cout << "Submarines pointed of " << p2.Get_Name() << endl;
	cout << endl;

	cout << "Filling the sea with the boats..." << endl;
	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(7000ms);
	auto end = std::chrono::high_resolution_clock::now();

	board_game.Fill_Matriz();
	cout << "Starting game..." << endl;
	cout << "Wait a few seconds..." << endl;

	auto strt = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(7000ms);
	auto ed = std::chrono::high_resolution_clock::now();

	board_game.Fill_Matriz_Multiplayer();
	cout << "Starting game..." << endl;
	cout << "Wait a few seconds..." << endl;

	while (boats_dead_player1 != 4 && boats_dead_player2 != 4) {

		plays++;

		board_game.Show();

		cout << endl << endl;

		for (int i = 0; i < size_name_p1 + 9; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == size_name_p1 + 8) {
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << char(179) << ANSI_COLOR_BLUE << " " << p1.Get_Name() <<  " TURN " << ANSI_COLOR_DARKBLUE << char(179) << endl;

		for (int i = 0; i < size_name_p1 + 9; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == size_name_p1 + 8) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << "Try to guess the enemy boat: " << endl;
		for (int u = 1; u < 4; u++) {
			int wrong = 0, aux = 0;
			char auy;

			cout << ">>> X(1-10): ";
			cin >> aux;
			cout << ">>> Y(A-J): ";
			cin >> auy;

			

			for (int i = 0; i < 4; i++) {
				
				board_game.Get_submarine_A(i).transforms_abc_to_ABC(auy);

				if (board_game.Get_Submarine_B(i).Get_NavalPoint().Get_x() == aux && board_game.Get_Submarine_B(i).Get_NavalPoint().Get_y() == auy) {
					if (board_game.Get_B_position(aux - 1, board_game.transforms_chary_inty(auy)) == 'T') {
						cout << "You already destroyed in here." << endl;
						cout << "You lost 1 play." << endl;
					}
					else {

						cout << ANSI_COLOR_GREEN << " You shot a boat with sucess!!" << ANSI_COLOR_RESET << endl;

						boats_dead_player2++;

						board_game.Set_B_shot(aux - 1, board_game.transforms_chary_inty(auy), 'T');

						if (boats_dead_player2 == 4) {
							break;
							break;
						}
					}
				}
				else if (board_game.Get_Submarine_B(i).Get_NavalPoint().Get_x() != aux || board_game.Get_Submarine_B(i).Get_NavalPoint().Get_y() != auy) {
					wrong++;

					if (wrong == 4) {
						if (board_game.Get_B_position(aux - 1, board_game.transforms_chary_inty(auy)) == 'A') {
							cout << "You already destroyed this place." << endl;
							cout << "You lost 1 play." << endl;
						}
						else {
							cout << ANSI_COLOR_RED << "You failed the submarine!!" << ANSI_COLOR_RESET << endl;

							board_game.Set_B_shot(aux - 1, board_game.transforms_chary_inty(auy), 'A');
							if (boats_dead_player2 == 4) {
								break;
								break;
							}
						}
					}
				}
			}
		}
		cout << endl << endl;


		for (int i = 0; i < size_name_p2 + 9; i++) {
			if (i == 0) {
				cout << ANSI_COLOR_DARKBLUE << char(218);
			}
			else if (i == size_name_p2 + 8) {
				cout << char(191) << endl;
			}
			else {
				cout << char(196);
			}
		}

		cout << char(179) << ANSI_COLOR_BLUE << " " << p2.Get_Name() << " TURN " << ANSI_COLOR_DARKBLUE << char(179) << endl;

		for (int i = 0; i < size_name_p2 + 9; i++) {
			if (i == 0) {
				cout << char(192);
			}
			else if (i == size_name_p2 + 8) {
				cout << char(217) << ANSI_COLOR_RESET << endl;
			}
			else {
				cout << char(196);
			}
		}
		
		
		for (int u = 1; u < 4; u++) {
			int aux, wrong = 0;
			char auy;
			cout << ">>> X(1-10): ";
			cin >> aux;
			cout << ">>> Y(A-J): ";
			cin >> auy;

			for (int i = 0; i < 4; i++) {

				board_game.Get_Submarine_B(i).transforms_abc_to_ABC(auy);

				if (board_game.Get_submarine_A(i).Get_NavalPoint().Get_x() == aux && board_game.Get_submarine_A(i).Get_NavalPoint().Get_y() == auy) {
					if (board_game.Get_A_position(aux - 1, board_game.transforms_chary_inty(auy)) == 'T') {
						cout << "You already destroyed in here." << endl;
						cout << "You lost 1 play." << endl;
					}
					else {

						cout << ANSI_COLOR_GREEN << " You shot a boat with sucess!!" << ANSI_COLOR_RESET << endl;

						boats_dead_player1++;

						board_game.Set_A_shot(aux - 1, board_game.transforms_chary_inty(aux), 'T');

						if (boats_dead_player1 == 4) {
							break;
							break;
						}
					}
				}
				else if (board_game.Get_submarine_A(i).Get_NavalPoint().Get_x() != aux || board_game.Get_submarine_A(i).Get_NavalPoint().Get_y() != auy) {

					wrong++;

					if (wrong == 4) {
						if (board_game.Get_A_position(aux - 1, board_game.transforms_chary_inty(auy)) == 'A') {
							cout << "You already destroyed this place." << endl;
							cout << "You lost 1 play." << endl;
						}
						else {
							cout << ANSI_COLOR_RED << "You failed the submarine!!" << ANSI_COLOR_RESET << endl;

							board_game.Set_A_shot(aux - 1, board_game.transforms_chary_inty(auy), 'A');
							if (boats_dead_player2 == 4) {
								break;
								break;
							}
						}
					}
				}
			}
		}
			auto st = std::chrono::high_resolution_clock::now();
			std::this_thread::sleep_for(2000ms);
			auto ended = std::chrono::high_resolution_clock::now();
		
	}
	cout << endl << endl;
	board_game.Show();
	if (boats_dead_player2 == 4) {
		cout << ANSI_COLOR_GREEN << "CONGRATS" << p1.Get_Name() <<"!! you won" << ANSI_COLOR_RESET;
		cout << "You won with " << plays << " plays" << endl;
	}
	else {
		cout << ANSI_COLOR_RED << "CONGRATS" << p2.Get_Name() << ANSI_COLOR_RESET << endl;
		cout << "You won with" << plays << " plays" << endl;
	}

}
