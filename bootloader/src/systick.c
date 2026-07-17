#include "systick.h"
#include "gpio.h"
volatile uint32_t tick_count  = 0;

struct Timer trafficlight;

struct Timer heartbeat;

struct Timer uarttimer;

struct Timer generalTimer;

// initialize timer lengths

void timers_init(void)
{
    trafficlight.duration = 500;
    heartbeat.duration = 1500;
    uarttimer.duration = 4500;
    generalTimer.duration = 500;
}

void systick_setup() {
    SYSTICK_STRELOAD_R = 16000;
    SYSTICK_STCURRENT_R = 0;
    SYSTICK_STCTRL_R = 0x07;
}

void timer_start(struct Timer *timer, uint32_t ms) { 
    timer->start_time = tick_count;
    timer->duration = ms;
}

void SysTick_Handler(void) {
    tick_count++;
}

int timer_expired(struct Timer *timer) {
    return (tick_count - timer->start_time >= timer->duration);
}
