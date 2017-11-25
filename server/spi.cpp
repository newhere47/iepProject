#include<spi.h>
Spi::Spi(uint8_t order, uint8_t data_mode, uint16_t clock_divider, uint8_t chip_select, uint8_t active){
    bcm2835_spi_setBitOrder(order);
    bcm2835_spi_setDataMode(data_mode);
    bcm2835_spi_setClockDivider(clock_divider);
    bcm2835_spi_chipSelect(chip_select);
    bcm2835_spi_setChipSelectPolarity(chip_select, active);
}
uint8_t Spi::transfer(uint8_t data){
    return bcm2835_spi_transfer(data);
}



Spi::~Spi() {
    bcm2835_close();
    bcm2835_spi_end();
}
