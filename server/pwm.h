#ifndef PWM_H
#include<bcm2835.h>
#define PWM_H
#define PWM_PIN RPI_GPIO_P1_12
#define PWM_CHANNEL 0
#define CLOCK_DIVIZOR 16
#define MARKSPACE_MODE  1

class pwm
{
public:
    pwm(uint32_t frecventa,uint32_t duty_cycle);
    void setFrecventa(double frecventa);
    uint32_t getFrecventa();
    void set_duty_cycle(uint32_t fdu);
    uint32_t get_duty_cycle();
    uint32_t getRange();
    void init_pwm(uint8_t fdu);
    void setRange(uint32_t range);

private:
    uint32_t frecventa;
    uint32_t duty_cycle;
    uint32_t range;

};

#endif // PWM_H
