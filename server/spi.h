#ifndef SPI_H
#define SPI_H


#include<bcm2835.h>
#include<stdint.h>
#include<serial.h>
class Spi : public Serial
{
    public:
        Spi(uint8_t order, uint8_t mode, uint16_t clock_divider, uint8_t chip_select, uint8_t active);
        uint8_t transfer(uint8_t data);
        ~Spi();
};
#endif // SPI_H
