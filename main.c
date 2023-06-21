#include "monty.h"

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: an array of arguments
 * Return: 0 if successfull
 */

int main(int argc, char *argv[])
{
	char *file_path;

	file_path = argv[1];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_file(file_path);
	return (0);
}
