#pragma once
#include "Team.h"
class GameManager
{

	float time;
	int scoreA, ScoreB;
	Team TeamAName, TeamBName;
	float restartXpos, restartYpos;


	void DefineWinner();
	void StopGame();
	void StartGame();
	void RestartGame();
	void CheckPosition();
};

