#include <stdio.h>
#include <iostream>
#include <boost/bind.hpp>
#include <time.h>

// // *Header file for capstone, variable resistance
// #include <fstream>
// #include <string>
// #include <sstream> 

//* Header file for Gazebo and Ros
#include <gazebo/gazebo.hh>
#include <ros/ros.h>

#include <gazebo/common/common.hh> 
#include <gazebo/common/Plugin.hh> //model plugin gazebo API에서 확인 
#include <gazebo/physics/physics.hh> //우리는 ODE physics 사용 
#include <gazebo/sensors/sensors.hh> //IMU sensor 사용 

#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h> //topic을 어떤 형태로 보내는지에 따라 사용되는 헤더파일이다.

#include <functional>
#include <ignition/math/Vector3.hh>
#include "CAPS.h"

#define PI      3.141592
#define D2R     PI/180.
#define R2D     180./PI 

//* Print color
#define C_BLACK   "\033[30m"
#define C_RED     "\x1b[91m"
#define C_GREEN   "\x1b[92m"
#define C_YELLOW  "\x1b[93m"
#define C_BLUE    "\x1b[94m"
#define C_MAGENTA "\x1b[95m"
#define C_CYAN    "\x1b[96m"
#define C_RESET   "\x1b[0m"

using namespace std;
//여기까지가 책으로 따지자면 목차이다. namespace까지


namespace gazebo {

    class arm_plugin : public ModelPlugin
    {
        //*** Variables for Kubot Simulation in Gazebo ***//
        //* TIME variable
        common::Time last_update_time;
        event::ConnectionPtr update_connection;
        double dt;
        double time = 0;

        physics::ModelPtr model; // model = _model 관련

        //* Index setting for each joint
        physics::JointPtr first_yaw;
        physics::JointPtr second_pitch;
        physics::JointPtr third_pitch;
        physics::JointPtr fourth_pitch;
        physics::JointPtr fifth_pitch;
        physics::JointPtr sixth_roll;

        ros::NodeHandle nh;
        ros::Subscriber CAPSModesp;
        int ControlMode_by_ROS = 1;

        ros::Publisher CAPSModesp_pub;
        std_msgs::Float64 CAPSModesp_msg;


        enum
        { 
            LK1 = 0, LK2, LK3, LK4, LK5, LK6
        };

        //* Joint Variables
        int nDoF; // Total degrees of freedom, except position and orientation of the robot. 구조체는 변수 집합이라고 생각.

        typedef struct RobotJoint //Joint variable struct for joint control 
        {
            double targetDegree; //The target deg, [deg]
            double targetRadian; //The target rad, [rad]
            double init_targetradian;

            double targetRadian_interpolation; //The interpolated target rad, [rad]

            double targetVelocity; //The target vel, [rad/s]
            double targetTorque; //The target torque, [N·m]

            double actualDegree; //The actual deg, [deg]
            double actualRadian; //The actual rad, [rad]
            double actualVelocity; //The actual vel, [rad/s]
            double actualRPM; //The actual rpm of input stage, [rpm]
            double actualTorque; //The actual torque, [N·m]

            double Kp;
            double Ki;
            double Kd;

        } ROBO_JOINT;
        ROBO_JOINT* joint;                

        CAPS caps;

    public :
            //*** Functions for Kubot Simulation in Gazebo ***//
          void Load(physics::ModelPtr _model, sdf::ElementPtr /*_sdf*/); // Loading model data and initializing the system before simulation 
          void UpdateAlgorithm(); // Algorithm update while simulation
          
          void setjoints(); // Get each joint data from [physics::ModelPtr _model]    
          void getjointdata(); // Get encoder data of each joint

          void jointcontroller();
          
          void initializejoint(); 
          void setjointPIDgain(); 

          void CAPSMode(const std_msgs::Int32 &msg);

    };
    GZ_REGISTER_MODEL_PLUGIN(arm_plugin);
    
}

void gazebo::arm_plugin::CAPSMode(const std_msgs::Int32 &msg)
{
    // ROS_INFO("I heard: [%d]",msg.data);

    ControlMode_by_ROS = msg.data;
    
    switch (ControlMode_by_ROS) {

    case 1:
        caps.ControlMode = WRITEMODE;
        caps.CommandFlag = RETURN_POSE;
        printf("RETURN POSE! \n");
        
        caps.Move_current = true;
        ControlMode_by_ROS = 0;
        break;

    default:
         break;
    }

}


void gazebo::arm_plugin::Load(physics::ModelPtr _model, sdf::ElementPtr /*_sdf*/)
{
    caps.Move_current = false;
    printf("\nLoad_do\n");
    CAPSModesp = nh.subscribe("/CAPSMode",1,&gazebo::arm_plugin::CAPSMode,this);

    //* model.sdf file based model data input to [physics::ModelPtr model] for gazebo simulation
    model = _model;

    setjoints();
    //sdf변환하기 전에 urdf파일에서 조인트가 몇개인지 인식을 함.
    //인식이 끝나면 joint 갯수에 맞게 구조체를 여러개 생성
    //Robotjoint 구조체를 joint 갯수만큼 복제되는 거임

    nDoF = 6; // Get degrees of freedom, except position and orientation of the robot
    //우리가 만든 joint는 12개로 지정
    joint = new ROBO_JOINT[nDoF]; // Generation joint variables struct    
    
    initializejoint();
    setjointPIDgain();
    //* setting for getting dt

    CAPSModesp_pub = nh.advertise<std_msgs::Float64>("command/CAPSMode", 1000);           

    last_update_time = model->GetWorld()->SimTime();
    update_connection = event::Events::ConnectWorldUpdateBegin(boost::bind(&arm_plugin::UpdateAlgorithm, this));
    
}


