#include"game.h"

using namespace std;

Game::Game(){
	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "Bkumar";
	players[10] = "Ishant";

}

void Game::Welcome(){
	cout<<"\t __________________________________"<<endl;
	cout<<"\t |          _______                |"<<endl;
	cout<<"\t |----------CRIC-IN-- -------------|"<<endl;
	cout<<"\t |          _______                |"<<endl;
	cout<<"\t | Welcome to Virtual Cricket Game |"<<endl;
	cout<<"\t |_________________________________|"<<endl<<endl;

	cout<<"_____________________________________________________"<<endl;
	cout<<"|                    ____________                    |"<<endl;
	cout<<"|--------------------INSTRUCTIONS--------------------|"<<endl;
	cout<<"|____________________________________________________|"<<endl;
	cout<<"|                                                    |"<<endl;
	cout<<"| 1. Create 2 teams (Team-A and Team-B with 4        |"<<endl;
	cout<<"|    players each) from a given pool of 11 players.  |"<<endl;
	cout<<"| 2. Lead the toss and decide the choice of play.    |"<<endl;
	cout<<"| 3. Each innings will be of 6 balls.                |"<<endl;
	cout<<"|____________________________________________________|"<<endl<<endl<<endl;
}

void Game::GetPlayerNames(){
	cout<<"   ______________________________________"<<endl;
	cout<<"   |                                     |"<<endl;
	cout<<"   |-----Here are the Players :----------| "<<endl;
	cout<<"   |_____________________________________|"<<endl<<endl;
	for(int i=0; i<totalPlayers; i++){
		cout<<"\t"<<i<<" "<<players[i]<<endl;
	}
}

int Game::takeIntegerInput(){

	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Invalid input, please try again :( "<<endl;
	}
	return n;
}

bool Game::validateSelectedPlayer(int index){

	vector<Player> players;
	players = teamA.players;

	int n = players.size();


	for(int i=0; i<n; i++){
		if(players[i].id == index){
			return false;
		}
	}

	players = teamB.players;
	n = players.size();


	for(int i=0; i<n; i++){
		if(players[i].id == index){
			return false;
		}
	}
	return true;

}

void Game::selectPlayers(){
	cout<<"\t ---------------------"<<endl;
	cout<<"\t | Create both teams |"<<endl;
	cout<<"\t ---------------------"<<endl;

	for(int i=0; i<playersPerTeam; i++){
		//add to team A

		cout<<endl<<"Select player "<<i+1<<" of team A: ";

		int playerIndexTeamA = takeIntegerInput();

		while(playerIndexTeamA<0 || playerIndexTeamA>10 || !(validateSelectedPlayer(playerIndexTeamA)))
		{
			cout<<"Please enter valid index value";
			cout<<endl<<"Select player "<<i+1<<" of team A: ";
			playerIndexTeamA = takeIntegerInput();
		}

			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);



		//add to team B
		cout<<endl<<"Select player "<<i+1<<" of team B: ";

		int playerIndexTeamB = takeIntegerInput();

		while(playerIndexTeamB<0 || playerIndexTeamB>10 || !(validateSelectedPlayer(playerIndexTeamB)))
		{
			cout<<"Please enter valid index value";
			cout<<endl<<"Select player "<<i+1<<" of team B: ";
			playerIndexTeamB = takeIntegerInput();
		}

			Player teamBPlayer;
			teamBPlayer.id = playerIndexTeamB;
			teamBPlayer.name = players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);

	}
}

void Game::displayTeamPlayers(){

	cout<<endl<<"\t----------------   |   ------------------"<<endl;
	cout<<"\t Team A players"<<"\t    \t   Team B players"<<endl;
	cout<<"\t----------------   |   ------------------"<<endl;
	for(int i=0; i<4; i++){
		cout<<"\t   "<<i+1<<" - "<<teamA.players[i].name<<"\t   |  \t "<<i+1<<" - "<<teamB.players[i].name<<endl;
	}
	cout<<"\t ----------------------------------------"<<endl;

}

