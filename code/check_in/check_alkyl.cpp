#include <iostream>

void notice();

void check_alkyl(short position[100][4], short& chain_length, short pointer[1][2], short key)
{
	if ((pointer[0][1] == 1 or pointer[0][1] == -1) and pointer[0][0] % 2 == 0)
	{
		if (position[pointer[0][0] - 1][2] == 4 or position[pointer[0][0] + 1][2] == 4)
		{
			std::cout << "取代基不能位于三键碳上\n";
			notice();
		}
		else if (position[pointer[0][0] - 1][2] == 3 or position[pointer[0][0] + 1][2] == 3)
		{
			if (pointer[0][1] == -1)
			{
				if (position[pointer[0][0]][3] != 0)
				{
					std::cout << "双键碳上不能存在两个取代基\n";
					notice();
				}
				else
				{
					goto next_check;
				}
			}
			else if (pointer[0][1] == 1)
			{
				if (position[pointer[0][0]][1] != 0)
				{
					std::cout << "双键碳上不能存在两个取代基\n";
					notice();
				}
				else
				{
					goto next_check;
				}
			}
		}
		else
		{
		next_check:if (key - 48 <= (chain_length - 1) / 2)
		{
			if (pointer[0][0] / 2 + 1 > key - 48 and chain_length - (pointer[0][0] / 2) > key - 48)
			{
				position[pointer[0][0]][pointer[0][1] + 2] = key - 43;
			}
			else
			{
				std::cout << "从取代基计算的链长不可长于主链长";
				notice();
			}
		}
		else
		{
			std::cout << "主链太短而取代基太长\n";
			notice();
		}
		}
	}
	else
	{
		std::cout << "取代基需位于主链碳上\n";
		notice();
	}
}