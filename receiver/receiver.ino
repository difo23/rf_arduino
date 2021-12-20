//Tech Trends Shameer
//RF Transmitter and Receiver

//Below is the Receiver Program

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

// PIN DIGITAL 11

void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[24];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      
      Serial.print("Message Received: ");
    
      
      char* rec = (char*)buf;
      int cases = int(rec[0]);
      
      Serial.println(cases);
      switch(cases) {
        
        case 48:
           digitalWrite(7, LOW);
        break;
        
        case 49:
           digitalWrite(7, HIGH);
        break;
        
        default:
         Serial.println("Default case");
        break;
      
      }      
    }
}
