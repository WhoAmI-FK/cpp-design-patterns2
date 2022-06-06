#pragma once
#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <string.h>

namespace proto {

	class Animal
	{
	protected:
		char _hairColor[10];
		int _hairLength, _tail, _weight, _height, _age;
		int _intelligence, _stubbornness, _agressiveness;

	public:
		virtual Animal* clone() = 0;

		int setHairLength(int length)
		{
			_hairLength = length;
		}

		void setHairColor(const char* color)
		{
			strcpy_s(_hairColor, color);
		}

		void setTail(int length)
		{
			_tail = length;
		}

		void setWeight(int kg)
		{
			_weight = kg;
		}

		void setHeight(int m)
		{
			_height = m;
		}

		void setAge(int age)
		{
			_age = age;
		}

	};

	class Sheep : public Animal
	{
	public:
		Sheep()
		{
			_hairLength = 5;
			_stubbornness = 3;
			_agressiveness = 2;
			_intelligence = 7;
		}
		Sheep* clone()
		{
			return new Sheep(*this);
		}
		void shearing()
		{
			_hairLength = _hairLength < 0 ? 0 : _hairLength - 2;
		}
	};


	class Cow : public Animal
	{
	public:
		Cow()
		{
			_stubbornness = 6;
			_agressiveness = 5;
			_intelligence = 8;
		}
		Cow* clone()
		{
			return new Cow(*this);
		}
	};
};