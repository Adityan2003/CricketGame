#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream oFile;
	oFile.open("msg.txt");

	oFile << "Hi! \n";

	oFile << "Your training ends ";
	oFile << "but the journey begins";
	oFile << "All the best.";
	oFile.close();

	string str;
	ifstream iFile;
	iFile.open("msg.txt");

	int count = 0;

	while(!iFile.eof()) {
	count++;
	getline(iFile, str);
	cout << str << endl;

	cout << "count: "<< count << endl;

	iFile.close();
	}
}
// Line 1

// Line 2
