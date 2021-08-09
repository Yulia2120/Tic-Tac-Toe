// Tic Tac Toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

void instruction();

	char nameOne[30];
	char nameTwo[30];     
	char board[3][3];    //00 01 02
				        //10 11 12
				       //20 21 22

int main()
{
	setlocale(LC_ALL, "Russian");

	instruction();












}



void instruction()
{
	std::cout << "\t\t\t\t\t\t*** Tic Tac Toe***\n\n";

	int l = 0;

	for (int i(0); i < 3; i++)
	{
		for (int j(0); j < 3; j++)
		{
			std::cout << "| " << l + 1 << ' ';
			board[i][j] = char(49 + l);
			l++;
		}
		std::cout << '|';
		std::cout << std::endl;
	}
}