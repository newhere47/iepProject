#include <QApplication>
#include <pin.h>
#include<pwm.h>
#include<cstdlib>
#include<spi.h>

int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
  /*    pin *led = new pin(LED,OUTPUT);
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
       /* button -> set(1);
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
*/
    bcm2835_set_debug(1);
       Spi *spi = new Spi(BCM2835_SPI_BIT_ORDER_MSBFIRST
                          ,BCM2835_SPI_MODE0, BCM2835_SPI_CLOCK_DIVIDER_65536,
                          BCM2835_SPI_CS0, LOW);
       uint8_t sent_data = 0x21;
       uint8_t read_data = spi->transfer(sent_data);
       printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", sent_data,read_data);
       if (sent_data != read_data)
             printf("Do you have the loopback from MOSI to MISO connected?\n");
}
