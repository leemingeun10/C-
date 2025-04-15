#pragma once
class Player
{
private:
	float Xpos, Ypos; 
	float HP, MP; 
	int Gold;

public:
	void move();
	void Attatck();
	


	int getGold();
	void setGOld();
	float getXpos();
	float getYpos();
	float getHP();
	float getMP();
	float setXpos();
	float setYpos();
	float setHP();
	float setMP();



};

