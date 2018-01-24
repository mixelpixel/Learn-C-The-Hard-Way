#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;        // <--- DECIMAL %d %i
	// int distance = 0x64;    // <--- HEXADECIMAL Hex integer %x %X
	// int distance = 0144;    // <--- OCTAL %o
	float power = 2.345f;      // <--- trailing f is required for floats
	double super_power = 56789.4532;
	// char initial = A;
	// char initial = "A";     // <--- double quotes result in an integer assignment
	char initial = 'A';        // <--- single quote for a char
	char first_name[] = "Zed"; // <--- double quote for char[] (strings)
	char last_name[] = "Shaw"; // <--- double quote for char[] (strings)

	printf("You are %d miles away.\n", distance);
	// printf("You are %x miles away.\n", distance);
	// printf("You are %o miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s. \n", last_name);
	printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
	// printf("My whole name is %s %c %s.\n", initial, first_name, last_name); // <--- segmentation fault

	return 0;
}
