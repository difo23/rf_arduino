//Tech Trends Shameer
//RF Transmitter and Receiver

//Below is the Transmitter Program

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup()
{
    // Initialize ASK Object
    rf_driver.init();
}

void loop()
{

    const char *on = "1";
    rf_driver.send((uint8_t *)on, strlen(on));
    rf_driver.waitPacketSent();
    delay(1000);
    
    const char *off = "0";
    rf_driver.send((uint8_t *)off, strlen(off));
    rf_driver.waitPacketSent();
    delay(1000);
}
