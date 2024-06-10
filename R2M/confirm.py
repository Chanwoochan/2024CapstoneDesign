# pth 숫자로 보고싶을때 실행 -> resistance.txt에 저장됨
def read_pth_file_and_save(file_path, output_file_path):
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
            
            # 가변저항 값들을 txt파일에 저장
            with open(output_file_path, "w") as output_file:
                for i in range(0, len(resistance_values), 8):
                    output_file.write(" ".join(map(str, resistance_values[i:i+8])) + "\n")
            
            print("Data saved to", output_file_path)
            
    except FileNotFoundError:
        print("File not found:", file_path)
    except Exception as e:
        print("An error occurred:", e)

# pth 파일 경로와 출력 파일 경로 설정
pth_file_path = "/home/jy/catkin_ws/src/2024CapstoneDesign/CAPSTONE/src/paths/l.pth"
output_file_path = "/home/jy/catkin_ws/src/2024CapstoneDesign/R2M/resistance_values.txt"

# pth 파일 읽고 가변저항 값들을 저장하는 함수 호출
read_pth_file_and_save(pth_file_path, output_file_path)


