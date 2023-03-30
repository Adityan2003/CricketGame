#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<unistd.h>
#include"team.h"

class Game{

	public:
		Game();

		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;

		void Welcome();
		void GetPlayerNames();
		int takeIntegerInput();
		void selectPlayers();
		bool validateSelectedPlayer(int);
		void displayTeamPlayers();
		void inningsToss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScoreCard();

		void startSecondInnings();

		void matchSummary();
};

