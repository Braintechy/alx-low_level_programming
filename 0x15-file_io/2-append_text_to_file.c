#include "main.h"

/**
 * append_text_to_file - Program that append the end of a text in a file.
 * @filename: The filename.
 * @text_content: The file content.
 *
 * Return: ...
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_t;
	int rletters;
	int qwr;

	if (!filename)
	return (-1);

	file_t = open(filename, O_WRONLY | O_APPEND);

	if (file_t == -1)
	return (-1);

	if (text_content)
	{
	for (rletters = 0; text_content[rletters]; rletters++)
	;

	qwr = write(file_t, text_content, rletters);

	if (qwr == -1)
	return (-1);
	}

	close(file_t);

	return (1);
}
