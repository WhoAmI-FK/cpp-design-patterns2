#include "Builder.h"

int main()
{
	using namespace std;
	using namespace builder;
	MealBuilder* cook = new MealBuilder;
	MealCombo* meal;
	int choice;

	// Prompt user for their meal choice
	cout << "Select a meal: " << endl;
	cout << "1: Hamburger Meal" << endl;
	cout << "2: Hotdog Meal" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

	// Instantiate the appropriate builder based on user input
	switch (choice)
	{
	case 1:
		cook = new BurgerMeal;
		break;
	case 2:
		cook = new HotdogMeal;
		break;
	default:
		cout << "Invalid Selection" << endl;
		cook = NULL;
		break;
	}

	cout << "Making selected meal" << endl;

	// Build the complex object
	cook->cookEntree();
	cook->cookSide();
	cook->fillDrink();
	meal = cook->getMeal();
	cout << meal->openMealBag() << endl;
	return 0;
}