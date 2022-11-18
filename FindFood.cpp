#include <iostream>//this allows input and output.
#include <string> //this allows me to work with strings.
#include "FindFood.h" //allows me to use the prototype function in the find food header file

using namespace std;// means using standard namespace and that I dont have to type std:: in front of each line.

//Find food scenario requires player to make the correct choice to find a food source to survive on the amazonas.
int ClassFindFood::FindFoodScenario()
{
	int pointsResults = 0;// This will be the number of health points higher or lower to add/sub to health.
	cout << "\n\nYou have successfully found water, and are starting to get hungry."; // food scenario.
	cout << "\nWhen you got water, you recall seeing a route running North to South.\n\n"; // food scenario.
	cout << "\nTo the North you hear animals, and to the South you see a grove of trees.\n"; // food scenario.
	cout << "\nWhich way would you like to go? (N or S) "; // ask user which way they want to go. 
	string localPlayerChoice; // strings user answer.
	getline(cin, localPlayerChoice);
	//calculate points based on decision
	if (localPlayerChoice == "N")// creates the option of N.
	{
		cout << "\nYou have chosen poorly, and encountered a mountain lion, he bites you, and you lose 50 health points.\n";
		pointsResults = -50;// if user chooses poorly, looses -50.
		// return -50;
	}
	else if (localPlayerChoice == "S")// creates the option of S.
	{
		cout << "\nYou have chosen wisely, and find fresh fruit, this gives you an increase of 100 health points.\n";
		pointsResults = 100;// if user chooses wisely gains 100 points.
		// return 100;
	}
	else
	{
		cout << "\nYou are not making clear choices, and are walking in circles causing you to lose 10 health points to hunger.\n";
		pointsResults = -10;
		// return -10;
	}
	return pointsResults;// if successful returns to Points Results. 
}