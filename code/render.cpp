#include <iostream>
#include <string>

void render(short position[100][4], short chain_length, short pointer[1][2])
{
    system("cls");

    std::cout << "=====欢迎使用非环烃命名工具=====\n";
    std::cout << "by TidalStarNan\n\n";
    std::cout << "WASD：移动   Esc：退出程序   R：重置   I:导入化合物   O：导出化合物   M：开始命名\n\n";
    std::cout << "Z：延长碳链    X：缩短碳链   Q：删除烃基\n";
    std::cout << "C：单键   V：双键   B：三键   数字键：烃基\n\n";
    std::cout << "当前碳链长度：" << chain_length << "\n\n";

	const char* type_name[] = {"　", "碳", "一", "二", "三", "？", "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "羟", "氨", "氟", "氯", "溴", "碘", "硝"};
	//                           0    1     2     3	    4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21

    for (short type = 1; type < 4; type++)
    {
        for (short i = 0; i < chain_length * 2 - 1; i++)
        {
            if (position[i][type] >= 0 and position[i][type] <= 21)
            {
                if (pointer[0][0] == i and pointer[0][1] == type -  2 )
                {
                    std::cout << "\033[100m" << type_name[position[i][type]] << "\033[0m";
                }
                else
                {
                    std::cout << type_name[position[i][type]];
                }
            }
            else
            {
                std::string error = "碳链值错误\n错误值：" + std::to_string(position[i][type]);
				throw std::out_of_range(error);
            }
        }

        if (type == 2)
        {
            std::cout << "　—> 主链";
        }
        std::cout << "\n";
    }
}