#include <iostream>
#include <string>
using namespace std;

const int maxGames = 15;
const int dataFields = 5;

//Function declarations
void addGame();
void viewLibrary();
void updateGame();
void deleteGame();

//Global variables
int gameCount = 0;
string gameAttributes[maxGames][dataFields];

int main()
{
	int choice;
	
	while (gameCount <= maxGames)
	{	
		cout << "1. Add game to library.\n";
		cout << "2. View games in library.\n";
		cout << "3. Update game in library.\n";
		cout << "4. Delete game to library.\n";
		cout << "5. Exit\n";
		
		cout << "\nChoose what you want to do: ";
		cin >> choice;
 	
		switch(choice)
		{
			case 1:
				addGame();
				break;
			case 2:
				viewLibrary();
				break;
			case 3:
				updateGame();
				break;
			case 4:
			    deleteGame();
			    break;
			case 5:
				return(0);
				break;
			default:
				cout << "Please choose a valid option!";
		}
	}
	return 0;
}

void addGame() 
{
	cin.ignore();
		
	if (gameCount < maxGames)
	{
		cout << "\nEnter Game ID: ";
		getline(cin, gameAttributes[gameCount][0]);
		
		cout << "Enter Game Name: ";
		getline(cin, gameAttributes[gameCount][1]);
		
		cout << "Enter Platform(Mobile, Console, PC,etc.): ";
		getline(cin, gameAttributes[gameCount][2]);
		
		cout << "Enter Name of Developer: ";
		getline(cin, gameAttributes[gameCount][3]);
		
		cout << "Enter the Year of Release: ";
		getline(cin, gameAttributes[gameCount][4]);
		
		cout << "\nGame has been added to your library!\n" << " \n";
		gameCount++;
	} else {
		cout << "\nYour library is full! \n" << " \n";
	}
}

void viewLibrary()
{
		cout << "\nHere are the games on your library: \n" << " \n";
	
	for (int i = 0; i < gameCount; i++)
	{
		cout << "Game ID: " << gameAttributes[i][0]
		<< "\nName: " << gameAttributes[i][1] 
		<< "\nPlatform: " << gameAttributes[i][2]
		<< "\nDeveloper: " << gameAttributes[i][3]
		<< "\nYear Released: " << gameAttributes[i][4] << endl << " \n";
	}
	
	cout << "Game(s) in library: " << gameCount << endl << " \n";
}

void updateGame()
{
	string gameID;
	bool gameFound = false;
	cin.ignore();
	
	cout << "\nEnter the ID of the game you want to update: ";
	getline(cin, gameID);
	
	for (int i = 0; i < gameCount; i++)
	{
		if (gameID == gameAttributes[i][0])
		{
			gameFound = true;
			
			cout << "Enter Game Name: ";
			getline(cin, gameAttributes[i][1]);
			
			cout << "Enter Platform(Mobile, Console, PC,etc.): ";
			getline(cin, gameAttributes[i][2]);
		
			cout << "Enter Name of Developer: ";
			getline(cin, gameAttributes[i][3]);
		
			cout << "Enter the Year of Release: ";
			getline(cin, gameAttributes[i][4]);
			
			cout << "\nGame has been updated from your library!\n" << " \n";
		}
	}
	
	if (!gameFound)
	{
		cout << "\nGame ID not found in the library! \n" << " \n";
	}
}

void deleteGame()
{
    string gameID;
    bool gameFound = false;
    cin.ignore();
    
	cout << "\nEnter the ID of the game you want to delete: ";
	getline(cin, gameID);
	
	for (int i = 0; i < gameCount; i++)
	{
	    if (gameID == gameAttributes[i][0])
	    {
	       gameFound = true;
	       	
	        for (int j = i; j < gameCount - 1; j++)
	        {
	            for (int k = 0; k < dataFields; k++)
	            {
	               gameAttributes[j][k] = gameAttributes[j + 1][k];
	            }
	        }
	        cout << "\nGame successfully deleted from your library! \n" << " \n";
	        gameCount--;
	        break;
	    }
	}
	
	if (!gameFound)
	{
	    cout << "\nGame ID not found in the library! \n" << " \n";
	}
}
