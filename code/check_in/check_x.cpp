#include <iostream>

void notice();

void check_x(short position[100][4], short &chain_length, short pointer[1][2])
{
	if (chain_length > 1)
	{
		if (position[chain_length * 2 - 2][1] == 0 and position[chain_length * 2 - 2][3] == 0)
		{
			for (short i = chain_length * 2 - 4; i >= 0; i -= 2)
			{
				if ((position[i][1] > 14 or position[i][1] - 5 < chain_length - (i / 2 + 1)) and (position[i][3] > 14 or position[i][3] - 5 < chain_length - (i / 2 + 1)))
				{
					//可以缩短碳链
				}
				else
				{
					std::cout << "无法缩短碳链，从取代基计算的链长不可长于主链长\n";
					std::cout << "位置：第" << i / 2 + 1 << "个碳\n";
					notice();
					goto x_end;
				}
			}

			position[chain_length * 2 - 2][2] = 0;
			position[chain_length * 2 - 3][1] = 0;
			position[chain_length * 2 - 3][2] = 0;
			position[chain_length * 2 - 3][3] = 0;
			chain_length--;

			if (pointer[0][0] > chain_length * 2 - 2)
			{
				pointer[0][0] = chain_length * 2 - 2;
			}
		}
		else
		{
			std::cout << "无法缩短碳链，要缩短的碳上带有取代基\n";
			notice();
		}
	}
	else
	{
		std::cout << "碳链长度已达下限1，无法继续缩短\n";
		notice();
	}

	x_end:return;
}