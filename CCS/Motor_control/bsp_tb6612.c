/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 文档网站：wiki.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 嘉立创社区问答：https://www.jlc-bbs.com/lckfb
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 */
#include "bsp_tb6612.h"
#include "ti_msp_dl_config.h"
#include "board.h"
#include "motor.h"
#include <math.h>

// // ====== PID参数 ======临界46,P = 12, I = 0.8, D = 0.1
// PID_TypeDef pid_A = {15.0f, 0.8f, 0.0f, 0, 500.0f, 0, 0, 0, 999.0f};
// PID_TypeDef pid_B = {15.0f, 0.8f, 0.0f, 0, 500.0f, 0, 0, 0, 999.0f};
// PID_TypeDef pid_A = {20.0f, 1.0f, 2.5f, 0, 500.0f, 0, 0, 0, 999.0f};
// PID_TypeDef pid_B = {20.0f, 1.0f, 2.5f, 0, 500.0f, 0, 0, 0, 999.0f};
PID_TypeDef pid_A = {12.0f, 0.78f, 0.18f, 0, 500.0f, 0, 0, 0, 999.0f};
PID_TypeDef pid_B = {12.0f, 0.78f, 0.18f, 0, 500.0f, 0, 0, 0, 999.0f};

float target_speed_A = 0.0f;
float target_speed_B = 0.0f;

// ========== PID设定 ==========
void AO_Speed_PID_SetTarget(float target) { target_speed_A = target; }
void BO_Speed_PID_SetTarget(float target) { target_speed_B = target; }

// ========== PID计算 ==========
float AO_Speed_PID_Controller(float target, float actual)
{
    PID_TypeDef* pid = &pid_A;
    float error = target - actual;
    // 积分项累加并限幅
    pid->integral += error;
    if(pid->integral > pid->max_integral) pid->integral = pid->max_integral;
    if(pid->integral < -pid->max_integral) pid->integral = -pid->max_integral;
    // 微分项
    float derivative = -(actual - pid->last_actual);
    pid->last_actual = actual;
    pid->last_error = error;
    pid->output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    // 输出限幅
    if(pid->output > pid->max_output) pid->output = pid->max_output;
    if(pid->output < -pid->max_output) pid->output = -pid->max_output;
    // // PID输出
    // if(actual == 0)  
    // {
    //     AO_Control(pid->output >= 0 ? 1 : 0, 10.0*target);
    //     delay_ms(1000);
    //     return pid->output=10.0*target;
    // }
    // else {
    // pid->output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
     return pid->output;
    // }
}

float BO_Speed_PID_Controller(float target, float actual)
{
    PID_TypeDef* pid = &pid_B;
    float error = target - actual;
    pid->integral += error;
    if(pid->integral > pid->max_integral) pid->integral = pid->max_integral;
    if(pid->integral < -pid->max_integral) pid->integral = -pid->max_integral;
    float derivative = -(actual - pid->last_actual);
    pid->last_actual = actual;
    pid->last_error = error;
    pid->output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    // 输出限幅
    if(pid->output > pid->max_output) pid->output = pid->max_output;
    if(pid->output < -pid->max_output) pid->output = -pid->max_output;
    // // PID输出
    // if(actual == 0)  
    // {
    //     BO_Control(pid->output >= 0 ? 1 : 0, 10.0*target);
    //     delay_ms(100);
    //     return pid->output=10.0*target;
    // }
    // else {
    pid->output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
     return pid->output;
    // }
}
/******************************************************************
 * 函 数 名 称：TB6612_Motor_Stop
 * 函 数 说 明：A端和B端电机停止
 * 函 数 形 参：无
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：无
******************************************************************/
void TB6612_Motor_Stop(void)
{
    AIN1_OUT(0);
    AIN2_OUT(0);
    BIN1_OUT(0);
    BIN2_OUT(0);
}

/******************************************************************
 * 函 数 名 称：AO_Control
 * 函 数 说 明：A端口电机控制
 * 函 数 形 参：dir旋转方向 1正转0反转   speed旋转速度，范围（0 ~ per-1）
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：speed 0-1000
******************************************************************/
void AO_Control(uint8_t dir, uint32_t speed)
{
    if(speed > 999 || dir > 1)
    {
        lc_printf("\nAO_Control parameter error!!!\r\n");
        return;
    }

    if( dir == 1 )
    {
        AIN1_OUT(0);
        AIN2_OUT(1);
    }
    else
    {
        AIN1_OUT(1);
        AIN2_OUT(0);
    }

    DL_TimerG_setCaptureCompareValue(PWM_0_INST, speed, GPIO_PWM_0_C0_IDX);
}



/******************************************************************
 * 函 数 名 称：BO_Control
 * 函 数 说 明：B端口电机控制
 * 函 数 形 参：dir旋转方向 1正转0反转   speed旋转速度，范围（0 ~ per-1）
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：speed 0-1000
******************************************************************/
void BO_Control(uint8_t dir, uint32_t speed)
{
    if(speed > 999 || dir > 1)
    {
        lc_printf("\nAO_Control parameter error!!!\r\n");
        return;
    }

    if( dir == 1 )
    {
        BIN1_OUT(0);
        BIN2_OUT(1);
    }
    else
    {
        BIN1_OUT(1);
        BIN2_OUT(0);
    }

    DL_TimerG_setCaptureCompareValue(PWM_0_INST, speed, GPIO_PWM_0_C1_IDX);
}