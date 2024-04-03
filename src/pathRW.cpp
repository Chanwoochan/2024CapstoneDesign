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
    rec_path.open("./paths/" + path_name + ".pth");
}

void writePathData(std::ofstream &rec_path,int data_size, char *data)
{
    for(int i{0}; i<data_size ;i++)
    {
        rec_path << data[i];
    }
    rec_path << "\n";
}

void endPathData(std::ofstream &rec_path)
{
    rec_path << "00000000000000000000000000000000";
}

bool openPathData(std::ifstream &path, std::string path_name)
{
    path.open("./paths/" + path_name + ".pth");
    if (!path)
	{
		std::cerr << "Cannot open this path data." << std::endl;

        return 0;
	}
    return 1;
}

std::string readOneLine(std::ifstream &path, int buff_size)
{
    char line[32];
    path.getline(line, 32);
    std::string line_s(line);
    std::cout << line_s << "\n";
    return line_s;
}

void readPathData(std::ifstream &path, int data_size, char *data)
{
    for(int i{0}; i < data_size; i++)
    {
        path >> data[i];
    }
}

void dataTransform(char *data, int *out, int motor_num)
{
    int o{0};int t{0};int h{0};
    for(int i{0}; i<motor_num; i++)
    {
        if((int)(data[(i+1)*3-1])>64)
        {
            h = ((int)(data[(i+1)*3-1])-55);
        }
        else
        {
            h = ((int)(data[(i+1)*3-1])-48);
        }
        if((int)(data[(i+1)*3])>64)
        {
            t = ((int)(data[(i+1)*3])-55);
        }
        else
        {
            t = ((int)(data[(i+1)*3])-48);
        }
        if((int)(data[(i+1)*3+1])>64)
        {
            o = ((int)(data[(i+1)*3+1])-55);
        }
        else
        {
            o = ((int)(data[(i+1)*3+1])-48);
        }
        out[i] = 16*16*h+16*t+o;
    }
}