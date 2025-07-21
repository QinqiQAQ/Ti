#include "motor.h"
#include "ti_msp_dl_config.h"
#include "encoder.h"
#include "Uart_info.h"
#include "bsp_tb6612.h"

#define pi 3.1415926

#define FILTER_WINDOW 4  // 可以改为任意正整数

// 权重数组，长度与FILTER_WINDOW一致
// 下面是3点滤波的示例权重（和为1.0），你可以根据需要更改
// static const float filter_weights[FILTER_WINDOW] = {0.6f, 0.3f, 0.1f};
// 以0.5递减，归一化
// const float filter_weights[5] = {0.516f, 0.258f, 0.129f, 0.0645f, 0.0322f}; // 总和≈1.0
const float filter_weights[5] = {0.25f, 0.25f, 0.25f, 0.25f, 0.25f}; // 总和≈1.0


static int encoder_left=0;
static int encoder_right=0;

static int encoder_left_history[FILTER_WINDOW] = {0};
static int encoder_right_history[FILTER_WINDOW] = {0};

static int filter_encoder_left=0;
static int filter_encoder_right=0;

static float motor_speed[2]={0.0f,0.0f};

float get_motor_speed(int motor_num)
{
    if((motor_num<2)&&(motor_num>=0))
    {
        return motor_speed[motor_num];
    }   
    else {
        return -1;
    }
}

// 加权平均滤波函数
int filter_encoder_value_weighted(int *history, int new_value, int window_size, const float *weights)
{
    // 移动历史
    for(int i = window_size - 1; i > 0; i--) {
        history[i] = history[i - 1];
    }
    history[0] = new_value;

    float sum = 0.0f;
    for(int i = 0; i < window_size; i++) {
        sum += history[i] * weights[i];
    }
    return (int)sum;
}

void TIMER_ECO_INST_IRQHandler(void)
{
    switch( DL_TimerG_getPendingInterrupt(TIMER_ECO_INST) )
    {
        case DL_TIMER_IIDX_ZERO:
            encoder_update();
            encoder_left = -get_encoder_count(0);
            encoder_right = get_encoder_count(1);

            // 可变窗口加权滤波
            filter_encoder_left = filter_encoder_value_weighted(
                encoder_left_history, encoder_left, FILTER_WINDOW, filter_weights);
            filter_encoder_right = filter_encoder_value_weighted(
                encoder_right_history, encoder_right, FILTER_WINDOW, filter_weights);

            // 计算轮胎速度
            motor_speed[0] = (float)filter_encoder_left / 20.8 * pi * 4.8;
            motor_speed[1] = (float)filter_encoder_right / 20.8 * pi * 4.8;
            // printf("%f,%f\n", motor_speed[0], motor_speed[1]);
            break;

        default:
            break;
    }
}