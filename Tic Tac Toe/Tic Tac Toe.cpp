// Tic Tac Toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>

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
	system("cls");











}



void instruction()
{
	std::cout << "\t\t\t\t\t\t*** Tic Tac Toe ***\n\n";
	std::cout << "Правила:\n";
	std::cout << "Играют 2 игрока на поле 3x3\n";
	std::cout << "Побеждает тот кто составит выиграшную комбинацию из трех символов\n";
	std::cout << std::endl;
	int c = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "|"<<'_' << c + 1 << '_';
			board[i][j] = char(49 + c);
			c++;
		}
		std::cout << '|';
		std::cout << std::endl;
	}
	std::cout << "\nДля хода нажмите цифру ячейки поля\n";
	std::cout << "Для начала игры нажмите клавишу:";
	_getch();

}
