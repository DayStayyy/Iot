/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "i2s.h"
#include "spi.h"
#include "usart.h"
#include "usb_host.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_USB_HOST_Process(void);
/* USER CODE BEGIN PFP */
int indexOfP(char);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
char arrChar[36] =
 { 'a',
   'b',
   'c',
   'd',
   'e',
   'f',
   'g',
   'h',
   'i',
   'j',
   'k',
   'l',
   'm',
   'n',
   'o',
   'p',
   'q',
   'r',
   's',
   't',
   'u',
   'v',
   'w',
   'x',
   'y',
   'z',
   '0',
   '1',
   '2',
   '3',
   '4',
   '5',
   '6',
   '7',
   '8',
   '9',
 };
 char* arrMorse[36] =
 { "._",
   "_...",
   "_._.",
   "_..",
   ".",
   ".._.",
   "__.",
   "....",
   "..",
   ".___",
   "_._",
   "._..",
   "__",
   "_.",
   "___",
   ".__.",
   "__._",
   ".__.",
   "...",
   "_",
   ".._",
   "..._",
   ".__",
   "_.._",
   "_.__",
   "__..",
   "_____",
   ".____",
   "..___",
   "...__",
   "...._",
   ".....",
   "_....",
   "__...",
   "___..",
   "____.",
 };
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */



  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

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
  MX_I2C1_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  MX_USB_HOST_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  char message[30] = "\necrivez votre message : ";
  while (1)
  {
	  char reponse[20], retour[20];
	  ecris_txt(message);
	  read_string(&reponse,strlen(reponse));
	  sprintf(retour, "%s",reponse);
	  ecris_txt("reponse : ");
	  ecris_txt(retour);
	  ecris_txt("\n");
	  wordToMorse(retour);
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void ecris_char(uint8_t car){
	HAL_UART_Transmit(&huart2,&car,1,1000);
}

void ecris_txt(uint8_t *txt){
	int i;
	for(i=0;i<strlen(txt);i++) {
		ecris_char(txt[i]);
	}
}

unsigned char* lis_txt(char *txt) {
	txt[0]='\0';
	while(!txt[0])
		HAL_UART_Receive(&huart2, txt, 1, 1000);
	ecris_char(*txt);
	return txt;
}

void read_string(unsigned char* txt, size_t size)
{

    unsigned char current;
    current = *lis_txt(&current);

    size_t currSize = 0;
    while (current != '\r' && current != '\n' && currSize < size - 1)
    {
        txt[currSize++] = current;
        current = *lis_txt(&current);
    }
    txt[currSize] = '\0';
    ecris_char('\r');
}

char* charToMorse(char *retour,char charactere) {
    strcpy(retour, arrMorse[indexOfP(charactere)]);
    char txt[20];
    /*sprintf(txt, "trouve %s\n\r",retour);
    ecris_txt(txt);*/
    return retour;
}

void morseToLight(char* tab,char* morse) {
	char txt[20];
	sprintf(txt, "trouve %s\n\r",morse);
	ecris_txt(txt);
    for (int i = 0; i < nbInstance(morse); i++) {
    	char txt[20];
    	sprintf(txt,"morse %c\n\r",morse[i]);
    	ecris_txt(txt);
        if(morse[i] == '.') {
        	HAL_GPIO_WritePin(LD6_BLUE_GPIO_Port, LD6_BLUE_Pin, GPIO_PIN_SET);
        	HAL_Delay(100);
        } else {
        	HAL_GPIO_WritePin(LD6_BLUE_GPIO_Port, LD6_BLUE_Pin, GPIO_PIN_SET);
        	HAL_Delay(300);
        }
       	HAL_GPIO_WritePin(LD6_BLUE_GPIO_Port, LD6_BLUE_Pin, GPIO_PIN_RESET);
        HAL_Delay(100);
    }
    HAL_Delay(700);
}

void wordToMorse(char *word) {
	char tableau[15];
	char tableau2[15];

    for (int i = 0; i < strlen(word); i++) {
  	  /*ecris_txt("word i : ");
  	  ecris_char(word[i]);
  	  ecris_txt("\n");*/
      morseToLight(tableau2,charToMorse(tableau, word[i]));
    }
}

int indexOfP(char charracter){
	for(int i = 0;  i < sizeof(arrChar); i++){
		char txt[20];
		/*sprintf(txt, "arrchar %c\n\r",arrChar[i]);
		ecris_txt(txt);*/

		if(arrChar[i] == charracter){
			char txt[20];
			/*sprintf(txt, "trouve %c\n\r",arrChar[i]);
			ecris_txt(txt);*/
			return i;
		}
	}
	return 0;
}

int nbInstance(char* alu){
	int i = 0;
	while(alu[i] != '\0'){
		i++;
	}
	return i;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

