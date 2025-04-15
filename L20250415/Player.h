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
	


	int GetGold();
	void SetGOld();
	float GetXpos();
	float GetYpos();
	float GetHP();
	float GetMP();
	float SetXpos();
	float SetYpos();
	float SetHP();
	float SetMP();



};

