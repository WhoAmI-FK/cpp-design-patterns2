#include "AbstractFactoryTerminal.h"


int func()
{
	using namespace aterminal;
	using std::cout;
	using std::cin;
	using std::endl;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 30);

	ThemeFactory* app;
	int choice;

	cout << "Select a theme: " << endl;
	cout << "1: Light" << endl;
	cout << "2: Dark" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

	// Initiate the correct factory based on user input
	switch (choice)
	{
	case 1:
		app = new LightFactory;
		break;
	case 2:
		app = new DarkFactory;
		break;
	default:
		cout << "Invalid Selection" << endl;
		app = NULL;
		break;
	}

	// Get the correct objects based on factory selected
	if (app != NULL)
	{
		Background* appBkgd = app->setBackground(hConsole);
		Text* appDefaultText = app->getDefaultText(hConsole);
		Text* appGreenText = app->getGreenText(hConsole);

		appDefaultText->message(hConsole);
		appGreenText->message(hConsole);
	}

	cout << endl;
	system("pause");

	return 0;
}