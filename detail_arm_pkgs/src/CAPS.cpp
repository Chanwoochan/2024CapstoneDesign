#include "CAPS.h"
#include <iomanip>
using namespace std;

CAPS::CAPS()
{
}

CAPS::CAPS(const CAPS &orig)
{
}

CAPS::~CAPS()
{
}

double CAPS::cosWave(double amp, double period, double time, double int_pos)
{
    return (amp / 2) * (1 - cos(PI / period * time)) + int_pos;
}

// void CAPS::ReturnPose(float return_time)
// {
//     static float re_time = 0;

//     static struct End_point target;
//     static struct End_point EP_goal;
//     static float init_joint_angle[2]; // Now nDoF = 13

//     // ref -> init
//     // (ik -> write_ready_joint) - (ref -> init) -> ref

//     EP_goal.x = 0.22;
//     EP_goal.y = 0.0;
//     Compute_IK(EP_goal.x, EP_goal.y);

//     if (re_time == 0)
//     {
//         for (int j = 0; j < 6; j++)
//         {
//             init_joint_angle[j] = refAngle[j];
//         }
//     }
//     if (re_time <= return_time)
//     {
//         for (int j = 0; j < 6; j++)
//         {
//             refAngle[j] = cosWave(write_ready_joint[j] - init_joint_angle[j], return_time, re_time, init_joint_angle[j]);
//         }
//         re_time += tasktime;
//     }
//     else
//     {
//         re_time = 0;
//         Move_current = false;
//     }
// }

// <coswave motion>
// void CAPS::Convert()
// {
//     // 파일 경로 설정
//     std::string file_path = "/home/park/resistance_values.txt";
    
//     // 파일 열기
//     std::ifstream input_file(file_path);
    
//     // 파일이 제대로 열렸는지 확인
//     if (!input_file.is_open()) {
//         std::cerr << "Failed to open file: " << file_path << std::endl;
//     }
    
//     const int motor_count = 7;
//     std::vector<double> Angle(motor_count, 0.0);
    
//     // 파일에서 한 줄씩 읽어와서 배열에 저장
//     std::string line;
//     while (std::getline(input_file, line)) {
//         std::istringstream iss(line);
//         for (int i = 0; i < motor_count && iss >> Angle[i]; i++) {
//             refAngle[i] = (PI / 2048) * Angle[i] * 4;
//         }
//         // 모터 배열 출력
//         for (int i = 0; i < motor_count; i++) {
//             // refAngle[motor_count]=Angle[motor_count];
//             std::cout << "t_motor[" << i + 1 << "] = " << Angle[i] << " "<<endl;
//             std::cout << "R_motor[" << i + 1 << "] = " << refAngle[i] << " "<<endl;
//         }
//     }
// }

// void CAPS::Motion1(float upTime, float swingTime)
// {
//     static float STUtime = 0;
//     static float currentAngle[7]; // Now nDoF = 20

//     if (STUtime >= 0 && motion_1 == false)
//     {

//         Motion1_Angle[0] = (-0 * D2R); 
//         Motion1_Angle[1] = (-5 * D2R);  
//         Motion1_Angle[2] = (110 * D2R); 
//         Motion1_Angle[3] = (-15 * D2R); 
//         Motion1_Angle[4] = (0 * D2R); 
//         Motion1_Angle[5] = (-85 * D2R); 
//         Motion1_Angle[6] = (0 * D2R);   


//         if (STUtime == 0 && motion_1 == false)
//         {

//             for (int j = 0; j < 7; j++)
//             {
//                 currentAngle[j] = refAngle[j];
//             }
//         }

//         if (STUtime < upTime && motion_1 == false)
//         {
//             for (int j = 0; j < 7; j++)
//             {
//                 refAngle[j] = cosWave(standupAngle[j] - currentAngle[j], upTime, STUtime, currentAngle[j]);
//             }
//             STUtime += tasktime;
//         }

//         else
//         {
//             STUtime = 0;
//             motion_1 = true;
//             motion_2 = false;
//         }
//     }

