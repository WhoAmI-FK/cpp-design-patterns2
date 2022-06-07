#pragma once
#include <iostream>
namespace afactory {
	using namespace std;
	class Door
	{
	public:
		Door()
		{
		}
		virtual void Open() = 0;
	};

	class GasCarDoor : public Door
	{
	public:
		GasCarDoor()
		{
			cout << "Making a door for a gas car." << endl;
		}
		void Open() override
		{
			cout << "click" << endl;
		}
	};

	class ElectricCarDoor : public Door
	{
	public:
		ElectricCarDoor()
		{
			cout << "Making a door for an electric car" << endl;
		}
		void Open() override
		{
			cout << "shhhhh" << endl;
		}
	};

	//Engine objects
	class Engine
	{
	protected:
		char _sound[15];
	public:
		Engine()
		{
			strcpy_s(_sound, "");
		}
		virtual void Run() = 0;
	};

	class GasEngine : public Engine
	{
	public:
		GasEngine()
		{
			strcpy_s(_sound, "vroom");
			cout << "Making a gas engine." << endl;
		}
		void Run() override
		{
			cout << _sound << endl;
		}
	};

	class ElectricEngine : public Engine
	{
	public:
		ElectricEngine()
		{
			strcpy_s(_sound, "SHHHH");
			cout << "Making an electric engine." << endl;
		}
		void Run() override
		{
			cout << _sound << endl;
		}
	};

	class CarFactory
	{
	public:
		virtual Door* BuildDoor() = 0;
		virtual Engine* BuildEngine() = 0;

	};
	class GasCarFactory : public CarFactory 
	{
	public:
		Door* BuildDoor() override
		{
			return new GasCarDoor();
		}
		Engine* BuildEngine() override
		{
			return new GasEngine();
		}
	};
	class ElectricCarFactory : public CarFactory
	{
	public:
		Door* BuildDoor() override
		{
			return new ElectricCarDoor();
		}
		Engine* BuildEngine() override
		{
			return new ElectricEngine();
		}
	};
}