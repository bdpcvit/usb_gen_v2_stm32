
#include "main.h"

float freq = 2000.0; //����������� �������� �� 25 �� 6000 ���
uint8_t att = 0; //����������� �������� �� 0 �� 63, 63 - ������������ ������, 0- �����������, ��� 0,5 ��
uint8_t enable = 0; //



uint8_t dataToSend[6] = {0};

int main(void)
{

  /* Configure the system clock and initialize all configured peripherals */
  InitAll();
  
  uint32_t data = 0;
  
  // �������� ��������� HMC
  SetAtt(0x2A);
  if (ReadAtt() == 0x2A) 
      dataToSend[5] = 2; 
   
  data = HMC83x_read(0) & 0x000FFFFF; //������ ID 0xA7975
  if (data == 0xA7975)
      dataToSend[5] = dataToSend[5] | 1;

  
  SetFreq(freq);
  SetAtt(att);
  HAL_Delay(100);
  En(enable);
  
  dataToSend[4] = enable;


  
  while (1)
  {
 
    
  }


}


void Led(uint8_t enable)
{
	if (enable == 0 ) // ����������
	{ 
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	}

	else // ���������
	{
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	}
}

void Error_Handler(void)
{

  while(1) 
  {
  }

}