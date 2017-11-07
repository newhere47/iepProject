#include "pwm.h"

pwm::pwm(int frecventa,int fdu)
{
    this -> frecventa = frecventa;
    this -> fdu = fdu;
    this -> divizor = 16;
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    this -> setFrecventa(frecventa);
    bcm2835_gpio_fsel(PWM_PIN, BCM2835_GPIO_FSEL_ALT5);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);

}


void pwm::setFdu(double fdu)
{
    this -> fdu = fdu;
     bcm2835_pwm_set_data(PWM_CHANNEL, fdu);
}

double pwm::getFdu()
{
    return this -> fdu;
}

void pwm::setFrecventa(int frecventa)
{
    this -> frecventa = frecventa;
    this -> range = 1200/frecventa;
    bcm2835_pwm_set_range(PWM_CHANNEL, this -> range);

}


int pwm::getFrecventa()
{
    return this -> frecventa;
}

int pwm::getRange()
{
    return this -> range;
}
