/*
Sanyerlis Camacaro- CSC215 - Sancamac@uat.edu
Final Project: Putting Everything Together with Object Oriented Programming

To Show off Skills learned during this course by creating a program that has humor. 
In this simulation, the player crashed by plane in the Amazonas, and must find
water, food and others suvivors to complete simulation. 
*/

#include <iostream> // includes input and out as the standard library.
#include <string> //this allows me to work with strings.
#include "FindWater.h"//allows to use the prototype function in the find water header file.
#include "FindLife.h"//allows to use the prototype function in the find life header file.
#include "FindFood.h" //allows to use the prototype function in the find food header file

using namespace std;// means using standard namespace and that I dont have to type std:: in front of each line.

// Declaring Global Varibles.
string playerRank; // This is the players rank.
int playersHealth = 1000; //  Variable that holds the player health and it starts at 1000 points.
int& playersScore = playersHealth; // creates a reference. 

// Declares Prototype functions. the pattern for each function is the same!
// return type : Name of functions : (O or more parameters)
string GetUserName(); 
void WelcomeUser(string userName); // declares to display user name in welcome message. 
void DisplayIntro(); // declares to display intro 
void DisplayPlayerRank(); // declares to display player rank = explorer
void DisplayPlayerHealth(); // declares to display player health
void jumbleName(string* const pFirst, string* const pMiddle, string* const pLast); //  declaration, calls jumblename function, constant pointers. 
void unjumbleName(string* const pFirst, string* const pMiddle, string* const pLast); // declaration, calls unjumblename function, constant pointers.
int countLetters(string* const pFirst, string* const pMiddle, string* const pLast); // declaration, calls countletters function, constant pointers.
string firstName; // Gets user input on their first name.
string middleName; // Gets user input on their middle name.
string lastName; // Gets user input on their last name.

int main()// first line of your program, your first instruction.
{
	
	//First we must create objects that we can use from the classes that we made.
	//Sytax is class name and object name that you want to make.
	ClassFindFood objectFindFood; // Class find food.
	ClassFindLife objectFindLife; // Class find life.
	ClassFindWater objectFindWater; // class find water. 

	
	playerRank = "Explorer"; // We are assigning a value to the global var playerRank, "Explorer".
	DisplayIntro(); //Calling the function to display intro.
	string localMainUserName; //Create local varible to hold username.
	localMainUserName = GetUserName();//Get User Name will return a value which we can assign localMainUserName var.
	WelcomeUser(localMainUserName);//Now we can pass a copy of the value localMainUserName to the Welcome User Function.
	DisplayPlayerHealth();//Display health before entering scenario starting with 1000 points. 
	system("pause"); // system pause and need to press any key to continue. 

	// Start the Find water Scenario. Object created from class is placed here.
	int localResultScore = objectFindWater.FindWaterScenario();
	playersHealth = playersHealth + localResultScore;
	DisplayPlayerHealth();//Display health after scenario
	system("pause");// system pause and need to press any key to continue. 
	// Start Find Food Scenario. Object created from class is placed here.
	localResultScore = objectFindFood.FindFoodScenario();
	playersHealth = playersHealth + localResultScore;
	DisplayPlayerHealth();//Display health after scenario
	system("pause");// system pause and need to press any key to continue. 
	// Start Find Intelligent Scenario. Object created from class is placed here.
	localResultScore = objectFindLife.FindIntelligentLifeScenario();
	playersHealth = playersHealth + localResultScore;
	DisplayPlayerHealth();//Display health after scenario
	//Tell the user to exit when they are ready
	cout << "\nWhen you're finished ";
	system("pause");// system pause and need to press any key to continue. 
	//Ends the main function, which also ends our program.
	return 0; // if successful returns value.
}

