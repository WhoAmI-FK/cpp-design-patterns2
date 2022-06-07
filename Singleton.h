#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
namespace singleton {

	class Leader
	{
	private:
		static Leader* _instance;
		Leader()
		{
			std::cout << "New Leader elected" << std::endl;
		}
	public:
		static Leader* getInstance() {
			if (_instance == nullptr)
			{
				_instance = new Leader();
			}
			return _instance;
		}
		void giveSpeech()
		{
			std::cout << "Address the public" << std::endl;
		}
	};
	Leader* Leader::_instance = nullptr;
};


