/*
 *timing.c: simple starter application for lab 1A and 1B
 *
 */

#include <stdio.h>		// Used for printf()
#include <stdlib.h>		// Used for rand()
#include "xparameters.h"	// Contains hardware addresses and bit masks
#include "xil_cache.h"		// Cache Drivers
#include "xintc.h"		// Interrupt Drivers
#include "xtmrctr.h"		// Timer Drivers
#include "xtmrctr_l.h" 		// Low-level timer drivers
#include "xil_printf.h" 	// Used for xil_printf()
#include "extra.h" 		// Provides a source of bus contention
//#include "xgpio.h" 		// LED driver, used for General purpose I/i

#define NUMBER_OF_TRIALS 1000000
#define NUMBER_OF_BINS 15
#define BUFFER_SIZE (1024*1024)
unsigned int buffer[BUFFER_SIZE]; //buffer for read/write operations to the DDR memory

/*
 * The following constant is used to determine which channel of the GPIO is
 * used for the LED if there are 2 channels supported.
 */
#define LED_CHANNEL 1

void histogram(void); // This function creates a histogram for the measured data

/*
 * The following are declared globally so they are zeroed and so they are
 * easily accessible from a debugger
 */
//XGpio Gpio; /* The Instance of the GPIO Driver used for LED 0 */

/*
 * This globally declared array stores the
 * number of clock cycles for all the trials.
 * With global declaration, it is stored in the data segment of the
 * memory. Declaring this large array locally may cause a stack overflow.
 */
int numClockCycles[NUMBER_OF_TRIALS];

//Stores the number of samples in each bin
int histData[NUMBER_OF_BINS];

//BaseAddr points to the base (byte) address of the DDR2 Memory
u8 * BaseAddr = (u8 *) XPAR_MIG7SERIES_0_BASEADDR;

/*
 * REPEAT is a somewhat dangerous macro that makes multiple statements from an
 * input string. The danger is statements like if() without {}... Here this is
 * no problem, but beware if you use it elsewhere -- macro bugs are often very
 * hard to debug.
 */
#define REPEAT_5(X) X;X;X;X;X
#define REPEAT_10(X) REPEAT_5(X);REPEAT_5(X)
#define REPEAT_15(X) REPEAT_10(X);REPEAT_5(X)
#define REPEAT_20(X) REPEAT_15(X);REPEAT_5(X)
#define REPEAT_25(X) REPEAT_20(X);REPEAT_5(X)
#define REPEAT_40(X) REPEAT_15(X);REPEAT_25(X)
#define REPEAT_100(X) REPEAT_40(X);REPEAT_40(X);REPEAT_20(X)

int main() {
    // Caches enabled here -- Diasble if you want alternate measurements
	Xil_ICacheInvalidate();
	Xil_ICacheEnable();
	Xil_DCacheInvalidate();
	Xil_DCacheEnable();
	print("---Entering main---\n\r");

	//int timer_val_before; //Used to store the timer value before executing the operation being timed

	// Extra Method contains an interrupt routine which is set to go off at timed intervals
	extra_method();

	//TIMER RESET CODE
	//Turn off the timer
	XTmrCtr_SetControlStatusReg(XPAR_TMRCTR_0_BASEADDR, 1, 0);
	//Put a zero in the load register
	XTmrCtr_SetLoadReg(XPAR_TMRCTR_0_BASEADDR, 1, 0);
	//Copy the load register into the counter register
	XTmrCtr_SetControlStatusReg(XPAR_TMRCTR_0_BASEADDR, 1, XTC_CSR_LOAD_MASK);
	//Enable (start) the timer
	XTmrCtr_SetControlStatusReg(XPAR_TMRCTR_0_BASEADDR, 1,
			XTC_CSR_ENABLE_TMR_MASK);
	//END TIMER RESET CODE

	//INITIALIZATION FOR AXI GPIO LED PORT
	//XGpio_Initialize(&Gpio, XPAR_AXI_GPIO_LED_DEVICE_ID);

	int i = 0;

	for (i = 0; i < NUMBER_OF_TRIALS; i++) {

		//Store the timer value before executing the operation being timed
		//timer_val_before = XTmrCtr_GetTimerCounterReg(XPAR_TMRCTR_0_BASEADDR, 1);


		//XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, onOff); //Turns on one LED

		/*numClockCycles[i] =
		XTmrCtr_GetTimerCounterReg(XPAR_TMRCTR_0_BASEADDR, 1)
				- timer_val_before; //Stores the time to execute the operation

		numClockCycles[i] = (numClockCycles[i] - 137) / 5;
		*/

	}

	while(1 == 1){

	}

	xil_printf("Done!\n\r");

	return 0;

}
