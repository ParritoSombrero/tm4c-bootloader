#ifndef SYSTICK_H
#define SYSTICK_H
#include <stdint.h>

#define SYSTICK_BASE 0xE000E000
#define SYSTICK_STRELOAD_R (*((volatile uint32_t*)(SYSTICK_BASE + 0x014)))
#define SYSTICK_STCTRL_R (*((volatile uint32_t*)(SYSTICK_BASE + 0x010)))
#define SYSTICK_STCURRENT_R (*((volatile uint32_t*)(SYSTICK_BASE + 0x018)))

extern volatile uint32_t tick_count;

struct Timer {
    uint32_t duration;
    uint32_t start_time;
};

extern struct Timer generalTimer;
extern struct Timer uarttimer;
extern struct Timer heartbeat;
extern struct Timer trafficlight;

void systick_setup();
void timer_start(struct Timer *timer, uint32_t ms);
void systick_handler(void);
int timer_expired(struct Timer *timer);

#endif
