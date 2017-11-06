#ifndef PWM_H
#include<bcm2835.h>
#define PWM_H
#define PWM_PIN RPI_GPIO_P1_12
#define PWM_CHANNEL 0
#define DIVIZOR 16

class pwm
{
public:
    pwm(int frecventa,int fdu);
    void setFrecventa(int frecventa);
    int getFrecventa();
    void setFdu(int fdu);
    int getFdu();
    int getRange();
    void init_pwm(int fdu);

private:
    int frecventa;
    int fdu;
    int range;
    int divizor;

};

#endif // PWM_H
