#include <iostream>

void notice();

void check_b(short position[100][4], short& chain_length, short pointer[1][2])
{
	if (pointer[0][1] == 0)
	{
		if (pointer[0][0] % 2 == 1 and position[pointer[0][0] - 2][2] == 2 and position[pointer[0][0] + 2][2] == 2)
		{
			if (position[pointer[0][0] - 1][1] != 0 or position[pointer[0][0] - 1][3] != 0 or position[pointer[0][0] + 1][1] != 0 or position[pointer[0][0] + 1][3] != 0)
			{
				std::cout << "三键任意侧的碳原子上不能有取代基\n";
				notice();
			}
			else
			{
				position[pointer[0][0]][2] = 4;
			}
		}
		else if (pointer[0][0] == 1 and position[3][2] == 0)
		{
			if ((position[0][1] != 0 and position[0][3] != 0) or (position[2][1] != 0 and position[2][3] != 0))
			{
				std::cout << "三键任意侧的碳原子上不能有两个取代基\n";
				notice();
			}
			else if (position[0][1] == 15 or position[0][3] == 15 or position[2][1] == 15 or position[2][3] == 15)
			{
				std::cout << "三键任意侧的碳原子上不能有羟基\n";
				notice();
			}
			else if (position[0][1] == 16 or position[0][3] == 16 or position[2][1] == 16 or position[2][3] == 16)
			{
				std::cout << "三键任意侧的碳原子上不能有氨基\n";
				notice();
			}
			else
			{
				position[1][2] = 4;
			}
		}
		else if (pointer[0][0] == 1 and position[3][2] == 2)
		{
			if ((position[0][1] != 0 and position[0][3] != 0) or (position[2][1] != 0 and position[2][3] != 0))
			{
				std::cout << "三键任意侧的碳原子上不能有两个取代基\n";
				notice();
			}
			else if (position[2][1] != 0 or position[2][3] != 0)
			{
				std::cout << "三键右侧的碳原子上不能有取代基\n";
				notice();
			}
			else if (position[0][1] == 15 or position[0][3] == 15 or position[2][1] == 15 or position[2][3] == 15)
			{
				std::cout << "三键任意侧的碳原子上不能有羟基\n";
				notice();
			}
			else if (position[0][1] == 16 or position[0][3] == 16 or position[2][1] == 16 or position[2][3] == 16)
			{
				std::cout << "三键任意侧的碳原子上不能有氨基\n";
				notice();
			}
			else
			{
				position[1][2] = 4;
			}
		}
		else if (pointer[0][0] == chain_length * 2 - 3 and position[chain_length * 2 - 5][2] == 2)
		{
			if ((position[chain_length * 2 - 4][1] != 0 and position[chain_length * 2 - 4][3] != 0) or (position[chain_length * 2 - 2][1] != 0 and position[chain_length * 2 - 2][3] != 0))
			{
				std::cout << "三键任意侧的碳原子上不能有两个取代基\n";
				notice();
			}
			else if (position[chain_length * 2 - 4][1] != 0 or position[chain_length * 2 - 4][3] != 0)
			{
				std::cout << "三键左侧的碳原子上不能有取代基\n";
				notice();
			}
			else if (position[0][1] == 15 or position[0][3] == 15)
			{
				std::cout << "三键左侧的碳原子上不能有羟基\n";
				notice();
			}
			else if (position[0][1] == 16 or position[0][3] == 16)
			{
				std::cout << "三键左侧的碳原子上不能有氨基\n";
				notice();
			}
			else
			{
				position[chain_length * 2 - 3][2] = 4;
			}
		}
		else
		{
			std::cout << "三键需位于两个单键碳之间\n";
			notice();
		}
	}
	else
	{
		std::cout << "三键需位于两个单键碳之间\n";
		notice();
	}
}