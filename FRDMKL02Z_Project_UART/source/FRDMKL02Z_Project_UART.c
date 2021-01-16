/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    FRDMKL02Z_Project_UART.c
 * @brief   Application entry point.
 /*Project Yuri Garcia*/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL02Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#define BOARD_LED_GPIO BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN BOARD_LED_RED_GPIO_PIN




#include "sdk_hal_uart0.h"

/* TODO: insert other include files here. */


/* TODO: insert other definitions and declarations here. */
/*
 * @brief   Application entry point.
 */
        void Delay(void){
            volatile uint32_t p=0;
            for (p=0; p<1000000;p++){
                __asm("NOP");
            }



        }
        int main(void) {

            BOARD_InitBootPins();
            BOARD_InitBootClocks();
            BOARD_InitBootPeripherals();
        #ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL

            BOARD_InitDebugConsole();
        #endif



            (void)uart0Inicializar(115200);



            while(1) {
                status_t status;
                uint8_t nuevo_byte;








                if(uart0NuevosDatosEnBuffer()>0){
                    status=uart0LeerByteDesdeBufferCircular(&nuevo_byte);
                    if(status==kStatus_Success){
                        printf("dato:%c\r\n",nuevo_byte);
                    }else{
                        printf("error\r\n");
                    }

                      if(nuevo_byte=='R'){

                    	  /*Red On*/
                            GPIO_PortClear(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);
                            Delay();
                        }

                      if(nuevo_byte=='r'){

                    	  /*Red Off*/
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);

                           Delay();
                      }

                      if(nuevo_byte=='A'){

                    	  /*Blue On*/
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);
                          Delay();
                          }

                      if(nuevo_byte=='a'){

                    	  /*Blue Off*/
                        GPIO_PortSet(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);
                        Delay();
                              }

                      if(nuevo_byte=='V'){

                    	 /*Green On*/
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);
                          Delay();
                                   }

                      if(nuevo_byte=='v'){

                    	  /*Green Off*/
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);
                          Delay();
                                                }
                      if(nuevo_byte=='C'){

                    	  /*Cian On*/
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);
                          Delay();
                                   }

                      if(nuevo_byte=='c'){

                    	  /*Cian Off*/
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);
                          Delay();
                      }

                      if(nuevo_byte=='M'){

                    	  /*Magenta On*/
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);
                          Delay();
                      }

                      if(nuevo_byte=='m'){

                    	  /*Magenta Off*/
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);
                          Delay();
                      }


                      if(nuevo_byte=='N'){

                    	  /*Orange On*/
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);
                          Delay();
                      }

                      if(nuevo_byte=='n'){

                    	  /*Orange Off*/
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);
                          Delay();
                      }


                      }
            }




            return 0 ;
        }
