#include <QApplication>
#include <pin.h>
#include<pwm.h>
#include<cstdlib>

int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        pin *led = new pin(LED,OUTPUT);
        led->setOutput();
        pin *button = new pin(BUTTON,INPUT);
        button->setInput();
        button->setPullUp();
        button->set(1);
        pwm *pwm_led = new pwm(1117,1);
        uint8_t readValue = -1;
        uint32_t temp = 0;

    while(1)
    {
        button -> set(1);
        readValue =  button -> get();
        printf("Voltage: %.5f\n",pwm_led -> get_duty_cycle());
        if(readValue != 0)
        {
            temp = pwm_led -> get_duty_cycle();
            pwm_led ->set_duty_cycle(temp);
        }
               bcm2835_delay(1000);
    }

        bcm2835_close();
        return 0;
    }

