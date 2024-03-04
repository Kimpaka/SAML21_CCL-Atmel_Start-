#include <atmel_start.h>
#include <hal_delay.h>

int main(void)
{
	bool flag = false;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	custom_logic_enable();
	/* Replace with your application code */
	while (1) {
		delay_ms(1000);
		flag = !flag;
		gpio_set_pin_level(SIGNAL,flag);
		gpio_set_pin_level(LED,flag);
	}
}
