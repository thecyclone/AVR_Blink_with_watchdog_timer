#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

ISR (WDT_vect)
{
    PORTB ^= (1<<5); //Left Shift 6 to make PB5 high
}
int main()
{
    cli(); //disable global interrupt
	wdt_reset(); //reset watchdog timer
	
	WDTCSR = (1<<WDCE)|(1<<WDE);//set up WDT interrupt
	WDTCSR = (1<<WDIE)|(1<<WDE)|(1<<WDP1)|(1<<WDP2); //Start Watchdog timer with 1s prescaler for 1s delay.

    sei(); // enable global interrupt


    DDRB |= (1<<5); // Left Shift 6 to define PIN5 of PortB as output
    
    while(1) 
    {
    
        
    }
    return 0;
}