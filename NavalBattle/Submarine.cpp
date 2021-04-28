#include "Submarine.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Submarine::Submarine(NavalPoint p){
	point = p;
}
Submarine::Submarine(int x, char y) {
	point.Set_x(x);
	point.Set_y(y);
}

void Submarine::Set_Submarine(int m_x, char m_y) {
	point.Set_x(m_x);
	point.Set_y(m_y);
}
void Submarine::Set_Random_y() {
	char abc[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	point.Set_y(abc[rand() % 10 - 1]);
}
void Submarine::Set_Random_x() {
	point.Set_x(rand() % 10 + 1);
}

void Submarine::Random_Point_Submarine() {
	Set_Random_y();
	Set_Random_x();
}
void Submarine::Ask_Set_Submarine() {
	int aux;
	char au;
	cout << "X(1-10): ";
	cin >> aux;
	point.Set_x(aux);

	cout << "Y(A-J): ";
	cin >> au;
	point.Set_y(au);
}
void Submarine::Show_Submarine() {
	point.ShowNavalPoint();
}
void Submarine::transforms_abc_to_ABC(char aux) {
	char ABC[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' }, abc[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	for (int i = 0; i < 10; i++) {
		if (aux == abc[i]) {
			aux = ABC[i];
		}
	}
}
