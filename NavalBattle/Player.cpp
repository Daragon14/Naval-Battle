#include "Player.h"

Player::Player() {
	name = "Nobody";
	plays = 1;
}
Player::Player(string s, int n) {
	name = s;
	plays = n;
}