void gazebo::arm_plugin::UpdateAlgorithm()
{
    //* UPDATE TIME : 1ms
    common::Time current_time = model->GetWorld()->SimTime();
    dt = current_time.Double() - last_update_time.Double();     //cout << "dt:" << dt << endl;
    time = time + dt;                                           //cout << "time:" << time << endl;

    //* setting for getting dt at next step
    last_update_time = current_time;
    
    getjointdata();

    static int con_count = 0;

    //* Real or simulated real-time thread time setting
    if (con_count % (int) (tasktime * 1000 + 0.001) == 0)
    {

        //* ControlMode
        switch (caps.ControlMode) 
        {

        case WRITEMODE:

            break;

        }

        //* CommandFlag
        switch (caps.CommandFlag) 
        {

        // case RETURN_POSE:

        //     if (caps.Move_current == true) {
        //         caps.ReturnPose(2.0);
        //          for (int j = 0; j < nDoF; j++) {
        //              joint[j].targetRadian = caps.refAngle[j];
        //         }
        //     }
        //     else {
        //         printf("RETURN_POSE COMPLETE !\n");
        //         caps.CommandFlag = NONE_ACT;
        //     }
        //     break;

        case NONE_ACT:

            break;
        }

    }
     
    caps.Convert();
    
    for (int j = 0; j < 7; ++j) {  //motor.size()
      joint[j].targetRadian = caps.refAngle[j];
    }
    

    jointcontroller();        

    CAPSModesp_pub.publish(CAPSModesp_msg); 

}


void gazebo::arm_plugin::setjoints() //plugin에다가 joints name 설정 .sdf파일에서 설정한 이름이랑 확인하기
{
    /*
     * Get each joints data from [physics::ModelPtr _model]
     */

    //* Joint specified in model.sdf
    first_yaw = this->model->GetJoint("first_yaw");
    second_pitch = this->model->GetJoint("second_pitch");
    third_pitch = this->model->GetJoint("third_pitch");
    fourth_pitch = this->model->GetJoint("fourth_pitch");
    fifth_pitch = this->model->GetJoint("fifth_pitch");
    sixth_roll = this->model->GetJoint("sixth_roll");

}

void gazebo::arm_plugin::getjointdata()
{
    /*
     * Get encoder and velocity data of each joint[j].targetRadian = joint_h[j];
     * encoder unit : [rad] and unit conversion to [deg]
     * velocity unit : [rad/s] and unit conversion to [rpm]
     */

    joint[LK1].actualRadian = first_yaw->Position(0);
    joint[LK2].actualRadian = second_pitch->Position(0);
    joint[LK3].actualRadian = third_pitch->Position(0);
    joint[LK4].actualRadian = fourth_pitch->Position(0);
    joint[LK5].actualRadian = fifth_pitch->Position(0);
    joint[LK6].actualRadian = sixth_roll->Position(0);


    joint[LK1].actualVelocity = first_yaw->GetVelocity(0);
    joint[LK2].actualVelocity = second_pitch->GetVelocity(0);
    joint[LK3].actualVelocity = third_pitch->GetVelocity(0);
    joint[LK4].actualVelocity = fourth_pitch->GetVelocity(0);
    joint[LK5].actualVelocity = fifth_pitch->GetVelocity(0);
    joint[LK6].actualVelocity = sixth_roll->GetVelocity(0);


    joint[LK1].actualTorque = first_yaw->GetForce(0);
    joint[LK2].actualTorque = second_pitch->GetForce(0);
    joint[LK3].actualTorque = third_pitch->GetForce(0);
    joint[LK4].actualTorque = fourth_pitch->GetForce(0);
    joint[LK5].actualTorque = fifth_pitch->GetForce(0);
    joint[LK6].actualTorque = sixth_roll->GetForce(0);
    
}

void gazebo::arm_plugin::jointcontroller()
{
        static double pre_rad[6];

        for (int j = 0; j < nDoF; j++){           

            joint[j].targetTorque = joint[j].Kp*(joint[j].targetRadian-joint[j].actualRadian) \
                                  + joint[j].Kd*(joint[j].targetVelocity -joint[j].actualVelocity);

        }
        
        //* Update target torque in gazebo simulation
        first_yaw->SetForce(0, joint[LK1].targetTorque);
        second_pitch->SetForce(0, joint[LK2].targetTorque);
        third_pitch->SetForce(0, joint[LK3].targetTorque);
        fourth_pitch->SetForce(0, joint[LK4].targetTorque);
        fifth_pitch->SetForce(0, joint[LK5].targetTorque);
        sixth_roll->SetForce(0, joint[LK6].targetTorque);
         
}

void gazebo::arm_plugin::initializejoint()
{
    /*
     * Initialize joint variables for joint control
     */
        joint[0].targetRadian= 0*D2R; 
        joint[1].targetRadian= 0*D2R; 
        joint[2].targetRadian= 0*D2R;
        joint[3].targetRadian= 0*D2R;
        joint[4].targetRadian= 0*D2R;
        joint[5].targetRadian= 0*D2R;

}

void gazebo::arm_plugin::setjointPIDgain()
{
    /*
     * Set each joint PID gain for joint control
     */
        joint[LK1].Kp = 3;
        joint[LK2].Kp = 3;
        joint[LK3].Kp = 3;
        joint[LK4].Kp = 3;
        joint[LK5].Kp = 3;
        joint[LK6].Kp = 3;

        joint[LK1].Kd = 0;
        joint[LK2].Kd = 0;
        joint[LK3].Kd = 0;
        joint[LK4].Kd = 0;
        joint[LK5].Kd = 0;
        joint[LK6].Kd = 0;
        
}