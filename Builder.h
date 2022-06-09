#pragma once
#include <iostream>

namespace builder {
	class Entree 
	{
	protected:
		char _entree[10];
	public:
		const char* getEntree() const {
			return _entree;
		}

	};
	

	class Burger : public Entree 
	{
	public:
		Burger()
		{
			std::cout << "\nGrill Burger patty, add tomatoes and place them in a bun\n";
			strcpy_s(_entree, "hotdog");
		}
	};

	class Hotdog : public Entree
	{
	public:
		Hotdog()
		{
			std::cout << "\n Cook sausage and place it in a bun";
			strcpy_s(_entree, "hotdog");
		}
	};

	class Side
	{
	protected:
		char _side[10];
	public:
		const char* getSide() const {
			return _side;
		}
	};
	class Fries : public Side
	{
	public:
		Fries() {
			std::cout << "\n Fry and season potatoes" << std::endl;
			strcpy_s(_side,"fries");
		}
	};

	class Salad : public Side 
	{
	public:
		Salad()
		{
			std::cout << "\nToss greens and dressing together" << std::endl;
			strcpy_s(_side, "salad");
		}
	};
	class Drink
	{
	protected:
		char _drink[10];
	public:
		Drink()
		{
			std::cout << "\nFill cup with soda" << std::endl;
			strcpy_s(_drink, "soda");
		}
		const char* getDrink() const {
			return _drink;
		}
	};

	class MealCombo
	{
	private:
		Entree* entree;
		Side* side;
		Drink* drink;
		char _bag[100];
	public:
		MealCombo(const char* type)
		{
			sprintf_s(_bag, "\n %s meal combo:", type);
		}
		void setEntree(Entree* e)
		{
			entree = e;
		}
		void setSide(Side* s)
		{
			side = s;
		}
		void setDrink(Drink* d)
		{
			drink = d;
		}
		const char* openMealBag() {
			sprintf_s(_bag, "%s, %s, %s, %s", _bag, entree->getEntree(), side->getSide(), drink->getDrink());
			return _bag;
		}
	};

	class MealBuilder {
	protected:
		MealCombo* _meal;
	public:
		virtual void cookEntree()
		{

		}
		virtual void cookSide() {

		}
		virtual void fillDrink()
		{

		}
		MealCombo* getMeal() const 
		{
			return _meal;
		}
	};
	class BurgerMeal : public MealBuilder 
	{
	public:
		BurgerMeal()
		{
			_meal = new MealCombo("Burger");
		}
		void cookEntree() override {
			Burger* burger = new Burger();
			_meal->setEntree(burger);
		}
		void cookSide() override
		{
			Fries* fries = new Fries();
			_meal->setSide(fries);
		}
		void fillDrink() override
		{
			Drink* drink = new Drink();
			_meal->setDrink(drink);
		}
	};
	class HotdogMeal : public MealBuilder
	{
	public:
		HotdogMeal()
		{
			_meal = new MealCombo("Hotdog");
		}
		void cookEntree() override
		{
			Hotdog* hotdog = new Hotdog;
			_meal->setEntree(hotdog);
		}
		void cookSide() override
		{
			Salad* caesar = new Salad;
			_meal->setSide(caesar);
		}
		void fillDrink() override
		{
			Drink* drink = new Drink;
			_meal->setDrink(drink);
		}
	};
}