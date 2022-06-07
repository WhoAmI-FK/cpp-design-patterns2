#pragma once
#include <iostream>

namespace factory {
	
	class Coffee {
	protected:
		char _type[15];
	public:
		Coffee()
		{

		}

		char* getType() 
		{
			return _type;
		}
	};

	class Espresso : public Coffee {
	public:
		Espresso() : Coffee()
		{
			strcpy_s(_type, "Espresso");
			std::cout << "\nMaking a cup of espresso" << std::endl;
			std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
		}

	};
	class Cappuccino : public Coffee
	{
	public:
		Cappuccino() : Coffee()
		{
			strcpy_s(_type, "Cappuccino");
			std::cout << "\nMaking a cup of cappuccino" << std::endl;
			std::cout << "Grind and brew one scoop of espresso beans" << std::endl;
			std::cout << "Heat and foam milk." << std::endl;
		}
	};

	class CoffeeMakerFactory 
	{
	private:
	//	Coffee* _coffee;
	public:
		Coffee* getCoffee() {
			int choice;
			std::cout << "Select type of coffee to make: " << std::endl;
			std::cout << "1: Espresso " << std::endl;
			std::cout << "2: Cappuccino " << std::endl;
			std::cout << "Selection: ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				return new Espresso();
			case 2:
				return new Cappuccino();
			default:
				std::cout << "Invalid Selection" << std::endl;
				return nullptr;
			}
		}
	};
};