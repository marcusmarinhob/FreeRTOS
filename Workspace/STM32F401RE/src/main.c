/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    17-August-2019
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

void vTask1Handler( void *pvParameters);
void vTask2Handler( void *pvParameters);

// used for semihosting
extern void initialise_monitor_handles();

int main(void)
{
	initialise_monitor_handles();

	printf("\n Inside main()");

	// 1.  Resets the RCC clock configuration to the default reset state.
	// HSI ON, PLL OFF, HSE OFF, system clock = 16MHz, cpu_clock = 16MHz
	RCC_DeInit();

	// 2. Update the SystemCoreClock variable
	SystemCoreClockUpdate();

	// 3. Let's create 2 tasks, task-1 and task-2
	xTaskCreate(vTask1Handler, "Task1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1 );
	xTaskCreate(vTask2Handler, "Task2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2 );


	// 4. Start the Scheduler
	vTaskStartScheduler();


	// You will never return here
	for(;;);


}


void vTask1Handler( void *pvParameters)
{
	/* Variables can be declared just as per a normal function. Each instance
	 * of a task created using this function will have its own copy of the
	 * iVariableExample variable. This would not be true if the variable was
	 * declared static - in which case only one copy of the variable would exist
	 * and this copy would be shared by each created instance of the task.
	 */
	//int iVariableExample = 0;

	/* A task will normally be implemented as in infinite loop*/
	for(;;)
	{
		/* The code to implement the task functionality will go here. */
		printf("\n vTask1Handler()");
	}

	/* Should the task implementation ever break out of the above loop
	 * then the task must be deleted before reaching the end of this function.
	 * The NULL parameter passed to vTaskDele() function indicates that
	 * the task to be deleted is the calling (this) task.
	 */
	vTaskDelete( NULL );
}


void vTask2Handler( void *pvParameters)
{
	/* Variables can be declared just as per a normal function. Each instance
	 * of a task created using this function will have its own copy of the
	 * iVariableExample variable. This would not be true if the variable was
	 * declared static - in which case only one copy of the variable would exist
	 * and this copy would be shared by each created instance of the task.
	 */
	//int iVariableExample = 0;

	/* A task will normally be implemented as in infinite loop*/
	for(;;)
	{
		/* The code to implement the task functionality will go here. */
		printf("\n vTask2Handler()");
	}

	/* Should the task implementation ever break out of the above loop
	 * then the task must be deleted before reaching the end of this function.
	 * The NULL parameter passed to vTaskDele() function indicates that
	 * the task to be deleted is the calling (this) task.
	 */
	vTaskDelete( NULL );
}
