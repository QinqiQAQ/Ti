#include "pid.h"

/********使用方法***********/
/*
    调用PID_Controller函数
*/



/******需要更改的值******/
/*
    PID参数：Kp,Ki,Kd
    积分器和PID输出限额：
    integral_limit
    output_limit
*/



// 静态全局变量
static PID_ErrorTerms PID_input;
static float prev_filtered_output = 0.0f;  // 低通滤波历史值
static float last_error = 0.0f;            // 上一次误差

void PID_Init() {
    prev_filtered_output = 0.0f;
    last_error = 0.0f;
    PID_input.error = 0.0f;
    PID_input.error_sum = 0.0f;
    PID_input.der_error = 0.0f;
}

float Lowpass_Filter(float pid_output, float alpha) {
    float filtered_output = alpha * pid_output + (1 - alpha) * prev_filtered_output;
    prev_filtered_output = filtered_output;  // 保存滤波后的值
    return filtered_output;
}

float PID_Controller(float error) {
    /* PID参数 */


    const float Kp = 1.0f;
    const float Ki = 0.1f;
    const float Kd = 0.2f;


    /* PID参数 */


    const float integral_limit = 3.0f;    // 积分限幅
    const float output_limit = 10.0f;      // 输出限幅
    const float filter_alpha = 0.2f;        // 低通滤波系数

    /* 更新误差项 */
    PID_input.error = error;
    
    // 积分项（限幅处理）
    float new_integral = PID_input.error_sum + error;
    PID_input.error_sum = MAX(MIN(new_integral, integral_limit), -integral_limit);
    
    // 微分项
    PID_input.der_error = (error - last_error);
    last_error = error;  // 保存当前误差

    /* 计算PID输出 */
    float pid_output = Kp * PID_input.error + Ki * PID_input.error_sum + Kd * PID_input.der_error;
    float filtered_output = Lowpass_Filter(pid_output, filter_alpha);
    
    /* 输出限幅 */
    return MAX(MIN(filtered_output, output_limit), -output_limit);
}