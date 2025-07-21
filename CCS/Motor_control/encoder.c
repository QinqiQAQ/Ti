#include "encoder.h"


/******************编码器数值读取**************/
/*

先调用  encoder_init 函数初始化

在定时器调用 encoder_update 函数更新编码器状态

调用  get_encoder_count 函数获取编码器值

调用  get_encoder_dir 函数获取电机转动方向



*/



static ENCODER_RES motor_encoder[2];

//编码器初始化
void encoder_init(void)
{
	//编码器引脚外部中断
	NVIC_ClearPendingIRQ(GPIOB_INT_IRQn);
	NVIC_EnableIRQ(GPIOB_INT_IRQn);
}

//获取编码器的值
int get_encoder_count(int motor_num)
{
	if((motor_num<2)&&(motor_num>=0))
		return motor_encoder[motor_num].count;
	else
	 	return 0;
}

//获取编码器的方向
ENCODER_DIR get_encoder_dir(int motor_num)
{
	if((motor_num<2)&&(motor_num>=0))
		return motor_encoder[motor_num].dir;
	else
	 	return 0;
}

//编码器数据更新
//请间隔一定时间更新
void encoder_update(void)
{
	for(int i=0;i<2;i++)
	{
		motor_encoder[i].count = motor_encoder[i].temp_count;

		//确定方向
		motor_encoder[i].dir = ( motor_encoder[i].count >= 0 ) ? FORWARD : REVERSAL;

		motor_encoder[i].temp_count = 0;//编码器计数值清零
	}
}

//外部中断处理函数
void GROUP1_IRQHandler(void)
{
	uint32_t gpio_status_L;
	uint32_t gpio_status_R;

	//获取中断信号情况
	gpio_status_L = DL_GPIO_getEnabledInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_PIN_A_L_PIN | GPIO_ENCODER_PIN_B_L_PIN);
	gpio_status_R = DL_GPIO_getEnabledInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_PIN_A_R_PIN | GPIO_ENCODER_PIN_B_R_PIN);
	//编码器A相上升沿触发
	if((gpio_status_L & GPIO_ENCODER_PIN_A_L_PIN) == GPIO_ENCODER_PIN_A_L_PIN)
	{
		//如果在A相上升沿下，B相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B_L_PIN))
		{
			motor_encoder[0].temp_count--;
		}
		else
		{
			motor_encoder[0].temp_count++;
		}
	}//编码器B相上升沿触发
	else if((gpio_status_L & GPIO_ENCODER_PIN_B_L_PIN)==GPIO_ENCODER_PIN_B_L_PIN)
	{
		//如果在B相上升沿下，A相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A_L_PIN))
		{
			motor_encoder[0].temp_count++;
		}
		else
		{
			motor_encoder[0].temp_count--;
		}
	}
	//编码器A相上升沿触发
	if((gpio_status_R & GPIO_ENCODER_PIN_A_R_PIN) == GPIO_ENCODER_PIN_A_R_PIN)
	{
		//如果在A相上升沿下，B相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_B_R_PIN))
		{
			motor_encoder[1].temp_count--;
		}
		else
		{
			motor_encoder[1].temp_count++;
		}
	}//编码器B相上升沿触发
	else if((gpio_status_R & GPIO_ENCODER_PIN_B_R_PIN)==GPIO_ENCODER_PIN_B_R_PIN)
	{
		//如果在B相上升沿下，A相为低电平
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A_R_PIN))
		{
			motor_encoder[1].temp_count++;
		}
		else
		{
			motor_encoder[1].temp_count--;
		}
	}
	//清除状态
	DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A_L_PIN|GPIO_ENCODER_PIN_B_L_PIN);
	DL_GPIO_clearInterruptStatus(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_A_R_PIN|GPIO_ENCODER_PIN_B_R_PIN);
}


