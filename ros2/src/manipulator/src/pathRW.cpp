/********************************************************************
 * @file Path_data_read_functions_for_JUJODANJO's_Manipulator
 * @name Chan_woo Kim
 * @version Alpha 1.0.0_
 * @copyright Chan_woo Kim
 *
 * !무단 수정 금지!
 ********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "pathRW.hpp"

void initPathData(std::ofstream &rec_path, std::string path_name)
{
    rec_path.open("/home/kcw/capstone_ws/2024CapstoneDesign/ros2/src/manipulator/src/paths/" + path_name + ".pth");
}

void writePathData(std::ofstream &rec_path,int data_size, char *data)
{
    for(int i{0}; i<data_size ;i++)
    {
        rec_path << data[i];
    }
}

bool openPathData(std::ifstream &path, std::string path_name)
{
    path.open("/home/kcw/capstone_ws/2024CapstoneDesign/ros2/src/manipulator/src/paths/" + path_name + ".pth");
    if (!path)
	{
		std::cerr << "\n파일이 존재하지 않거나, 파일을 열 수 없습니다,\n프로그램을 종료합니다.\n\n" << std::endl;

        return 0;
	}
    return 1;
}

std::string readOneLine(std::ifstream &path)
{
    char line[32];
    path.getline(line, 32);
    std::string line_s(line);
    std::cout << line_s << "\n";
    return line_s;
}

void readPathData(std::ifstream &path, int data_size, char *data)
{
    path.read(data,data_size);
}

void dataTransform(char *data, int *out, int motor_num)
{
        for(int i{0}; i<motor_num; i++)
        {
            out[i]=(int)((unsigned char)(data[2*i])<<8|(unsigned char)(data[2*i+1]));
        }
}