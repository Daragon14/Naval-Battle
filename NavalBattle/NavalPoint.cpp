#include "NavalPoint.h"
#include<iostream>

using namespace std;

NavalPoint::NavalPoint(int m_x, char m_y) {
	x = m_x;
	y = m_y;
}

NavalPoint::NavalPoint(int m_x, int m_y) {
	x = m_x;
	y = m_y;
}
NavalPoint::NavalPoint() {
	x = -1;
	y = 'Z';
}

NavalPoint::~NavalPoint() {

}
void NavalPoint::Set_NP(int m_x, char m_y) {
	m_x = x;
	m_y = y;
}
void NavalPoint::Set_NP(NavalPoint NP) {
	NP.Set_x(x);
	NP.Set_y(y);
}
void NavalPoint::Ask2Set_NP(void){
	int m_x;
	char m_y;

	cout << "X(1-10):";
	cin >> m_x;
	x = m_x;

	cout << endl;

	cout << "Y(A-J):";
	cin >> m_y;
	y = m_y;

	cout << endl;
}

bool NavalPoint::IsValid(void) {
	bool prove;
	char ABC[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' }, abc[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	prove = false;
	if (x > 0 && x <= 10) {
		for (int i = 0; i < 10; i++) {
			if (abc[i] == y || ABC[i] == y) {
				prove = true;
			}
		}
	}
	return prove;
}

void NavalPoint::ShowNavalPoint(){

	cout << "NavalPoint(" << x << "," << y << ")" << endl;

}

bool NavalPoint::operator == (const NavalPoint p) const {
	bool prove = false;

	if (x == p.x && y == p.y){
			prove = true;
	}
	return prove;
}

bool NavalPoint:: operator != (const NavalPoint p) const {
	bool prove = false;

	if (x !=p.x || y !=p.y){
			prove = true;
		}
	return prove;
}

void NavalPoint:: operator = (NavalPoint p) {
	
	Set_x(p.x);
	Set_y(p.y);

}

int NavalPoint::Get_int_y(char m_y) const{
	char ABC[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	char abc[10]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

	for (int i = 0; i <= 9; i++) {
		if (abc[i] == m_y || ABC[i] == m_y) {
			return i;
		}
	}
}