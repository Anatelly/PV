#define MAIN

#include "include.h"

int main(void)
{
  init_task();

  while (1)
  {
    adc_task();
  }
}


