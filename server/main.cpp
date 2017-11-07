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
        uint8_t readValue = -1;
        double temp;

    pwm *pwm_led = new pwm(10,1);

    while(1)
    {
        button -> set(1);
        readValue =  button -> get();
        printf("Voltage: %.5f\n",pwm_led -> getFdu());
        if(readValue != 0)
        {
            temp = pwm_led -> getFdu();
            temp = temp + (temp*10)/100;
            pwm_led ->setFdu(temp);
            temp = pwm_led -> getFdu();
            if(temp >= pwm_led -> getRange())
                pwm_led ->setFdu(1);
        }
               bcm2835_delay(100);
    }

        bcm2835_close();
        return 0;
    }

