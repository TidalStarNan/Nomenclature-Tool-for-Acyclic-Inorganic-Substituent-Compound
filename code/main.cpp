#include <iostream>
#include "main.h"

int main()
{
	main:
	short position[100][4]{};
	position[0][2] = 1;
	for (short x = 0; x < 100; x++)
	{
		position[x][0] = x;
	}

	short pointer[1][2]{};
	short chain_length = 1;
	bool esc = false;

	try
	{
		while (esc == false)
		{
			render(position, chain_length, pointer);

			short key = _getch();
			if (key == 0xE0 || key == 0x00)
			{
				(void)_getch();
				continue;
			}

			switch (key)
			{
			case 27:
				esc = true;
				break;

			case 'm':
			case 'M':
				nomenclature(position, chain_length);

				std::cout << "\n\n按任意键继续……";
				(void)_getch();
				break;

			case 'w':
			case 'W':
				if (pointer[0][1] > -1 and pointer[0][0] % 2 == 0)
				{
					pointer[0][1]--;
				}
				break;

			case 's':
			case 'S':
				if (pointer[0][1] < 1 and pointer[0][0] % 2 == 0)
				{
					pointer[0][1]++;
				}
				break;

			case 'a':
			case 'A':
				if (pointer[0][0] > 0)
				{
					if (pointer[0][1] == 0)
					{
						pointer[0][0]--;
					}
					else if (pointer[0][1] == -1 or pointer[0][1] == 1)
					{
						pointer[0][0] = pointer[0][0] - 2;
					}
				}
				break;

			case 'd':
			case 'D':
				if (pointer[0][0] < chain_length * 2 - 2)
				{
					if (pointer[0][1] == 0)
					{
						pointer[0][0]++;
					}
					else if (pointer[0][1] == -1 or pointer[0][1] == 1)
					{
						pointer[0][0] = pointer[0][0] + 2;
					}
				}
				break;

			case 'z':
			case 'Z':
				if (chain_length < 50)
				{
					position[chain_length * 2 - 1][2] = 2;
					position[chain_length * 2][2] = 1;
					chain_length++;
				}
				else
				{
					std::cout << "碳链长度已达上限50，无法继续延长\n";
					notice();
				}
				break;

			case 'x':
			case 'X':
				check_x(position, chain_length, pointer);
				break;

			case 'c':
			case 'C':
				check_c(position, pointer);
				break;

			case 'v':
			case 'V':
				check_v(position, chain_length, pointer);
				break;

			case 'b':
			case 'B':
				check_b(position, chain_length, pointer);
				break;

			case 'q':
			case 'Q':
				check_q(position, pointer);
				break;

			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				check_alkyl(position, chain_length, pointer, key);
				break;

			case 't':
			case 'T':
				check_t(position, chain_length, pointer);
				break;

			case 'y':
			case 'Y':
				check_y(position, chain_length, pointer);
				break;

			case 'f':
			case 'F':
			case 'g':
			case 'G':
			case 'h':
			case 'H':
			case 'j':
			case 'J':
				check_halogen(position, chain_length, pointer, key);
				break;

			case'k':
			case'K':
				check_k(position, chain_length, pointer);
				break;

			case'i':
			case'I':
				input(position, chain_length);
				break;

			case'o':
			case'O':
				output(position, chain_length);
				break;

			case 'r':
			case 'R':
				std::cout << "\n确定要重置吗？\n按Y键确认，按其他键取消\n";
				key = _getch();
				if (key == 'y' or key == 'Y')
				{
					for (short x = 0; x < 100; x++)
					{
						position[x][0] = x;
						position[x][1] = 0;
						position[x][2] = 0;
						position[x][3] = 0;
					}
					position[0][2] = 1;

					pointer[0][0] = 0;
					pointer[0][1] = 0;
					chain_length = 1;
				}
				break;
			}
		}
	}
	catch (const std::exception& error)
	{
		std::cout << "程序发生错误，错误信息：" << error.what() << "\n";
		std::cout << "\n按任意键重置碳链……";
		(void)_getch();
		goto main;
	}
	catch (...)
	{
		std::cout << "程序发生未知错误";
		std::cout << "\n按任意键退出程序……";
		(void)_getch();
		std::exit(EXIT_FAILURE);	
	}
}