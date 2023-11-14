#include "main.h"
/**
 * main - entry point 
 *@argc: counter
 *@argv: array of string
 * Return: exit succuss
 */

int main(int argc, char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		intc();
	}
	else
	{
		non_int();
	}
	(void)(argc);
	(void)(argv);
	return (0);
}
