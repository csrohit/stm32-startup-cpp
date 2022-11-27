#include <stdio.h>
#include <stm32f1xx.h>

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
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
  GPIOC->CRH |= 0x02 << ((13 - 8) << 2);

  while(1){
    GPIOC->ODR ^= 1U << 13;
		ms_delay(1000U);
  }

}
