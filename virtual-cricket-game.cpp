
#include "game.h"
using namespace std;

int main() {

	Game game1;
	game1.Welcome();

	cout<<endl<<"Press enter to continue..."<<endl;
	getchar();

	game1.GetPlayerNames();

	cout<<endl<<"Press enter to continue..."<<endl;
	getchar();

	game1.selectPlayers();
	game1.displayTeamPlayers();

	cout<<endl<<"Press enter to Toss the Coin.."<<endl;
	fflush(stdin);
	getchar();

	game1.inningsToss();

	game1.startFirstInnings();

	game1.startSecondInnings();

	game1.matchSummary();

	return 0;
}
