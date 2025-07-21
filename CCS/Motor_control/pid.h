#ifndef PID_H
#define PID_H

// 宏定义
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// PID误差项结构体
typedef struct {
    float error;      // 当前误差
    float error_sum;  // 误差积分
    float der_error;  // 误差微分
} PID_ErrorTerms;

// 函数声明
void PID_Init(void);
float PID_Controller(float error);

#endif 