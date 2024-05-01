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

void CAPS::ReturnPose(float return_time)
{
    static float re_time = 0;

    static struct End_point target;
    static struct End_point EP_goal;
    static float init_joint_angle[2]; // Now nDoF = 13

    // ref -> init
    // (ik -> write_ready_joint) - (ref -> init) -> ref

    EP_goal.x = 0.22;
    EP_goal.y = 0.0;
    Compute_IK(EP_goal.x, EP_goal.y);

    if (re_time == 0)
    {
        for (int j = 0; j < 6; j++)
        {
            init_joint_angle[j] = refAngle[j];
        }
    }
    if (re_time <= return_time)
    {
        for (int j = 0; j < 6; j++)
        {
            refAngle[j] = cosWave(write_ready_joint[j] - init_joint_angle[j], return_time, re_time, init_joint_angle[j]);
        }
        re_time += tasktime;
    }
    else
    {
        re_time = 0;
        Move_current = false;
    }
}

void CAPS::Convert()
{
    // 파일 이름 설정
    // string filename = "/home/park/catkin_ws/src/2024CapstoneDesign/src/paths/first_path.pth";
    string filename = "/home/jy/catkin_ws/src/2024CapstoneDesign/CAPSTONE/src/paths/ff.pth";

    // 파일 열기
    ifstream inputFile(filename);

    // 파일이 열렸는지 확인
    if (!inputFile.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }

    // 데이터를 저장할 벡터 선언
    vector<int> motor;


    // from ChatGPT
    // 파일에서 바이너리 데이터 읽어오기
    char byte;
    while (inputFile.read(&byte, sizeof(byte))) {
        // 바이트를 16진수 문자열로 변환하여 벡터에 저장
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<unsigned char>(byte));
        std::string hexValue = ss.str();

        // 16진수 문자열을 10진수로 변환하여 저장
        int decimalValue = std::stoi(hexValue, 0, 16);
        motor.push_back(decimalValue);
    }



    // // 파일에서 한 줄씩 읽어오기
    // string line;
    // while (getline(inputFile, line)) {
    //     // stringstream을 사용하여 한 줄을 공백으로 분할
    //     stringstream ss(line);
    //     string hexValue;

    //     while (ss >> hexValue) {
    //         // 16진수 문자열을 10진수로 변환하여 저장
    //         int decimalValue = stoi(hexValue, 0, 16);
    //         motor.push_back(decimalValue);
    //     }
    // }





    // 파일 닫기
    inputFile.close();

    // motor 배열에 저장된 값 출력 (테스트용)
    cout << "motor 배열에 저장된 값: ";
    for (int i = 1; i < 8; ++i) {  //motor.size()
        cout << "motor[" << i << "] = " << motor[i] << ", ";
    }
    cout << endl;

    cout << "tick to Radian: ";
    for (int i = 0; i < 7; ++i) {  //motor.size()
        refAngle[i] = (PI/2048)*(motor[i+1]-1024);
        cout << "motor[" << i << "] = " << refAngle[i] << ", ";
    }
    cout << endl;

}

