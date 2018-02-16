/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/*
                                                                   `-/+osyhdmmNNy`
                                                             `-/shmNmhyso+/oMMMy`
                                                         `-+hmNdy+:.`     /mMNo`
                                                     `.:smNds/.`        .yNMm:
                                             `.:+oosmmNmy+.`          .sNMNo`
                                        `-/syhs+:./hmy/`    `::     .odmms.
       ./oyyyo:`       ./oyyy+-      ./ymNyo+oo+/:+/.    ./o//+++//+oso+o++:       .:/++/:.
      :mNNNNNNNh-     /mNNNNNNmy. -odNMMN++dmmdhddd/ `:odNs/hydddmNmdddmmmmo      /ddmmmmdh/
      hNNNmsmNNNm-    hNNNmsmNNms.dNMMMM/-mNdyydmmdd-sNMMh-Ndmmmysossssssss/     -dmmmdhmmmd-
      hNNNh :NNNNh`   hNNNy /NNmm/-+oo++.dNNdd-:dmNNd-NMMo+mddd:                `ymmmd:-dmmmh`
      hNNNh  oNNNN/   hNNNy .omNNm.ddhy-+mNNNo.:sMNNNo+MN/-dmmmho+++++++/-`     +mmmmo  ommmmo
      hNNNh  `dNNNd`  hNNNy-d-dNNm/.-...dhNNh` y.mNNNN-o.  +dmmmmmmmmmmmmmh:   -dmmmh`  `hmmmd-
      hNNNh   :NNNN/  hNmmy:Ms/mdhh.:.`omdmh- .Ny:NNNdy     .+syyyyyyyydmmmd- `ymmmm:    -dmmmy`
      hNNNh    hNNNd` hmNNy:Nh.syss/``+ddmho-:mMM:odmmm/               :mmmmo /mmmmo      ommmm/
      hNNNh    -NNNNy:dmNNy:mms:yoos-.hmmdd-mMNd+.`dmmmd`  .////////::/smmmm/.dmmmh`      `hmmmd.
      hNNNh     +mNNNNNmNm+/yso.odmmyyNddN:sdo-    :mmmms  +mmmmmmmdymmmmmmo`smmmm:        -dmmms
      sddds      -ohdddhs+sdNNMy:dsyhhyydo`-        ohhhh. /hhhhhhysshhhyo- .yhhho          +yyyy.
                    ``` :NMMMMMMh:   .:`                      `.+s.
                         /mMMMMMMs                         `./hmy-
                          .omMMMMMs.`                  `./sdNNy:
                          .-./smNMMMmho+:-..``...-:/oshmMMNmo.
                           :yhysoyNMMMMMMMMMMMMMMMMMMMMNdo-
                             .+ymMMMMMMMMMMMMMMMMMMmyo:`
                                 .-+osyyhhhyyso+:.`
 */

#include "flash.h"
#include "sensors.h"
#include "commandline.h"
#include "GPS.h"
#include "radio.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim10;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/


//GLOBALS:
//UART Buffers
uint8_t uart1_in;
buffer uart1_buf;
uint8_t uart3_in;
buffer uart3_buf;
uint16_t packet_number = 0;

union flt{
  float f;
  uint8_t bytes[4];
};
union flt float_conv;

//Sensors Structs
baro b;
gyro gyros[6];
accel a;
extern gps_data gps;

//Global Flags
uint8_t ADXL_Log, GYRO1_Log, GYRO2_Log, GYRO3_Log, GYRO4_Log, GYRO5_Log, GYRO6_Log, GPS_Log;
uint8_t radio_tim, baro_tim, ms_tim;
uint8_t baro_conv_state = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM10_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM6_Init(void);
static void MX_TIM7_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  // Initialize uart command buffer


  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM10_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();

  /* USER CODE BEGIN 2 */
  //Local vars
  volatile uint8_t temp_packet[23] = {0};

  //Init CS pins to default state
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 1);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 1);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 1);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 1);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 1);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 1);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  HAL_GPIO_WritePin(ADXL_CS_GPIO_Port, ADXL_CS_Pin, 1);
  HAL_GPIO_WritePin(GPS_nRST_GPIO_Port, GPS_nRST_Pin, 1);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);



