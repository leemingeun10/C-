#pragma once
class SoccerPlayer
{
public:
	int Tall, Weight, DEfStat, AttackStat,Speed;
	int xpos, ypos, zpos;
	int position;
	bool IsHaveBall;
	int card;
	int BackNum;
	float HP;
	bool IsHurt;


	void MoveMent();
	void MakeTurn();
	


	void DoPass();
	void DoCross();
	void DoShoot();
	void DoMistake();
	void DoCatch();
	void DoDefense();	
	void DoTacckle();
	void DoDribble();
	void DoSave();
	void GetLoseBall();
	void GetPass();

	void DoThrowIn();
	

};

