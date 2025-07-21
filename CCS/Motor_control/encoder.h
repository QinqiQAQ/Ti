#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "ti_msp_dl_config.h"

typedef enum {
    FORWARD,  // 正向
    REVERSAL  // 反向
} ENCODER_DIR;

typedef struct {
    volatile long long temp_count; //保存实时计数值
    int count;         						 //根据定时器时间更新的计数值
    ENCODER_DIR dir;            	 //旋转方向
} ENCODER_RES;


void encoder_init(void);
int get_encoder_count(int motor_num);
ENCODER_DIR get_encoder_dir(int motor_num);
void encoder_update(void);
static ENCODER_RES motor_encoder[2];
#endif