void DisplayIntro() // body of functions main, calls to displays intro.
{
	cout << "\n\n\n\t                   *** Mission: Survive the Wild ***\n\n"; // title of simulation, first line.
	cout << "\t In this simulation, you are a Survivor that has just survived a plane crash!\n"; // tells user that they are survivors.
	cout << "\t You're in the middle of the Amazonas, and your mission is to find:\n"; // where the mission takes place, amazonas.
	cout << "\t water, food, and a village or others survivors.\n"; // what the user must find to complete mission. 
	DisplayPlayerRank(); // displays player rank, "explorer".
	return; // if succesful returns value. 
}

string GetUserName() // calls to get user input on name. 
{
	cout << "\n What is your player name?"; // asks user for input of  player name. 
	string userName; // This is a local varible.
	/*this is what actually gets the user input
	remember never to use cin with getline in the same program. */
	getline(cin, userName);
	return userName; // returns with name input. 
}

void WelcomeUser(string localUserName) // welcomes user with local string, displays user name and welcome message. 
{
	cout << "\n Welcome Explorer, " + localUserName; // Welcome Explorer, and input name. 
	cout << "\nPlease enter your First name: "; // line that ask user for their first name.
	cin >> firstName; // user enter first name in this line.
	cout << "Please enter your Middle name: "; // line that ask user for their middle name.
	cin >> middleName; // user enter middle name in this line.
	cout << "Please enter your Last name: "; // line that ask user for their last name.
	cin >> lastName; // user enter last name in this line.

	jumbleName(&firstName, &middleName, &lastName);// Calls the jumbleName function.
	cout << "\n\nHello, " << firstName << " " << middleName << " " << lastName << "!\n"; // greats user by full name. 

	cout << "oOpss... I think I got your name wrong...\n"; // tells users that got their name wrong.
	cout << "I definitely meant to say "; // apologizes to users and displays the right name. 

	unjumbleName(&firstName, &middleName, &lastName);// Calls the unjumbleName function.
	cout << firstName << " " << middleName << " " << lastName << ".\n\n"; // displays user full name in order. 

	cout << "I apologize about the name confusion...\n"; // apologizes to user about the name confusion. 
	cout << "Just to make it up to you, I'll count the total letters in your full name.\n"; // tells users that it will count letters of full name.

	cout << "You have " << countLetters(&firstName, &middleName, &lastName) << " letters in your full name!\n\n";// Calls the countLetters function.
}
// Functions
// jumbleName will disorganize the full name entered by the user originally.
void jumbleName(string* const pFirst, string* const pMiddle, string* const pLast)
{
	string temp = *pFirst; // Store value pointed to by pFirst in temp.
	*pFirst = *pMiddle; // Store value pointed to by pMiddle in address pointed to by pFirst.
	*pMiddle = *pLast; // Store value originally pointed to by pLast in address pointed to by pMiddle.
	*pLast = temp;// Stores value originally pointed to by pLast in address pointed to temp.
}

// unjumbleName will reorganize the full name as the user originally input.
void unjumbleName(string* const pFirst, string* const pMiddle, string* const pLast)
{
	string temp = *pMiddle; // Store value pointed to by pMiddle in temp.
	*pMiddle = *pFirst; // Store value pointed to by pFirst in address pointed to by pMiddle.
	*pFirst = *pLast; // Store value originally pointed to by pLast in address pointed to by pFirst.
	*pLast = temp; // Store value orignally pointed to by pLast in address pointed to temp.
}

// countLetters will count the total amount of letters in the users name.
int countLetters(string* const pFirst, string* const pMiddle, string* const pLast)
{
	// Add together the size of all the pointers and returns the int letterCount.
	int letterCount = pFirst->size() + pMiddle->size() + pLast->size();

	return letterCount; //  if successful returns value to letterCount. 
}
void DisplayPlayerHealth() // displays player health at the beginning of simulation. 
{
	cout << "\n Your Current Player Health is " << playersHealth << endl; // displays player initial health. 
	cout << "\n Your Current Player Score is " << playersScore << endl; // displays player initial score, which is the reference.
	return; // if succesful returns value.
}

void DisplayPlayerRank() // displays player rank "explorer".
{
	cout << "\n Your Current Rank is " + playerRank << endl; // displays rank "Explorer" before user enters name. 
}