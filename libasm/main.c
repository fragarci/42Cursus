#include <unistd.h>
#include <stdio.h>
#include <errno.h>

extern int ft_read(int fd, void *buf, unsigned int count);
extern int ft_write(unsigned int fd, const void *buf, unsigned int count);

int	main(void)
{
	int write_test;

	dprintf(1, "##### ft_write tests #####\n");
	dprintf(1, "ft_write stdout print: ");
	write_test = ft_write(1, "Hola Mundo\n", 11);
	dprintf(1, "return value: %d\n", write_test);
	dprintf(1, "errno test with: ft_write(69, \"69\", 2);\n");
	write_test = ft_write(69, "69", 2);
	dprintf(1, "return value: %d\nerrno: %d\n", write_test, errno);
	dprintf(1, "perror: ");
	perror("ft_write");

	dprintf(1, "\nwrite stdout print: ");
	write_test = write(1, "Hola Mundo\n", 11);
	dprintf(1, "return value: %d\n", write_test);
	dprintf(1, "errno test with: write(69, \"69\", 2);\n");
	write_test = write(69, "69", 2);
	dprintf(1, "return value: %d\nerrno: %d\n", write_test, errno);
	dprintf(1, "perror: ");
	perror("write");
	return (0);
}