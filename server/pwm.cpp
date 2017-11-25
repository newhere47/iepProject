#include "pwm.h"

pwm::pwm(uint32_t frecventa,uint32_t duty_cycle)
{

    this->setFrecventa(frecventa);
    this->set_duty_cycle(duty_cycle);
    uint32_t range = 1024;
    this->setRange(range);
    bcm2835_gpio_fsel(PWM_PIN, BCM2835_GPIO_FSEL_ALT5);
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, MARKSPACE_MODE, 1);
}


void pwm::set_duty_cycle(uint32_t duty_cycle)
{

   int32_t range = 1200000 / (this->getFrecventa());
   int32_t temp = this->get_duty_cycle();
   temp = duty_cycle + (duty_cycle*10)/100;
   uint32_t data = temp / 100 * range;
   if(temp >= this -> getRange())
   {
       bcm2835_pwm_set_data(PWM_CHANNEL, 1);
          this->set_duty_cycle(1);
   }
   else {
       bcm2835_pwm_set_data(PWM_CHANNEL, data);
       this->set_duty_cycle(temp);
   }

}

uint32_t pwm::get_duty_cycle()
{
    return this -> duty_cycle;
}

void pwm::setFrecventa(double frecventa)
{
    this -> frecventa = frecventa;
}


uint32_t pwm::getFrecventa()
{
    return this -> frecventa;
}

uint32_t pwm::getRange()
{
    return this -> range;
}

void pwm::setRange(uint32_t range)
{
    this -> range = range;
    bcm2835_pwm_set_range(PWM_CHANNEL, range);
}
