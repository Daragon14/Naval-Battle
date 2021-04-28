#pragma once
#include<iostream>
#include<string.h>

using namespace std;

class Player
{
private:
	string name;
	int plays;
public:
	Player();
	Player(string s, int n);
	~Player(){ }

	void Set_plays(int m_p) { plays = m_p; }
	void Set_name(string m_n) { name = m_n; }
	string Get_Name() { return name; }
	int Get_Plays() { return plays; }
		


};

