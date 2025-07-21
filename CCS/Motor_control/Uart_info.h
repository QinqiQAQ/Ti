#ifndef UART_INFO_H
#define UART_INFO_H

#include "ti_msp_dl_config.h" // 如果需要用到其中定义的类型
#include <stdint.h>
#include <stdio.h>
#include <string.h> // 用于memset
// 函数原型声明

extern volatile char uart_0_buffer; 
extern volatile char uart_1_buffer; 
extern volatile char uart_3_buffer; 


void UART_Init(int urat_port);
void uart_send_char(char ch,int urat_port);
void uart_send_string(char* str,int uart_port);

#endif // UART_INFO_H