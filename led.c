#include <avr/io.h>
#include <util/delay.h>

void delay()
{
  unsigned char counter = 0;
  while (counter != 50)
    {
      /* wait (30000 x 4) cycles = wait 120000 cycles */
      _delay_loop_2(50000);
      counter++;
    }
}


int main(void)
{
  /* Initialization, set PB5 (arduino digital pin 13) as output */
  DDRB |= (1<<PB5);

  while (1) 
    {
      PORTB |= (1<<PB5);  //arduino digital pin 5 -> 5V
      delay();
      PORTB &= ~(1<<PB5);  //arduino digital pin 5 -> GND   
      delay();
    }
  return 0;
}
