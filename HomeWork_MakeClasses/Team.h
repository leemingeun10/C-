#pragma once
#include"SoccerPlayer.h"
class Team
{	
	SoccerPlayer Starting[11];
	SoccerPlayer Backup[13];
	int ChanceToChange;
	int tactics;

	void ChangePlayer();
	void Changetactics();
};

