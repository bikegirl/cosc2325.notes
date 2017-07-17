#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN         5
#define LED_ON          (PORTB |= (1<<LED_PIN))
#define LED_OFF         (PORTB &= ~(1<<LED_PIN))

#define LED_CONFIG      (DDRB |= (1<<LED_PIN))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

int main(void) {

    CPU_PRESCALE(0);
    LED_CONFIG;
    LED_OFF;

    while(1){
        LED_ON;
        _delay_ms(500);
        LED_OFF;
        _delay_ms(500);
    }
}
