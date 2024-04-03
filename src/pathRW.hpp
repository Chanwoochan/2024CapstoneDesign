/********************************************************************
 * @file Path_data_read_functions_for_JUJODANJO's_Manipulator_HEADER
 * @name Chan_woo Kim
 * @version Alpha 1.0.0_
 * @copyright Chan_woo Kim
 *
 * !무단 수정 금지!
 ********************************************************************/

#ifndef PATH_READ
#define PATH_READ

void initPathData(std::ofstream &rec_path, std::string path_name);

void writePathData(std::ofstream &rec_path, int data_size, char *data);

void endPathData(std::ofstream &rec_path);

bool openPathData(std::ifstream &path, std::string path_name);

std::string readOneLine(std::ifstream &path, int buff_size);

void readPathData(std::ifstream &path, int data_size, char *data);

void dataTransform(char *data, int *out, int motor_num);

#endif