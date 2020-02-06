/* 
    (c) 2019 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

#define PERIOD_EXAMPLE_VALUE			(0x0FFF)
#define F_CPU							(4000000UL)

#include <avr/io.h>
#include <util/delay.h>
/*Using default clock 4MHz */

uint32_t dutyCycle = 0;

void PORT_init(void);
void TCA1_init(void);

void PORT_init(void)
{
	PORTC.DIRSET |= PIN6_bm;						/* set pin 6 of PORT C as output */
}

void TCA1_init(void)
{
	PORTMUX.TCAROUTEA = PORTMUX_TCA10_bm;			/* set waveform output on PORT C */

    TCA1.SINGLE.CTRLB = TCA_SINGLE_CMP2EN_bm                    /* enable compare channel 2 */
                      | TCA_SINGLE_WGMODE_SINGLESLOPE_gc ;		/* single-slope PWM mode */
    
    TCA1.SINGLE.PER = PERIOD_EXAMPLE_VALUE;			/* set PWM frequency*/
    
    TCA1.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1_gc	/* set clock source (sys_clk/1) */
                      | TCA_SINGLE_ENABLE_bm;		/* start timer */

}


int main(void)
{
	PORT_init();
	TCA1_init();
	
	while (1)
	{
		TCA1.SINGLE.CMP2 = dutyCycle;
		
		_delay_ms(1);
		
		dutyCycle++;
		
		if(dutyCycle == PERIOD_EXAMPLE_VALUE)
		{
			dutyCycle = 0;
		}
	}
}
