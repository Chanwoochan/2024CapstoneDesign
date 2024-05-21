import rospy
from std_msgs.msg import Int32MultiArray

def read_pth_file_and_publish(file_path):
    try:
        # pth 파일 열기
        with open(file_path, "rb") as file:
            # 파일 내용 읽기
            data = file.read()
            
            # 16비트 정수로 변환하여 가변저항 값으로 해석
            resistance_values = []
            for i in range(0, len(data), 2):  # 2바이트씩 읽음
                value = int.from_bytes(data[i:i+2], byteorder='little')  # little-endian으로 변환
                resistance_values.append(value * 1024 // 65535)  # 0에서 1024 범위로 변환
            
            # ROS Publisher 초기화
            rospy.init_node('resistance_publisher', anonymous=True)
            pub = rospy.Publisher('resistance_values', Int32MultiArray, queue_size=10)
            rate = rospy.Rate(10)  # 발행 속도 설정
            
            # 가변저항 값을 한 행당 8개씩 묶어서 발행
            idx = 0
            while not rospy.is_shutdown():
                # 한 행당 8개씩 메시지에 담아 발행
                row = resistance_values[idx:idx+8]
                msg = Int32MultiArray(data=row)
                pub.publish(msg)
                rate.sleep()
                
                idx += 8
                if idx >= len(resistance_values):
                    break
            
            rospy.loginfo("Resistance values published successfully.")
            
    except FileNotFoundError:
        rospy.logerr("File not found: %s", file_path)
    except Exception as e:
        rospy.logerr("An error occurred: %s", str(e))

# 테스트를 위해 pth 파일 경로 설정
pth_file_path = "/home/jy/catkin_ws/src/2024CapstoneDesign/CAPSTONE/src/paths/ss.pth"

# pth 파일 읽고 가변저항 값을 ROS topic으로 발행
read_pth_file_and_publish(pth_file_path)

