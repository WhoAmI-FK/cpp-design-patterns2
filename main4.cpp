#include "AbstractFactory.h";
/*
int main()
{
	afactory::CarFactory* CarPlant;
	int choice;
	std::cout << "Select a car type: " << std::endl;
	std::cout << "1: Gasoline " << std::endl;
	std::cout << "2: Electric " << std::endl;
	std::cout << "Selection: ";
	std::cin >> choice;
	
	switch (choice)
	{
	case 1:
		CarPlant = new afactory::GasCarFactory;
		break;
	case 2:
		CarPlant = new afactory::ElectricCarFactory;
		break;
	default:
		std::cout << "Invalid Selection" << std::endl;
		CarPlant = nullptr;
	}

	if (CarPlant != nullptr) {
		afactory::Door* myDoor = CarPlant->BuildDoor();
		afactory::Engine* myEngine = CarPlant->BuildEngine();
		myDoor->Open();
		myEngine->Run();
	}

	return 0;
}
*/