#include "main.h"

/**
 * create_file - Program that create a file.
 * @filename: The filename.
 * @text_content: The content written in the text.
 *
 * Return: ...
 */
int create_file(const char *filename, char *text_content)
{
	int file_t;
	int rletters;
	int qwr;

	if (!filename)
	return (-1);

	file_t = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_t == -1)
	return (-1);

	if (!text_content)
	text_content = "";

	for (rletters = 0; text_content[rletters]; rletters++)
	;

	qwr = write(file_t, text_content, rletters);

	if (qwr == -1)
	return (-1);

	close(file_t);

	return (1);
}
