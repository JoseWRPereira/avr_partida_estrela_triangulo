#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

int main(void) 
{
	// Configurações das entradas e saídas
	// Entradas
	DDRB &= ~((1<<2)|(1<<1));
	PORTB |= ((1<<2)|(1<<1));	// Pull-up 

	// Saídas
	DDRB |= ((1<<3)|(1<<4)|(1<<5));
	PORTB &= ~(1<<3); // Zero 
	PORTB &= ~(1<<4); // Zero 
	PORTB &= ~(1<<5); // Zero 

	while( 1 )
	{
		if( !(PINB & (1<<2)) ) // S1
		{
			PORTB |= (1<<5);	// K1
			PORTB |= (1<<4);	// K2
			_delay_ms(5000);
			PORTB &= ~(1<<4);	// K2
			PORTB |= (1<<3);	// K3
		}
		else if( !(PINB & (1<<1)) ) // S0
		{
			PORTB &= ~(1<<3); // Zero 
			PORTB &= ~(1<<4); // Zero 
			PORTB &= ~(1<<5); // Zero 
		}
	}
}