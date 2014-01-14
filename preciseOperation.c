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

float sub(float number1, float number2)
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

	mpf_sub(result, mpf_number1, mpf_number2);
	
	return mpf_get_d(result);
}

float myPow(float base, float exponent)
{
	char stringBase[25], stringExponent[10];
	mpf_t mpf_base, mpf_exponent, result;
	mpir_ui mpir_exponent;

	sprintf(stringBase, "%.20f", base);
	sprintf(stringExponent, "%f", exponent);

	mpf_init(mpf_base);
	mpf_init(mpf_exponent);
	mpf_init(result);

	mpf_set_str(mpf_base, stringBase, 10);
	mpf_set_str(mpf_exponent, stringExponent, 10);

	mpir_exponent = mpf_get_ui(mpf_exponent);

	mpf_pow_ui(result, mpf_base, mpir_exponent);
	
	return (float) mpf_get_d(result);
}
