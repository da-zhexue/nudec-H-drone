#include "sys.h"
/*****************************设置优先级******************
**1.设置优先级分组
**2.获取优先级编码
**3.设置优先级
**4.使能中断线
**形参：IRQn_Type IRQn --- 中断线
**			uint32_t PreemptPriority -- 设置抢占优先级
**			uint32_t SubPriority  --设置子优先级
*********************************************************/
void STM32_NVIC_SetPriority(IRQn_Type IRQn,uint32_t PreemptPriority, uint32_t SubPriority)
{
	uint32_t priority;
	NVIC_SetPriorityGrouping(NVIC_PriorityGroup_2);//设置优先级分组,抢占优先2位，子优先级2位
	priority=NVIC_EncodePriority (NVIC_PriorityGroup_2, PreemptPriority, SubPriority);//设置优先级编码
	NVIC_SetPriority(IRQn,priority);//设置优先级
	NVIC_EnableIRQ(IRQn);//使能中断线
}
