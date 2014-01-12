#include "preciseOperation.h"

float mul(float number1, float number2)
{
	char stringNumber1[25], stringNumber2[25];
	mpf_t mpf_number1, mpf_number2, result;

	sprintf(stringNumber1, "%.20f", number1);
	sprintf(stringNumber2, "%.20f", number2);

	mpf_init(mpf_number1);
	mpf_init(mpf_number2);
	mpf_init(result);

	mpf_set_str(mpf_number1, stringNumber1, 10);
	mpf_set_str(mpf_number2, stringNumber2, 10);

	mpf_mul(result, mpf_number1, mpf_number2);
	
	return mpf_get_d(result);
}

float add(float number1, float number2)
{
	char stringNumber1[25], stringNumber2[25];
	mpf_t mpf_number1, mpf_number2, result;

	sprintf(stringNumber1, "%.20f", number1);
	sprintf(stringNumber2, "%.20f", number2);

	mpf_init(mpf_number1);
	mpf_init(mpf_number2);
	mpf_init(result);

	mpf_set_str(mpf_number1, stringNumber1, 10);
	mpf_set_str(mpf_number2, stringNumber2, 10);

	mpf_add(result, mpf_number1, mpf_number2);
	
	return mpf_get_d(result);
}

