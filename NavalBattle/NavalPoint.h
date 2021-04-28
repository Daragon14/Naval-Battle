#pragma once
class NavalPoint
{
private:
	int x; //1 -- 10
	char y; //A -- J
public:
	NavalPoint(int m_x, char m_y);
	NavalPoint();
	NavalPoint(int m_x, int m_y);
	virtual ~NavalPoint();

	void Set_x(int m_x) { x = m_x;}
	void Set_y(int m_y) { y = m_y;}
	void Set_y(char m_y) { y = m_y;}
	void Set_NP(int m_x, char m_y);
	void Set_NP(NavalPoint NP);

	int Get_x(void) const { return x; }
	char Get_y(void) const { return y; }
	int Get_int_y(char m_y) const;

	void Ask2Set_NP(void);
	bool IsValid(void);
	void ShowNavalPoint(void);

	bool operator == (const NavalPoint p) const;
	bool operator != (const NavalPoint p) const;
	void operator = (NavalPoint p);
	

};