void Game::inningsToss(){

	cout<<"\t --------------------"<<endl;
	cout<<"\t | Tossing the coin |"<<endl;
	cout<<"\t --------------------"<<endl;

	usleep(3000000);

	srand(time(0));
	int x = rand()%2;

	switch(x){
		case(0):
			cout<<endl<<"| * Team A has won the Toss * |"<<endl<<endl;
			tossChoice(teamA);
			break;
		case(1):
			cout<<endl<<"| * Team B has won the Toss * |"<<endl<<endl;
			tossChoice(teamB);
			break;
	}
}

void Game::tossChoice(Team tossWinnerTeam){

	cout<<"Enter 1 to bat and 2 to bowl first "<<endl
	    <<"1. Bat"<<endl
	    <<"2. Bowl"<<endl;

	int tossInput = takeIntegerInput();

	fflush(stdin);

	switch(tossInput){
		case 1:
			cout<< endl << tossWinnerTeam.name <<" won the toss and chose to bat first" <<endl<<endl;
			if(tossWinnerTeam.name.compare("Team-A")==0){
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else{
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;
		case 2:
			cout<< endl << tossWinnerTeam.name <<" won the toss and chose to bowl first" <<endl<<endl;
			if(tossWinnerTeam.name.compare("Team-A")==0){
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			}
			else{
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}
			break;
		default:
			cout<<"Invalid input, please try again :("<< endl;
			tossChoice(tossWinnerTeam);
			break;

	}

}

void Game::startFirstInnings(){

	cout<<"\t\t ---------|| First Innings Starts ||--------" << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers(){

	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout<<battingTeam->name<<" - "<<batsman->name<<" is batting"<< endl;
	cout<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling"<< endl << endl;

}

void Game::playInnings(){

	for(int i=0; i<maxBalls; i++){

		fflush(stdout);
		cout<<"Press Enter to bowl...";
		fflush(stdin);
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		cout<<"Bowling..."<<endl;
		usleep(1000000);
		bat();

		showGameScoreCard();

		if(!validateInningsScore()){
			break;
		}
	}
}

void Game::bat(){
	srand(time(0));
	int runsScored = rand()%7;
//	int runsScored = 0;

	//update batting team and batsman score
	batsman->runsScored += runsScored;
	battingTeam->totalRunScored += runsScored;
	batsman->ballsPlayed += 1;

	//update batting team and batsman score
	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled += 1;
	bowler->runsGiven += runsScored;

	//usleep(2000000);

	if( runsScored != 0){
		cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" <<endl <<endl;
	}
	else{
		cout << endl << bowler->name << " to " << batsman->name << " OUT!! "<<endl <<endl;
		battingTeam->wicketsLost += 1;
		bowler->wicketsTaken += 1;


		//int nextPlayerIndex = battingTeam->wicketsLost;
		if(battingTeam->wicketsLost < 4){
			batsman = &battingTeam->players[battingTeam->wicketsLost];
		}
		else{
			if(!isFirstInnings){
				return;
			}

		}

		if(battingTeam->wicketsLost<playersPerTeam){
			cout<<"Player batting now is "<<batsman->name<<endl;
			}
		}
}

bool Game::validateInningsScore(){

	if(isFirstInnings){

		if((battingTeam->wicketsLost == playersPerTeam) || bowlingTeam->totalBallsBowled == maxBalls){

			cout<<endl<<"\t || First Innings ends ||"<<endl<<endl;

			cout<< battingTeam->name << " " << battingTeam->totalRunScored << " - " <<battingTeam->wicketsLost
					<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;

			cout<< bowlingTeam->name << " needs " << battingTeam->totalRunScored+1
				<< " runs to win the match" <<endl <<endl;
			return false;
		}
	}
	else{

		if(battingTeam->totalRunScored > bowlingTeam->totalRunScored){

			cout<<endl<<"\t || Second Innings ends ||"<<endl<<endl;

			cout<<"-----------------------------------------------"<<endl;
			cout<<"|  "<<battingTeam->name<<" has won the match   |"<<endl;
			cout<<"-----------------------------------------------"<<endl;

			return false;
		}
		else if(battingTeam->totalRunScored == bowlingTeam->totalRunScored && bowlingTeam->totalBallsBowled == maxBalls){

			cout<<endl<<"\t || Second Innings Ends ||" <<endl <<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"\t It is a tie.... \t |"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			return false;
		}
		else if( battingTeam->wicketsLost==playersPerTeam && bowlingTeam->wicketsLost==playersPerTeam){

			cout<<endl<<"\t || Second Innings Ends ||" <<endl <<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"\t It is a tie.... \t |"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			return false;
		}
		else if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){

			cout<<endl<<"\t || Second Innings ends ||"<<endl<<endl;

			cout<<"-----------------------------------------------"<<endl;
			cout<<"| "<<bowlingTeam->name<<" has won the match    |" << endl;
			cout<<"-----------------------------------------------"<<endl;
			return false;

		}

	}
	return true;
}

void Game::showGameScoreCard(){
	cout<<"\t ---------------------------------------------------------"<<endl;

	cout<<"\t "<<battingTeam->name<<"       "<< battingTeam->totalRunScored <<" - "<<battingTeam->wicketsLost<<"("<<bowlingTeam->totalBallsBowled<< ")"
		<<" | "<<batsman->name<<" "<<batsman->runsScored<<"  ("<<batsman->ballsPlayed<<")"
		<<"\t "<< bowler->name <<" "<<bowler->ballsBowled <<" "<< bowler->runsGiven << " "<< bowler->wicketsTaken<<endl;

	cout<<"\t ---------------------------------------------------------"<<endl;
}

void Game::startSecondInnings(){

	cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
	cout<<"\t\t ---------|| Second Innings Starts ||--------" << endl << endl;

	Team *temp;
	temp = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = temp;

	isFirstInnings = false;

	initializePlayers();
	playInnings();

}

void Game::matchSummary(){

	cout<<endl<<"\t \t || MATCH ENDS ||"<<endl<<endl;

	cout<<"Team A "<<teamA.totalRunScored<<" - "<<teamA.wicketsLost<<"  ("<<teamB.totalBallsBowled<<")"<<endl;

	cout<<"================================================================"<<endl;

	cout<<"| PLAYER \t BATTING \t BOWLING |"<<endl;
	cout<<"-----------------------------------------"<<endl;
	for(int i=0; i<playersPerTeam; i++){
		cout<<teamA.players[i].id<<" "<<teamA.players[i].name<<" \t "<<teamA.players[i].runsScored<<"("<<teamA.players[i].ballsPlayed<<")"
				<<" \t "<<teamA.players[i].ballsBowled<<" - "<<teamA.players[i].runsGiven<<" - "<<teamA.players[i].wicketsTaken<<"   |"<<endl;
		cout<<" ----------------------------------------------------- "<<endl;
	}

	cout<<endl;

	cout<<endl<<endl<<"Team B "<<teamB.totalRunScored<<" - "<<teamB.wicketsLost<<"  ("<<teamA.totalBallsBowled<<")"<<endl;
	cout<<"| PLAYER \t BATTING \t BOWLING |"<<endl;
	cout<<"-----------------------------------------"<<endl;
	for(int i=0; i<playersPerTeam; i++){
		cout<<teamB.players[i].id<<" "<<teamB.players[i].name<<" \t "<<teamB.players[i].runsScored<<"("<<teamB.players[i].ballsPlayed<<")"
				<<" \t "<<teamB.players[i].ballsBowled<<" - "<<teamB.players[i].runsGiven<<" - "<<teamB.players[i].wicketsTaken<<"   |"<<endl;
		cout<<" ----------------------------------------------------- "<<endl;
	}
	cout<<"================================================================"<<endl;
}
