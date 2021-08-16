// Tic Tac Toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>


void instruction();

	char nameOne[30];
	char nameTwo[30];     
	char board[3][3];    
	bool step;
	bool Input();
	bool victory();


int main()
{
	setlocale(LC_ALL, "Russian");

	instruction();
	system("cls");
	int i = 0;
	std::cout << "Введите имя 1 игрока: ";
	std::cin.getline(nameOne, 30);
	std::cout << "Введите имя 2 игрока: ";
	std::cin.getline(nameTwo, 30);
//случайным образом выбираем кто ходит первым
	srand(time(NULL));
	if (rand() & 1)    //битовое умножение на 1(деление с остатком на 2)
		step = true;
	else step = false;

	while (!victory())
	{
		if (i == 9)
		{
			std::cout << "Ничья!";
			_getch();
			return -1;
		}
		system("cls");
		if (!Input())
		{
			std::cout << "Вы ввели неверные данные повторите!";
			_getch();
		}
		i++;
	}

	system("cls");
	if (step)
		std::cout << "Победил " << nameTwo << std::endl;
	else std::cout << "Победил " << nameOne << std::endl;


	_getch();
	return 0;


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
	return;
}

bool Input()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "| " << board[i][j] << ' ';
		}
		std::cout << '|';
		std::cout << std::endl;
	}

	std::cout << std::endl;
	if (step)
		std::cout << "Ходит " << nameOne << " : ";
	else std::cout << "Ходит " << nameTwo << " : ";

	int n;
	std::cin >> n;
	if (n < 1 || n > 9)
		return false;   //ввод не удался
	int i, j;  //ищем индексы столбца и строки
											   //00 01 02
						                      //10 11 12
					                          //20 21 22
	if (n % 3 == 0)       //третий столбец
	{
		i = n / 3 - 1;   //строки
		j = 2;
	}
	else
	{
		j = n % 3 - 1;
		i = n / 3;
	}

	if (board[i][j] == 'O' || board[i][j] == 'X') //если клетка занята, то ввод не удался
		return false;

	if (step)     //смотря чей ход
	{
		board[i][j] = 'X';
		step = false;
	}
	else { board[i][j] = 'O'; step = true; }
	return true;
}

bool victory()
{
	for (int i(0); i < 3; i++)
		if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))  //проверка по горизонтали
			return true;

		else
			if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))  //проверка по вертикали
				return true;

			else if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])) //проверка по диагонали
				return true;


	return false;
}