//  unlock_all(); // Flash init
//  filesystem fs;
//  if(1){  // Change this to a 1 to wipe the old filesystem, and init it to a blank new one (be careful)
//      fs.current_file = -1;
//      fs.next_file_page = 64;
//      fs.num_files = 0;
//      file blank_file;
//      blank_file.bytes_free = 0;
//      blank_file.current_page = 0;
//      blank_file.file_number = 0;
//      blank_file.start_page = 0;
//      blank_file.stop_page = 0;
//      for(int n = 0; n < MAX_FILES; n++){
//          fs.files[n] = blank_file;
//      }
//      write_filesystem(&fs);
//  }

  //Cmd Interface Init
  buffer_init(&uart1_buf, UART_BUFFER_SIZE, 1);
  HAL_UART_Receive_IT(&huart1, &uart1_in, 1);

  //GPS UART Init
  buffer_init(&uart3_buf, UART_BUFFER_SIZE, 3);
  HAL_UART_Receive_IT(&huart3, &uart3_in, 1);

  //Gyro Init
  init_gyros();
  for(int n = 1; n <= 6; n++){
      gyros[n-1].id = n;
  }

  //Accel Init
  init_accel();

  //Baro Init
  init_baro(&b);
  D2_conv_baro(&b);
  HAL_Delay(20);

  //Radio Init
  init_radio();
  radio_resetFIFO();

  print("System Initilization Complete\n\0");


