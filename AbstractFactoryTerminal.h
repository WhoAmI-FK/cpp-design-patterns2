#pragma once
#include <iostream>
#include <string>
#include <windows.h>
namespace aterminal {
#pragma region Background
	class Background 
	{
	protected:
		std::string _theme;
	public:
		Background() {	
		}	
		virtual void getTheme() = 0;
	};
	class LightBackground : public Background
	{
	public:
		LightBackground(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 240);
			std::cout << "Making the background white" << std::endl;
			_theme = "light";
		}
		void getTheme() override {
			std::cout << "This is a part of the Light theme" << std::endl;
		}
	};
	class DarkBackground : public Background 
	{
	public:
		DarkBackground(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "Making the background black" << std::endl;
			_theme = "dark";
		}

		void getTheme() override {
			std::cout << "This is a part of the Dark theme" << std::endl;
		}
	};
#pragma endregion Background

#pragma region Text
	class Text
	{
	protected:
		std::string _theme;
	public:
		Text()
		{

		}
		virtual void message(HANDLE hConsole) = 0;
	};
	class BlackText : public Text
	{
	public:
		BlackText(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 240);
			_theme = "light";
			std::cout << "Making the text black" << std::endl;
		}
		void message(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 240);
			std::cout << "This is the default font from the light theme" << std::endl;
		}	
	};
	class WhiteText : public Text
	{
	public:
		WhiteText(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 15);
			_theme = "dark";
			std::cout << "Making the text white" << std::endl;
		}
		void message(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "This is the default font for the dark theme" << std::endl;
		}
	};

	class DarkGreenText : public Text 
	{
	public:
		DarkGreenText(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 242);
			_theme = "dark green";
			std::cout << "Making the text dark green" << std::endl;
		}
		void message(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 242);
			std::cout << "This is the green font for the light theme" << std::endl;
		}
	};
	class LightGreenText : public Text
	{
	public:
		LightGreenText(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 10);
			_theme = "light green";
			std::cout << "Making the text light green" << std::endl;
		}
		void message(HANDLE hConsole)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "This is the green font for the dark theme" << std::endl;
		}
	};
	// need to finish
#pragma endregion Text

#pragma region Factories
	class ThemeFactory 
	{
	public:
		virtual Background* setBackground(HANDLE hConsole) = 0;
		virtual Text* getDefaultText(HANDLE hConsole) = 0;
		virtual Text* getGreenText(HANDLE hConsole) = 0;
	};

	class LightFactory : public ThemeFactory
	{
	public:
		Background* setBackground(HANDLE hConsole) override
		{
			return new LightBackground(hConsole);
		}
		Text* getDefaultText(HANDLE hConsole) override
		{
			return new BlackText(hConsole);
		}
		Text* getGreenText(HANDLE hConsole) override {
			return new DarkGreenText(hConsole);
		}
	};
	class DarkFactory : public ThemeFactory 
	{
	public:
		Background* setBackground(HANDLE hConsole) override
		{
			return new DarkBackground(hConsole);
		}
		Text* getDefaultText(HANDLE hConsole) override
		{
			return new WhiteText(hConsole);
		}
		Text* getGreenText(HANDLE hConsole) override
		{
			return new LightGreenText(hConsole);
		}
	};
#pragma endregion Factories
}