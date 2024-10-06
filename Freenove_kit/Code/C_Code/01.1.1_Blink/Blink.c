/**********************************************************************
* Filename    : Blink.c
* Description : Basic usage of GPIO. Let led blink.
* auther      : www.freenove.com
* modification: 2019/12/26
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define  ledPin    0	//define the led pin number

#include <wiringPi.h>   // Include the wiringPi library for GPIO control
#include <stdio.h>      // Include the standard I/O library for printf()

#define ledPin 0        // Define the LED pin number (using wiringPi pin numbering)

int main(void)
{
    // Output a starting message to the terminal
    printf("Program is starting ... \n");
    
    // Initialize the wiringPi library and set up the pin numbering system
    // wiringPiSetup() uses the wiringPi pin numbering scheme
    if (wiringPiSetup() == -1) { // When initialization fails, exit the program
        printf("Setup wiringPi failed!");
        return 1;
    }

    // Set the mode of the pin to OUTPUT to control the LED
    pinMode(ledPin, OUTPUT);

    // Output the pin number being used to the terminal
    printf("Using pin %d\n", ledPin);

    // Infinite loop to continuously blink the LED
    while(1) {
        // Turn the LED on by setting the pin voltage HIGH
        digitalWrite(ledPin, HIGH);
        // Output a message indicating the LED is on
        printf("LED turned on >>>\n");
        // Wait for 1000 milliseconds (1 second)
        delay(10000);

        // Turn the LED off by setting the pin voltage LOW
        digitalWrite(ledPin, LOW);
        // Output a message indicating the LED is off
        printf("LED turned off <<<\n");
        // Wait for 1 second before the loop repeats
        delay(1000);
    }

    return 0; // Although this line will never be reached due to the infinite loop
}

