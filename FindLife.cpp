#include <iostream> //this allows input and output.
#include <string> //this allows me to work with strings.
#include "FindLife.h" //allows me to use the prototype function in the find life header file.

using namespace std;// means using standard namespace and that I dont have to type std:: in front of each line.



int ClassFindLife::FindIntelligentLifeScenario()//Find intelligent life scenario requires player to fulfill his duties to find shelter.
{
	int pointsResults = 0;// This will be the number of health points higher or lower to add/sub to health.
	cout << "\n\nYou are now seeking for shelter, and hope to find somewhere to sleep before sunset. "; // shelter scenario.
	cout << "\nYou really hope to find others survivors or a village. \n\n";// shelter scenario.
	cout << "\n You start to hear voices North West, and you see smoke from a camp fire South East.";// shelter scenario.
	cout << "\nWhich way do you want to explore the NW or SE?\n"; // asks user to input which way to go.
	string localPlayerChoice; // strings user answer.
	getline(cin, localPlayerChoice);
	//calculate points based on decision
	if (localPlayerChoice == "NW")// creates the option of NW.
	{
		cout << "\nYou have chosen poorly, you found plane survivors, and now you're all lost, causing you to lose 1000 health points.\n";
		pointsResults = -1000;// if user chooses poorly, looses -1000.
		// return -1000;
	}
	else if (localPlayerChoice == "SE")// creates the option of SE.
	{
		cout << "\nYou have chosen wisely, you found a village and survived, gaining 1000 health points.\n";
		pointsResults = 1000; // if user chooses wisely gains 1000points.
		// return 1000;
	}
	else
	{
		cout << "\nYou are not making clear choices, and are walking in circles causing you to lose 500 health points to failure to find shelter.\n";
		pointsResults = -500;// if user types wrong input, looses 500 points. 
		// return -500;
	}
	return pointsResults;// if successful returns to Points Results. 
}