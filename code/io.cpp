#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

void output(short position[100][4], short chain_length)
{
	srand(time(0));
	const char* replace_char[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l"};
	const char* random_chars[] = {"z", "y", "x", "w", "v", "u", "t", "s", "r", "q", "p", "o", "n", "m"};
	short random_chars_count = std::size(random_chars);
	std::string out_string = "=";
	int checksum = 0;

	if (chain_length < 10)
	{
		out_string += "0";
	}
	out_string += std::to_string(chain_length);
	checksum += chain_length;

	for (short x = 0; x < chain_length * 2 - 1; x++)
	{
		for (short y = 1; y <= 3; y++)
		{
			checksum += position[x][y];

			if (position[x][y] == 0)
			{
				out_string += random_chars[rand() % random_chars_count];
			}
			else if (position[x][y] >= 1 and position[x][y] <= 9)
			{
				out_string += std::to_string(position[x][y]);
			}
			else if (position[x][y] >= 10 and position[x][y] <= 21)
			{
				out_string += replace_char[position[x][y] - 10];
			}
			else
			{
				std::string error = "碳链值错误\n错误值：" + std::to_string(position[x][y]);
				throw std::out_of_range(error);
			}
		}
	}
	out_string += std::to_string((checksum + 8) % 100);
	out_string += "=";

	std::cout << "\n选择导出方式：\n1. 文本文件（输出至本程序同目录下的output.txt）\n2. 控制台\n\n";
	short out_choice = _getch();
	switch (out_choice)
	{
	case '1':
	{
		std::ofstream out_file("output.txt", std::ios::app);
		if (out_file)
		{
			out_file << out_string << "\n\n";
			out_file.close();

			char fullpath[MAX_PATH];
			DWORD length = GetFullPathNameA("output.txt", MAX_PATH, fullpath, nullptr);
			if (length == 0)
			{
				std::cout << "无法获取文件保存位置，可能已经保存了。来自Windows的错误代码: " << GetLastError();
			}
			else
			{
				std::cout << "已保存到: " << fullpath;
			}
		}
		else
		{
			std::cout << "无法打开或创建输出文件，也许你需要管理员权限";
		}
		break;
	}
	case '2':
		std::cout << out_string;
		break;
	}

	std::cout << "\n\n按任意键继续……";
	(void)_getch();
}

void input(short position[100][4], short &chain_length)
{
	char start_char;
	char length_chars_tens;
	char length_chars_ones;
	char data_char;
	char read_checksum_tens;
	char read_checksum_ones;
	char end_char;

	short read_chain_length = 0;
	short file_checksum = 0;
	short read_checksum = 0;

	short temp_position[100][4]{};
	std::string in_char;
	short in_char_index = 3;

	std::cout << "\n选择导入方式：\n1. 文本文件（读取本程序同目录下的input.txt）\n2. 控制台\n\n";
	short in_choice = _getch();

	switch (in_choice)
	{
	case '1':
	{
		std::ifstream file("input.txt");
		if (file.is_open())
		{
			file.get(start_char);
			if (start_char != '=')
			{
				std::cout << "文件格式不合法，缺少起止标志";
				file.close();
				break;
			}

			file.get(length_chars_tens);
			file.get(length_chars_ones);
			read_chain_length = (length_chars_tens - '0') * 10 + (length_chars_ones - '0');
			if (read_chain_length < 0 or read_chain_length > 50)
			{
				std::cout << "文件值不合法";
				break;
			}
			file_checksum += read_chain_length;

			for (short x = 0; x < read_chain_length * 2 - 1; x++)
			{
				for (short y = 1; y <= 3; y++)
				{
					file.get(data_char);
					if (data_char >= '0' and data_char <= '9')
					{
						temp_position[x][y] = data_char - '0';
					}
					else if (data_char >= 'a' and data_char <= 'l')
					{
						temp_position[x][y] = data_char - 'a' + 10;
					}
					else if(data_char >= 'm' and data_char <= 'z')
					{
						temp_position[x][y] = 0;
					}
					else
					{
						std::cout << "文件值不合法";
						file.close();
						break;
					}
					file_checksum += temp_position[x][y];
				}
			}

			file.get(read_checksum_tens);
			file.get(read_checksum_ones);
			read_checksum = (read_checksum_tens - '0') * 10 + (read_checksum_ones - '0');
			if (read_checksum != (file_checksum + 8) % 100)
			{
				std::cout << "校验和错误，文件可能已损坏或被篡改";
				file.close();
				break;
			}

			file.get(end_char);
			if (end_char != '=')
			{
				std::cout << "文件格式不合法，缺少起止标志";
				file.close();
				break;
			}
			
			chain_length = read_chain_length;
			for (short x = 0; x < read_chain_length * 2 - 1; x++)
			{
				for (int y = 1; y < 4; y++)
				{
					position[x][y] = temp_position[x][y];
				}
			}
			std::cout << "\n导入成功！";
		}
		else
		{
			std::cout << "无法打开文件，可能是文件不存在或被占用";
		}
	}
	break;

	case '2':
		std::cout << "请输入碳链编码：";

		std::cin >> in_char;

		start_char = in_char.at(0);
		if (start_char != '=')
		{
			std::cout << "\n输入格式不合法，缺少起止标志";
			break;
		}

		length_chars_tens = in_char.at(1);
		length_chars_ones = in_char.at(2);
		read_chain_length = (length_chars_tens - '0') * 10 + (length_chars_ones - '0');
		if (read_chain_length < 0 or read_chain_length > 50)
		{
			std::cout << "\n输入值不合法";
			break;
		}
		file_checksum += read_chain_length;

		for (short x = 0; x < read_chain_length * 2 - 1; x++)
		{
			for (short y = 1; y <= 3; y++)
			{
				data_char = in_char.at(in_char_index);
				if (data_char >= '0' and data_char <= '9')
				{
					temp_position[x][y] = data_char - '0';
				}
				else if (data_char >= 'a' and data_char <= 'l')
				{
					temp_position[x][y] = data_char - 'a' + 10;
				}
				else if(data_char >= 'm' and data_char <= 'z')
				{
					temp_position[x][y] = 0;
				}
				else
				{
					std::cout << "\n输入值不合法";
					break;
				}
				in_char_index++;
				file_checksum += temp_position[x][y];
			}
		}

		read_checksum_tens = in_char.at(in_char_index);
		in_char_index++;
		read_checksum_ones = in_char.at(in_char_index);
		in_char_index++;

		read_checksum = (read_checksum_tens - '0') * 10 + (read_checksum_ones - '0');
		if (read_checksum != (file_checksum + 8) % 100)
		{
			std::cout << "\n校验和错误，输入可能已损坏或被篡改";
			break;
		}

		end_char = in_char.at(in_char_index);
		if (end_char != '=')
		{
			std::cout << "\n输入格式不合法，缺少起止标志";
			break;
		}

		chain_length = read_chain_length;
		for (short x = 0; x < read_chain_length * 2 - 1; x++)
		{
			for (int y = 1; y < 4; y++)
			{
				position[x][y] = temp_position[x][y];
			}
		}
		std::cout << "\n导入成功！";
		break;
	}

	std::cout << "\n\n按任意键继续……";
	(void)_getch();
}