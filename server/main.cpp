<<<<<<< HEAD
#include <QApplication>
#include <pin.h>
#include<pwm.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bcm2835_set_debug(1);
    pin *led = new pin(LED,OUTPUT);
    led->setOutput();
    pin *button = new pin(BUTTON,INPUT);
    button->setInput();
    button->setPullUp();
    uint8_t readValue = -1;
=======
    #include <QApplication>
    #include <pin.h>

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        pin *led = new pin(LED,OUTPUT);
        led->setOutput();
        pin *button = new pin(BUTTON,INPUT);
        button->setInput();
        button->setPullUp();
        uint8_t readValue = -1;
>>>>>>> server

    pwm *pwm_led = new pwm(1171,1);

<<<<<<< HEAD
    while(1)
    {
        readValue = button -> get();
        if(readValue != 0)
        {
            pwm_led -> setFdu(pwm_led->getFdu() + (10*pwm_led -> getFdu())/100);
            if(pwm_led -> getFdu() >= pwm_led -> getRange() )
                pwm_led -> setFdu(0);
        }

               pwm_led -> setFdu(pwm_led->getFdu());
               bcm2835_delay(1);
    }
=======
        while(1)
        {
            readValue = bcm2835_gpio_lev(button->numar);
            led->set(0);
            bcm2835_delay(500);
            led->set(1);
            bcm2835_delay(500);

        }
>>>>>>> server


        bcm2835_close();
        return 0;
    }
