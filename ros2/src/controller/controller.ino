/*
kcwjoma@naver.com
*/

#define SWITCH_PIN 7

void motor_data_send(int n, byte *UART_PACKET, int motor)
{
  UART_PACKET[n*2]=motor>>8;
  UART_PACKET[n*2+1]=motor;
}

void setup()
{
  Serial.begin(1000000);
  Serial.setTimeout(0);
  pinMode(SWITCH_PIN,INPUT_PULLUP);
  for(int i{};i<7;i++)
    pinMode(A0+i,INPUT);
}

void loop()
{
  byte UART_PACKET[16]{0};
  byte STATE[2]{0};

  int motor[7]{};

  //UART_PACKET data
  for(int i{};i<7;i++)
  {
    motor[i]=analogRead(A0+i);
    motor_data_send(i, UART_PACKET, motor[i]);
  }

  //Reading polling msg
  byte msg = Serial.read();

  //Observe pushing stop switch
  if(!digitalRead(SWITCH_PIN))
    UART_PACKET[15]=0xFF;
  else
    UART_PACKET[15]=0x00;

  //STATE data
  for(int i{};i<2;i++)
    STATE[i]=UART_PACKET[14+i];

  //Polling
  if(msg == 0xAB)
    Serial.write(UART_PACKET, 16);
  if(msg == 0xCD)
    Serial.write(STATE, 2);
}