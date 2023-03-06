// Description----------------------------------------------------------------|
/*
 *
 */
// DEFINES AND INCLUDES-------------------------------------------------------|

#define STM32F051												   //COMPULSORY
#include "stm32f0xx.h"											   //COMPULSORY
#include "lcd_stm32f0.h"

// GLOBAL VARIABLES ----------------------------------------------------------|


// FUNCTION DECLARATIONS -----------------------------------------------------|

void main(void);                                                   //COMPULSORY

// MAIN FUNCTION -------------------------------------------------------------|

typedef struct age_data
{
	uint8_t date_of_month;
	uint8_t month_number;
	uint16_t year_of_birth;
} my_age;

// MAIN FUNCTION -------------------------------------------------------------|

void main(void)
{
	struct age_data my_age;
	my_age.date_of_month = 11;
    my_age.month_number  = 5;
    my_age.year_of_birth = 2001;

    struct age_data todays_date;
    todays_date.date_of_month = 6;
    todays_date.month_number  = 3;
    todays_date.year_of_birth  = 2023;


    init_LCD();
    uint8_t counter, age;

    age = todays_date.year_of_birth-my_age.year_of_birth;
    if ((todays_date.month_number - my_age.month_number) < 0) //checks if birth month is lesser than current month
    	age--;
    else if ((todays_date.month_number - my_age.month_number)==0) //if in current month is birth birth month checks if birth date has passed
    {
    	if((todays_date.date_of_month - my_age.date_of_month) < 0)
    		age--;
    }
    else
    {
    	age = todays_date.year_of_birth-my_age.year_of_birth;
    }

	while(1)
	{
		for (counter = 0;counter <=age; counter++)
		{
		if (counter < 10)                      // displays numbers less that 10 on LCD
				lcd_putchar(48 + counter);
			else if (counter < 20)  // displays numbers between 10 and 20 on LCD
			{
				lcd_putchar(48 + 1);
				lcd_putchar(38 + counter);
			}
			else               // displays numbers between 20 and 30 on LCD
			{
				lcd_putchar(48 + 2);
				lcd_putchar(28 + counter);
			}
			delay(100000);
			lcd_command(CLEAR);
		}
	}
}

// OTHER FUNCTIONS -----------------------------------------------------------|
