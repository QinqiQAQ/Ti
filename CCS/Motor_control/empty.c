#include "ti_msp_dl_config.h"
#include "Uart_info.h"
#include "stdio.h"
#include "stdint.h"
#include "encoder.h"
#include "bsp_tb6612.h"
#include "board.h"
#include "motor.h"




volatile static int i=0;
int main(void)
{
    SYSCFG_DL_init();
    UART_Init(0);
    UART_Init(1);
    UART_Init(2);

        //确保定时器初始化和启动
    NVIC_ClearPendingIRQ(TIMER_ECO_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_ECO_INST_INT_IRQN);
    uart_send_string("uart0 start work\r\n",0);

	encoder_init();
    delay_ms(500);

   while (1) 
    {
        uart_send_string("sjasf",1);
        // uart_send_string("uart1 start work\r\n",1);


        //电机速度motor_A,motor_B
        float motor_speed_A = get_motor_speed(0);
        float motor_speed_B = get_motor_speed(1);
        // 正反转自己定义
        //  uart0_send_string("hello\r\n");
        // delay_ms(10);
                // 设定目标速度
        AO_Speed_PID_SetTarget(30.0f); // A电机目标速度
        BO_Speed_PID_SetTarget(10.0f); // B电机目标速度
        // AO_Control(1, 300);// A端电机转动 速度最大1000
        // BO_Control(1, 100);// B端电机转动 速度最大1000
        float actual_A = get_motor_speed(0);
        float actual_B = get_motor_speed(1);

        float out_A = AO_Speed_PID_Controller(target_speed_A, actual_A);
        float out_B = BO_Speed_PID_Controller(target_speed_B, actual_B);
   
        AO_Control(out_A >= 0 ? 1 : 0, fabsf(out_A));
        BO_Control(out_B >= 0 ? 1 : 0, fabsf(out_B));
        //建议加串口打印，便于调试
        // printf("A: tar=%.1f act=%.1f out=%.1f\r\n", target_speed_A, actual_A, out_A);
        // printf("B: tar=%.1f act=%.1f out=%.1f\r\n", target_speed_B, actual_B, out_B);

        //控制刷新周期
        // delay_ms(100);
        // char c = uart_1_buffer; // 读取最新收到的字节

        // lc_printf("串口3收到: %c", c);
        delay_ms(1000);


        // for(int i = 0; i < 300; i += 30)
        // {
        //     AO_Control(1, i);// A端电机转动 速度最大1000
        //     BO_Control(1, i);// B端电机转动 速度最大1000

        //     lc_printf("Dir[ 1 ]   i[ %d ]\r\n",i);  
        //     printf("%0.2f,%0.0f\n",motor_speed_A,motor_speed_B);
        //     // encoder_update();  // 周期性更新编码器值


        //     delay_ms(500);

        // }
        // TB6612_Motor_Stop(); // 停止转动
        // delay_ms(1000);

        // // for(int i = 0; i < 300; i += 30)
        // // {
        //     // AO_Control(0, i);// A端电机转动 速度最大1000
        //     // BO_Control(0, i);// B端电机转动 速度最大1000

        // //     lc_printf("Dir[ 0 ]   i[ %d ]\r\n",i);
        // //     printf("%0.0f,%0.0f\n",motor_speed_A,motor_speed_B);
        // //     // encoder_update();  // 周期性更新编码器值
        // //     delay_ms(500);
        // // }
        // delay_ms(1000);
        // TB6612_Motor_Stop(); // 停止转动

    }
    return 0;
}