//  file* logfile = new_log();
//  for(int i = 0; i<600; i++){
//      read_gyro(&gyros[0]);
//      read_accel(&a);
//      log_accel(logfile, &a);
//      log_gyro(logfile, &gyros[0]);
//      HAL_Delay(5);
//  }
//  close_log(logfile);

  //Start Timers
  HAL_TIM_Base_Init(&htim6);
  HAL_TIM_Base_Start_IT(&htim6);
  HAL_TIM_Base_Init(&htim7);
  HAL_TIM_Base_Start_IT(&htim7);
  HAL_TIM_Base_Init(&htim10);
  HAL_TIM_Base_Start_IT(&htim10);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
    //Check if a drdy interrupt has occured and fetch data
    if(ADXL_Log == 1){
        read_accel(&a);
        //log_accel(logfile, &a);
        ADXL_Log = 0;
    }
    if(GYRO1_Log == 1){
      read_gyro(&gyros[0]);
      //log_gyro(logfile, &gyros[0]);
      GYRO1_Log =0;
    }
    if(GYRO2_Log == 1){
      read_gyro(&gyros[1]);
      //log_gyro(logfile, &gyros[1]);
      GYRO2_Log =0;
    }
    if(GYRO3_Log == 1){
      read_gyro(&gyros[2]);
      //log_gyro(logfile, &gyros[2]);
      GYRO3_Log =0;
    }
    if(GYRO4_Log == 1){
      read_gyro(&gyros[3]);
      //log_gyro(logfile, &gyros[3]);
      GYRO4_Log =0;
    }
    if(GYRO5_Log == 1){
      read_gyro(&gyros[4]);
      //log_gyro(logfile, &gyros[4]);
      GYRO5_Log =0;
    }
    if(GYRO6_Log == 1){
      read_gyro(&gyros[5]);
      //log_gyro(logfile, &gyros[5]);
      GYRO6_Log = 0;
    }
    if(GPS_Log == 1){
        //log_gps(logfile, &gps);
    }


    //Check timer interrupts
    if(radio_tim == 1){
        //Send out radio packet
        temp_packet[1] = 0x7; //0x0 wil be normal packet
        temp_packet[2] = (packet_number >> 8) & 0xFF;
        temp_packet[3] = (packet_number & 0xFF);

        float_conv.f = gps.latitude;
        temp_packet[4] = float_conv.bytes[0];
        temp_packet[5] = float_conv.bytes[1];
        temp_packet[6] = float_conv.bytes[2];
        temp_packet[7] = float_conv.bytes[3];

        float_conv.f = gps.longitude;
        temp_packet[8] = float_conv.bytes[0];
        temp_packet[9] = float_conv.bytes[1];
        temp_packet[10] = float_conv.bytes[2];
        temp_packet[11] = float_conv.bytes[3];

        //Need to write function to actually get baro_alt
//        temp_packet[12] = (baro_alt >> 8) & 0xFF;
//        temp_packet[13] = (baro_alt) & 0xFF;

        //Same as above
//        temp_packet[14] = (max_alt >> 8) & 0xFF;
//        temp_packet[15] = (max_alt) & 0xFF;

        //Just send gyro 2 data for now. Can send avg of all channels if wanted
        //Need to change axis to the correct one...
        temp_packet[16] = (gyros[2].data[2] >> 8) & 0xFF;
        temp_packet[17] = (gyros[2].data[2]) & 0xFF;

        //Need to write function to actually calculate vel from accel
//        temp_packet[18] = (gyros[1].data[1] >> 8) & 0xFF;
//        temp_packet[19] = (gyros[1].data[1]) & 0xFF;

        //Need to change axis to the correct one...
        temp_packet[20] = (a.data[2] >> 16) & 0xFF;
        temp_packet[21] = (a.data[2] >> 8) & 0xFF;
        temp_packet[22] = (a.data[2]) & 0xFF;

        //Byte for packet stuffing test. Remember to remove
        temp_packet[12] = 0x0A;

        //Do steps for transmit
        radio_txPacket(temp_packet);
        packet_number += 1;
        radio_tim = 0;
    }
    if(baro_tim == 1){
        //Send conversion and/or read adc
        if(baro_conv_state == 0){
            read_D2_baro(&b);
            D1_conv_baro(&b);
            baro_conv_state = 1;
        }
        else{
            read_D1_baro(&b);
            D2_conv_baro(&b);
            conv_pres_baro(&b);
            //log_baro(logfile, &b);
            baro_conv_state = 0;
        }
        baro_tim = 0;
    }
    if(ms_tim == 1){
        //Log number of ms??
    }
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    //_Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI2 init function */
static void MX_SPI2_Init(void)
{

  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM6 init function */
static void MX_TIM6_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 17999;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 99;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM7 init function */
static void MX_TIM7_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 17999;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 999;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM10 init function */
static void MX_TIM10_Init(void)
{

  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 1799;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 99;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART3 init function */
static void MX_USART3_UART_Init(void)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, MEM_CS_Pin|PYRO_2_FIRE_Pin|GYRO5_CS_Pin|GYRO4_CS_Pin 
                          |ADXL_CS_Pin|RADIO_CS_Pin|GPS_nRST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PYRO_1_FIRE_Pin|GYRO1_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, MS5607_CS_Pin|GYRO3_CS_Pin|GYRO2_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : GYRO2_INT_Pin GYRO4_INT_Pin nIRQ_RADIO_Pin */
  GPIO_InitStruct.Pin = GYRO2_INT_Pin|GYRO4_INT_Pin|nIRQ_RADIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : MEM_CS_Pin PYRO_2_FIRE_Pin GPS_nRST_Pin */
  GPIO_InitStruct.Pin = MEM_CS_Pin|PYRO_2_FIRE_Pin|GPS_nRST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PYRO_1_FIRE_Pin */
  GPIO_InitStruct.Pin = PYRO_1_FIRE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PYRO_1_FIRE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MS5607_CS_Pin GYRO3_CS_Pin GYRO2_CS_Pin */
  GPIO_InitStruct.Pin = MS5607_CS_Pin|GYRO3_CS_Pin|GYRO2_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : GYRO5_CS_Pin GYRO4_CS_Pin ADXL_CS_Pin RADIO_CS_Pin */
  GPIO_InitStruct.Pin = GYRO5_CS_Pin|GYRO4_CS_Pin|ADXL_CS_Pin|RADIO_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : GYRO1_INT_Pin GYRO5_INT_Pin ADXL_DRDY_Pin */
  GPIO_InitStruct.Pin = GYRO1_INT_Pin|GYRO5_INT_Pin|ADXL_DRDY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : GYRO1_CS_Pin */
  GPIO_InitStruct.Pin = GYRO1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GYRO1_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : GYRO6_CS_Pin */
  GPIO_InitStruct.Pin = GYRO6_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GYRO6_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : GYRO6_INT_Pin GYRO3_INT_Pin */
  GPIO_InitStruct.Pin = GYRO6_INT_Pin|GYRO3_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
