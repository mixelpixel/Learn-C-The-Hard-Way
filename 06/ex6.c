#include <stdio.h>

int main(int argc, char *argv[])
{
	// int distance = 100; // DECIMAL %d %i
	// int distance = 0x64; // HEXADECIMAL Hex integer %x %X
	int distance = 0144; // OCTAL %o
	float power = 2.345f;
	double super_power = 56789.4532;
	// char initial = A;
	// char initial = "A";
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	printf("You are %d miles away.\n", distance);
	// printf("You are %x miles away.\n", distance);
	// printf("You are %o miles away.\n", distance);
	printf("You have %f levels of poser.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s. \n", last_name);
	printf("My whole name is %s %c %s.\n", first_name, initial, last_name);
	// printf("My whole name is %c %s %s.\n", first_name, initial, last_name);

	return 0;
}
