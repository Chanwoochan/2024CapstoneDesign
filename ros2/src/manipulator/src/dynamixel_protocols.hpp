/********************************************************************
 * @file Dynamixel_Protocol_2.0_functions_for_JUJODANJO's_Manipulator_HEADER
 * @name Chan_woo Kim
 * @version Alpha 1.0.0_
 * @copyright Chan_woo Kim
 *
 * !무단 수정 금지!
 ********************************************************************/

#ifndef DYXL_PROTOCOLS
#define DYXL_PROTOCOLS

unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);

void motor_position_control(int fd, unsigned char motor_id, unsigned short position);

void motor_velocity_control(int fd, unsigned char motor_id, unsigned short velocity);

void motor_Profile_v(int fd, unsigned char motor_id, unsigned short velocity);

void motor_Profile_a(int fd, unsigned char motor_id, unsigned short acc);

void motor_p_gain(int fd, unsigned char motor_id, unsigned short p_gain);

void motor_d_gain(int fd, unsigned char motor_id, unsigned short d_gain);

void motor_torque_e(int fd, unsigned char motor_id);

void position_init(int fd, unsigned long runtime);

#endif