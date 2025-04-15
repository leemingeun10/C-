#pragma once
class Monster
{
private:
	float Xpos, Ypos;
public:
	void Attack();
	void Move();

	float GetXpos();
	float GetYpos();
	float SetXpos();
	float SetYpos();
};

