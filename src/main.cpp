#include <stdio.h>
#include <stm32f1xx.h>
#include <gpio.hpp>


void ms_delay(int ms)
{
  while (ms-- > 0)
  {
    volatile int x = 500;
    while (x-- > 0)
      __asm("nop");
  }
}

int main(void)
{
  GPIO::enable_PortC();
  GPIO::setMode(GPIOC, GPIO::PIN_13,GPIO::OUTPUT_2MHZ);
  GPIO::setConfig(GPIOC, GPIO::PIN_13,GPIO::OUTPUT_PUSH_PULL);
  while (1)
  {
    GPIO::toggle(GPIOC, GPIO::PIN_13);
    ms_delay(1000U);
  }
}
