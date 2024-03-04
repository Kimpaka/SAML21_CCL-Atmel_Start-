/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

struct usart_sync_descriptor TARGET_IO;

void DIGITAL_GLUE_LOGIC_0_PORT_init(void)
{

	gpio_set_pin_function(CCL_IN, PINMUX_PB06I_CCL_IN6);

	gpio_set_pin_function(PB09, PINMUX_PB09I_CCL_OUT2);
}

void DIGITAL_GLUE_LOGIC_0_CLOCK_init(void)
{
	hri_mclk_set_APBDMASK_CCL_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, CCL_GCLK_ID, CONF_GCLK_CCL_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void DIGITAL_GLUE_LOGIC_0_init(void)
{
	DIGITAL_GLUE_LOGIC_0_CLOCK_init();
	custom_logic_init();
	DIGITAL_GLUE_LOGIC_0_PORT_init();
}

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(PA04, PINMUX_PA04D_SERCOM0_PAD0);

	gpio_set_pin_function(PA05, PINMUX_PA05D_SERCOM0_PAD1);
}

void TARGET_IO_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM0_GCLK_ID_SLOW, CONF_GCLK_SERCOM0_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM0_bit(MCLK);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	usart_sync_init(&TARGET_IO, SERCOM0, (void *)NULL);
	TARGET_IO_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA12

	gpio_set_pin_level(SIGNAL,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(SIGNAL, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(SIGNAL, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB10

	gpio_set_pin_level(LED,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED, GPIO_PIN_FUNCTION_OFF);

	DIGITAL_GLUE_LOGIC_0_init();

	TARGET_IO_init();
}