//     else if (STUtime >= 0 && motion_2 == false)
//     {
//         Motion1_Angle[0] = (-0 * D2R); 
//         Motion1_Angle[1] = (-5 * D2R);  
//         Motion1_Angle[2] = (110 * D2R); 
//         Motion1_Angle[3] = (-15 * D2R); 
//         Motion1_Angle[4] = (0 * D2R); 
//         Motion1_Angle[5] = (-85 * D2R); 
//         Motion1_Angle[6] = (0 * D2R);     

//         if (STUtime == 0 && motion_2 == false)
//         {

//             for (int j = 0; j < 7; j++)
//             {
//                 currentAngle[j] = refAngle[j];
//             }
//         }

//         if (STUtime < upTime && motion_2 == false)
//         {
//             for (int j = 0; j < 7; j++)
//             {
//                 refAngle[j] = cosWave(standupAngle[j] - currentAngle[j], upTime, STUtime, currentAngle[j]);
//             }
//             STUtime += tasktime;
//         }

//         else
//         {
//             STUtime = 0;
//             motion_2 = true;
//             motion_3 = false;
//         }
//     }

//     else if (STUtime >= 0 && motion_3 == false)
//     {

//         Motion1_Angle[0] = (-0 * D2R); 
//         Motion1_Angle[1] = (-5 * D2R);  
//         Motion1_Angle[2] = (110 * D2R); 
//         Motion1_Angle[3] = (-15 * D2R); 
//         Motion1_Angle[4] = (0 * D2R); 
//         Motion1_Angle[5] = (-85 * D2R); 
//         Motion1_Angle[5] = (0 * D2R);   
//         Motion1_Angle[7] = (0 * D2R);  

//         if (STUtime == 0 && motion_3 == false)
//         {

//             for (int j = 0; j < 7; j++)
//             {
//                 currentAngle[j] = refAngle[j];
//             }
//         }


//         if (STUtime < upTime && motion_3 == false)
//         {
//             for (int j = 0; j < 7; j++)
//             {
//                 refAngle[j] = cosWave(standupAngle[j] - currentAngle[j], upTime, STUtime, currentAngle[j]);
//             }
//             STUtime += tasktime;
//         }

//         else
//         {
//             STUtime = 0;
//             motion_3 = true;
//             motion_4 = false;
//         }
//     }

//     else if (STUtime >= 0 && motion_4 == false)
//     {

//         Motion1_Angle[0] = (-0 * D2R); 
//         Motion1_Angle[1] = (-5 * D2R);  
//         Motion1_Angle[2] = (110 * D2R); 
//         Motion1_Angle[3] = (-15 * D2R); 
//         Motion1_Angle[4] = (0 * D2R); 
//         Motion1_Angle[5] = (-85 * D2R); 
//         Motion1_Angle[6] = (0 * D2R);   

//         if (STUtime == 0 && motion_4 == false)
//         {

//             for (int j = 0; j < 7; j++)
//             {
//                 currentAngle[j] = refAngle[j];
//             }
//         }

//         if (STUtime < 0.1 && motion_4 == false)
//         {
//             for (int j = 0; j < 7; j++)
//             {
//                 refAngle[j] = cosWave(standupAngle[j] - currentAngle[j], 0.1, STUtime, currentAngle[j]);
//             }
//             STUtime += tasktime;
//         }

//         else
//         {
//             STUtime = 0;
//             motion_4 = true;
//             MOTION_ING = true;
//         }
//     }
//     else
//     {
//         motion_1 = false;
//         motion_2 = true;
//         motion_3 = true;
//         motion_4 = true;
//         //s_stop_TorF = false;
//     }
// }

//     // 파일 닫기
//     inputFile.close();

//     // motor 배열에 저장된 값 출력 (테스트용)
//     cout << "motor 배열에 저장된 값: ";
//     for (int i = 1; i < 8; ++i) {  //motor.size()
//         cout << "motor[" << i << "] = " << motor[i] << ", ";
//     }
//     cout << endl;

//     cout << "tick to Radian: ";
//     for (int i = 0; i < 7; ++i) {  //motor.size()
//         refAngle[i] = (PI/2048)*(motor[i+1]-1024);
//         cout << "motor[" << i << "] = " << refAngle[i] << ", ";
//     }
//     cout << endl;

// }

