#include "main.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Program that read the text file and print it to the stdio.
 *
 * @filename: The name of the file to be read.
 *
 * @letters: The num of letter it should read and print.
 *
 * Return: ...
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_t;
	ssize_t lenq, lenv;
	char *buff;

	if (filename == NULL)
	return (0);
	file_t = open(filename, O_RDONLY);
	if (file_t == -1)
	return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
	close(file_t);
	return (0);
	}
	lenq = read(file_t, buff, letters);
	close(file_t);
	if (lenq == -1)
	{
	free(buff);
	return (0);
	}
	lenv = write(STDOUT_FILENO, buff, lenq);
	free(buff);
	if (lenq != lenv)
	return (0);
	return (lenv);
}
