#include <iostream>
#include <windows.h>
#include "Functions.h"
#include <string>
#include <fstream>


std::fstream file("User.txt", std::ios::in | std::ios::out | std::ios::app);

std::string rusername, rpassword;
void start()
{
	int choice;
	std::cout << "-|-|-|-|-|-|-|-|-|-|-|-> Welcome to our webstie <-|-|-|-|-|-|-|-|-|-|-|- " << std::endl;
	std::cout << "             You must register and then you can continue                   " << std::endl;
	std::cout << "                   1. Register           2. Login " << std::endl;
	std::cout << "                   3. forgot PASSWORD    4. EXIT " << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		Register();
		break;
	case 2:
		login();
		break;
	case 3:
		forgot_Password();
	case 4:
		system("CLS");
		std::cout << "\t\t\t THANKS FOR USING OUR WEBSITE \n";
		break;
	}
}

void Register()
{
	system("CLS");
	std::cout << "\t\t\t Enter username : ";
	std::cin >> rusername;
	file << rusername << std::endl;
	std::cout << "\t\t\t\ Enter password : ";
	std::cin >> rpassword;
	file << rpassword << std::endl;
	system("ClS");
	std::cout << "\t\t\t Registration is successfull! \n";
	start();
}

void login()
{
	std::string username, password;
	int choice_after_fail;
	system("CLS");
	std::cout << "\t\t\t USERNAME ";
	std::cin >> username;
	std::cout << "\t\t\t Password ";
	std::cin >> password;
	file.close();
	file.open("User.txt");
	if(file.is_open())
	{
		//std::cout << "FILE SUCCESSFULLY OPENED " << std::endl;
		while (file.good())
		{
			getline(file, rusername);
			getline(file, rpassword);
			if (username == rusername && password == rpassword)
			{
				system("CLS");
				std::cout << "\t\t\t Loggin successfull! \n";
				file.seekg(std::ios::beg);
				start();
			}
		}
		std::cout << "\t\t\t Failed! -> Username or Password incorrect <- Failed! \n";
		std::cout << "\t\t\t Please try again(PRESS 1) or go to menu(PRESS 2) and forgot PASSWORD \n";
		std::cin >> choice_after_fail;
		if (choice_after_fail == 1)
		{
			login();
		}
		else if (choice_after_fail == 2)
		{
			system("CLS");
			start();
		}
		else if (choice_after_fail != 1 && choice_after_fail != 2)
		{
			std::cout << "\t\t\t Enter again \n";
			std::cin >> choice_after_fail;
		}
	}
	else std::cout << "Error while opeening file" << std::endl;
}

void forgot_Password()
{
	std::string fusername;
	system("CLS");
	std::cout << "\t\t\t Enter your username and we will find your password \n";
	std::cin >> fusername;
	char k;
	while (file.good())
	{
		getline(file, rusername);
		if (fusername == rusername)
		{
			getline(file, rusername);

			std::cout << "\t\t\ Congratulations !!!!!!	We found your password : " << rusername << std::endl;
			std::cout << "if you want continue press any key ";
			std::cin >> k;
			system("CLS");
			start();
		}
	}
	if (fusername != rusername)
	{
		std::cout << "\t\t\ You must enter right username and we will definitely find your password \n";
		Sleep(5000);
		forgot_Password();
	}
}