#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO_stat(int stat, int fd, char *filename, char mode);
/**
 * main - ...
 * @argc: ...
 * @argv: ...
 *
 * Return: ...
 */
int main(int argc, char *argv[])
{
	int sra, dest, r_read = 1024, wrote, close_sra, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buff[1024];

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "%s", "usage: cp file_from file_to\n");
	exit(97);
	}
	sra = open(argv[1], O_RDONLY);
	check_IO_stat(sra, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(dest, -1, argv[2], 'w');
	while (r_read == 1024)
	{
	r_read = read(sra, buff, sizeof(buff));
	if (r_read == -1)
	check_IO_stat(-1, -1, argv[1], 'O');
	wrote = write(dest, buff, r_read);
	if (wrote == -1)
	check_IO_stat(-1, -1, argv[2], 'W');
	}
	close_sra = close(sra);
	check_IO_stat(close_sra, sra, NULL, 'C');
	close_dest = close(dest);
	check_IO_stat(close_dest, dest, NULL, 'C');
	return (0);
}
/**
 * check_IO_stat - ...
 * @stat: ...
 * @filename: ...
 * @mode: ...
 * @fd: ...
 *
 * Return: ...
 */
void check_IO_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", filename);
	exit(90);
	}
	else if (mode == 'W' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(90);
	}
}
