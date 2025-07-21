#include "ti_msp_dl_config.h"
#include "Uart_info.h" // 包含 uart_data 的声明
#include <string.h> // 用于memset
#include "stdio.h"
#include "stdint.h"


/************串口文件使用************/
/*
定义：
1、该文件中，定义了三个串口：uart_0,uart_1,uart_2
2、波特率默认为115200，传输数据位为8位，默认接收数据为char类型

初始化：
1、在main函数中调用时，先对所需使用的串口进行初始化，调用UART_Init(int urat_port)函数，其中uart_port是串口号，
取值为0，1，2，对应uart_0,uart_1,uart_3。因为没有用到uart_2,所以2对应uart_3

串口发送:
串口发送数据，有三个函数：
1、uart_send_char(char ch,int urat_port)：发送单个字符，传参为 需要发送的字符 和 串口号，串口号对应方式如上
2、void uart_send_string(char* str,int urat_port)：发送字符串，传参对应关系参考uart_send_char
3、printf函数：这里把printf函数重定向到了uart_0,可自行更改

串口接收：
1、串口接收的数据为char类型，接收到的数据默认存储到uart_x_buffer（这里的x为0，1，3）
2、可更改uart_x_buffer的类型，如把char改为uint8_t，可接收到int类型数据
3、接收到的数据可以在其他文件中直接调用，记得包含Uart_info.h头文件


*/


/************串口文件使用************/



volatile char uart_0_buffer; 
volatile char uart_1_buffer; 
volatile char uart_3_buffer; 


static const IRQn_Type UART_IRQN_TYPE[]={  
    UART_0_INST_INT_IRQN,
    UART_1_INST_INT_IRQN,
    UART_3_INST_INT_IRQN
};


static  UART_Regs* const UART_PORT[] = {
    UART_0_INST,
    UART_1_INST,
    UART_3_INST
};



/*串口初始化函数*/
void UART_Init(int urat_port) //urat_port为对应的串口，urat_port=0对应uart_0
{
    if((urat_port<3)&&(urat_port>=0))
    {
        NVIC_ClearPendingIRQ(UART_IRQN_TYPE[urat_port]);
    //使能串口中断
        NVIC_EnableIRQ(UART_IRQN_TYPE[urat_port]);
    }
}



// 串口发送单个字符
void uart_send_char(char ch,int urat_port) //ch为字符，urat_port为对应串口
{
    if((urat_port<3)&&(urat_port>=0))
    {    
        while (DL_UART_isBusy(UART_PORT[urat_port]) == true);
        DL_UART_Main_transmitData(UART_PORT[urat_port], ch);
    }
}

// 串口发送字符串
void uart_send_string(char* str,int urat_port)
{
    while (*str != 0 && str != 0)
    {
        uart_send_char(*str++,urat_port);
    }
}


/***************printf重定向(默认在uart_0)*****************/
//重定向fputc函数
int fputc(int ch, FILE *stream)
{
    while( DL_UART_isBusy(UART_0_INST) == true );
    DL_UART_Main_transmitData(UART_0_INST, ch);
    return ch;
}

//重定向fputs函数
int fputs(const char* restrict s, FILE* restrict stream) {

    uint16_t char_len=0;
    while(*s!=0)
    {
        while( DL_UART_isBusy(UART_0_INST) == true );
        DL_UART_Main_transmitData(UART_0_INST, *s++);
        char_len++;
    }
    return char_len;
}
int puts(const char* _ptr)
{
 return 0;
}

/***************printf重定向(默认在uart_0)*****************/



void UART_0_INST_IRQHandler(void)
{
    switch(DL_UART_Main_getPendingInterrupt(UART_0_INST))
    {
        case DL_UART_IIDX_RX:
            uart_0_buffer = DL_UART_Main_receiveData(UART_0_INST);

            break;

        default:
            break;
    }
}

void UART_1_INST_IRQHandler(void)
{
    switch(DL_UART_Main_getPendingInterrupt(UART_1_INST))
    {
        case DL_UART_IIDX_RX:
            uart_1_buffer = DL_UART_Main_receiveData(UART_1_INST);
            uart_send_char('0',0);
            // uart_send_char('\n',0);

            break;

        default:
            break;
    }
}
void UART_3_INST_IRQHandler(void)
{
    switch(DL_UART_Main_getPendingInterrupt(UART_3_INST))
    {
        case DL_UART_IIDX_RX:
            uart_3_buffer = DL_UART_Main_receiveData(UART_3_INST);
            uart_send_char(uart_3_buffer,0);
            // uart_send_char('\n',0);
            break;

        default:
            break;
    }
}
// #define UART3_BUF_SIZE 64
// volatile char uart3_rx_buf[UART3_BUF_SIZE];
// volatile uint16_t uart3_rx_head = 0;

// void UART_3_INST_IRQHandler(void)
// {
//     switch(DL_UART_Main_getPendingInterrupt(UART_3_INST))
//     {
//         case DL_UART_IIDX_RX:
//             uart3_rx_buf[uart3_rx_head] = DL_UART_Main_receiveData(UART_3_INST);
//             uart3_rx_head = (uart3_rx_head + 1) % UART3_BUF_SIZE;
//             break;
//         default:
//             break;
//     }
// }
