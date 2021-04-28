#pragma once
#include<iostream>
#include"NavalPoint.h"

class Submarine
{
private:
	NavalPoint point;
public:
	Submarine() {  };
	Submarine(NavalPoint p);
	Submarine(int x, char y);
	~Submarine() {   };

	void Set_Submarine(NavalPoint p) { point = p; }
	void Set_Submarine(int m_x, char m_y);
	
	NavalPoint Get_NavalPoint(void) { return point; }
	void transforms_abc_to_ABC(char aux);


	void Set_Random_y();
	void Set_Random_x();
	void Ask_Set_Submarine();
	void Random_Point_Submarine();

	void Show_Submarine();
};

