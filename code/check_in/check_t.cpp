#include <iostream>

void notice();

void check_t(short position[100][4], short& chain_length, short pointer[1][2])
{
	if (pointer[0][0] == 0)
	{
		if (pointer[0][1] == -1 or pointer[0][1] == 1)
		{
			if (position[1][2] == 0 or position[1][2] == 2)
			{
				if ((pointer[0][1] == -1 and position[0][3] == 15) or (pointer[0][1] == 1 and position[0][1] == 15))
				{
					std::cout << "一个碳上不能存在两个羟基\n";
					notice();
				}
				else if ((pointer[0][1] == -1 and position[0][3] == 16) or (pointer[0][1] == 1 and position[0][1] == 16))
				{
					std::cout << "一个碳上不能同时存在氨基和羟基\n";
					notice();
				}
				else
				{
					position[0][pointer[0][1] + 2] = 15;
				}
			}
			else
			{
				std::cout << "羟基只能位于单键碳上\n";
				notice();
			}
		}
		else
		{
			std::cout << "取代基需位于主链碳上\n";
			notice();
		}
	}
	else if (pointer[0][0] == chain_length * 2 - 2)
	{
		if (pointer[0][1] == -1 or pointer[0][1] == 1)
		{
			if (position[pointer[0][0] - 1][2] == 0 or position[pointer[0][0] - 1][2] == 2)
			{
				if ((pointer[0][1] == -1 and position[pointer[0][0]][3] == 15) or (pointer[0][1] == 1 and position[pointer[0][0]][1] == 15))
				{
					std::cout << "一个碳上不能存在两个羟基\n";
					notice();
				}
				else if ((pointer[0][1] == -1 and position[pointer[0][0]][3] == 16) or (pointer[0][1] == 1 and position[pointer[0][0]][1] == 16))
				{
					std::cout << "一个碳上不能同时存在氨基和羟基\n";
					notice();
				}
				else
				{
					position[pointer[0][0]][pointer[0][1] + 2] = 15;
				}
			}
			else
			{
				std::cout << "羟基只能位于单键碳上\n";
				notice();
			}
		}
		else
		{
			std::cout << "取代基需位于主链碳上\n";
			notice();
		}
	}
	else if (pointer[0][0] % 2 == 0)
	{
		if (pointer[0][1] == -1 or pointer[0][1] == 1)
		{
			if ((position[pointer[0][0] - 1][2] == 0 or position[pointer[0][0] - 1][2] == 2) and (position[pointer[0][0] + 1][2] == 0 or position[pointer[0][0] + 1][2] == 2))
			{
				if ((pointer[0][1] == -1 and position[pointer[0][0]][3] == 15) or (pointer[0][1] == 1 and position[pointer[0][0]][1] == 15))
				{
					std::cout << "一个碳上不能存在两个羟基\n";
					notice();
				}
				else if ((pointer[0][1] == -1 and position[pointer[0][0]][3] == 16) or (pointer[0][1] == 1 and position[pointer[0][0]][1] == 16))
				{
					std::cout << "一个碳上不能同时存在氨基和羟基\n";
					notice();
				}
				else
				{
					position[pointer[0][0]][pointer[0][1] + 2] = 15;
				}
			}
			else
			{
				std::cout << "羟基只能位于单键碳上\n";
				notice();
			}
		}
		else
		{
			std::cout << "取代基需位于主链碳上\n";
			notice();
		}
	}
	else
	{
		std::cout << "取代基需位于主链碳上\n";
		notice();
	}
}