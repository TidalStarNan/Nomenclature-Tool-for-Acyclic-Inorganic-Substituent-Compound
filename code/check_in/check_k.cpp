#include <iostream>
#include <string>

void notice();

void check_k(short position[100][4], short& chain_length, short pointer[1][2])
{
	if (pointer[0][1] == -1 or pointer[0][1] == 1)
	{
		if (pointer[0][0] == 0)
		{
			if (position[1][2] == 2 or position[1][2] == 3)
			{
				position[pointer[0][0]][pointer[0][1] + 2] = 21;
			}
			else if (position[1][2] == 4)
			{
				if (pointer[0][1] == -1 and position[0][3] != 0)
				{
					std::cout << "三键碳上不能存在两个取代基\n";
					notice();
				}
				else if (pointer[0][1] == 1 and position[0][1] != 0)
				{
					std::cout << "三键碳上不能存在两个取代基\n";
					notice();
				}
				else
				{
					position[pointer[0][0]][pointer[0][1] + 2] = 21;
				}
			}
		}
		else if (pointer[0][0] == chain_length * 2 - 2)
		{
			if (position[chain_length * 2 - 3][2] == 2 or position[chain_length * 2 - 3][2] == 3)
			{
				position[pointer[0][0]][pointer[0][1] + 2] = 21;
			}
			else if (position[chain_length * 2 - 3][2] == 4)
			{
				if (pointer[0][1] == -1 and position[chain_length * 2 - 2][3] != 0)
				{
					std::cout << "三键碳上不能存在两个取代基\n";
					notice();
				}
				else if (pointer[0][1] == 1 and position[chain_length * 2 - 2][1] != 0)
				{
					std::cout << "三键碳上不能存在两个取代基\n";
					notice();
				}
				else
				{
					position[pointer[0][0]][pointer[0][1] + 2] = 21;
				}
			}
		}
		else
		{
			if (position[pointer[0][0] - 1][2] == 4 or position[pointer[0][0] + 1][2] == 4)
			{
				std::cout << "取代基不能位于三键碳上\n";
				notice();
			}
			else if (position[pointer[0][0] - 1][2] == 3 or position[pointer[0][0] + 1][2] == 3)
			{
				if (pointer[0][1] == -1 and position[pointer[0][0]][3] != 0)
				{
					std::cout << "双键碳上不能存在两个取代基\n";
					notice();
				}
				else if (pointer[0][1] == 1 and position[pointer[0][0]][1] != 0)
				{
					std::cout << "双键碳上不能存在两个取代基\n";
					notice();
				}
				else
				{
					position[pointer[0][0]][pointer[0][1] + 2] = 21;
				}
			}
			else
			{
				position[pointer[0][0]][pointer[0][1] + 2] = 21;
			}
		}
	}
	else
	{
		std::cout << "取代基需位于主链碳上\n";
		notice();
	
	}
}