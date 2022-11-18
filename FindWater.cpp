#include <iostream> //this allows input and output.
#include <string> //this allows me to work with strings.
#include "FindWater.h" //allows me to use the prototype function in the find water header file.


using namespace std;// means using standard namespace and that I dont have to type std:: in front of each line.

//Find fresh water scenario requires player to make the correct choice to find fresh water to survive on the amazonas.
int ClassFindWater::FindWaterScenario()
{
	int pointsResults = 0;// This will be the number of health points higher or lower to add/sub to health.
	cout << "\n\nAfter surviving a plane crash, you wake up in the middle of the Amazonas."; // water scenerio. 
	cout << "\nYou are inside the plane, and notice the plane is empty with no one around. ";// water scenerio. 
	cout << "\nYou start getting thirsty, but your water maker is broke.You need to find ";// water scenerio. 
	cout << "\nfresh water fast or you will perish.\n\n";// water scenerio. 
	cout << "\nAfter exiting the plane, to the West you hear the wind, and to the East you hear water splashing from a waterfall.\n";// water scenerio. 
	cout << "\nWhich way would you like to go? (W or E) "; // user needs to choose if W or E.
	string localPlayerChoice; // string the choice of the player.
	getline(cin, localPlayerChoice);
	//calculate points based on decision
	if (localPlayerChoice == "W") // creates the option of W.
	{
		cout << "\nYou have chosen poorly and get hit by lightning and lose 25 health points.\n";
		pointsResults = -25; // if user chooses poorly, looses -25.
		// return -25;
	}
	else if (localPlayerChoice == "E") // creates the option of E.
	{
		cout << "\nYou have chosen wisely and find water and this gives you an increase of 25 health points.\n";
		pointsResults = 25; // if user chooses wisely gains 25 points. 
		// return 25;
	}
	else
	{
		cout << "\nYou are not making clear choices, and are walking in circles causing you to lose 10 health points to thirst.\n";
		pointsResults = -10; // if user types wrong input, looses 10 points. 
		// return -10;
	}
	return pointsResults; // if successful returns to Points Results. 
}