#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

extern unsigned int	ft_strlen(const char *s);
extern int ft_strcmp(const char *s1, const char *s2);
extern int ft_read(int fd, void *buf, unsigned int count);
extern int ft_write(unsigned int fd, const void *buf, unsigned int count);

void	ft_test_strlen(void)
{
	char	*str = "Hola Mundo!";
	unsigned int	strlen_test;

	printf("\n##### ft_strlen tests #####\n");
	strlen_test = ft_strlen(str);
	printf("ft_strlen: %d\n", strlen_test);
	strlen_test = strlen(str);
	printf("strlen: %d\n", strlen_test);
}

void	ft_test_read(void)
{
	char	buff[64];
	int		read_test;
	int		fd;

	printf("\n##### ft_read tests #####\n");
	fd = open("read_test.txt", O_RDONLY);
	if (fd == -1)
		return (perror("unexpected error"));
	read_test = ft_read(fd, buff, 16);
	printf("buff: %s\nreturn value: %d\n", buff, read_test);
	close(fd);
	printf("errno test with closed file\n");
	read_test = ft_read(fd, buff, 16);
	printf("return value %d\n", read_test);
	perror("ft_read");

	fd = open("read_test.txt", O_RDONLY);
	if (fd == -1)
		return (perror("unexpected error"));
	read_test = read(fd, buff, 16);
	printf("\nbuff: %s\nreturn value: %d\n", buff, read_test);
	close(fd);
	printf("errno test with closed file\n");
	read_test = read(fd, buff, 16);
	printf("return value %d\n", read_test);
	perror("read");
}

void ft_test_write(void)
{
	int write_test;

	dprintf(1, "\n##### ft_write tests #####\n");
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
}

int	main(void)
{
	int		strcmp_test;

	dprintf(1, "\n##### ft_strcmp tests #####\n");
	strcmp_test = ft_strcmp("str1", "str1");
	printf("ft_strcmp equal test: %d\n",strcmp_test);
	strcmp_test = ft_strcmp("str2", "str1");
	printf("ft_strcmp first diff: %d\n",strcmp_test);
	strcmp_test = ft_strcmp("str1", "str2");
	printf("ft_strcmp second diff: %d\n",strcmp_test);
	strcmp_test = ft_strcmp("str1", "str");
	printf("ft_strcmp length diff: %d\n",strcmp_test);
	strcmp_test = ft_strcmp("", "");
	printf("ft_strcmp empty string: %d\n",strcmp_test);

	strcmp_test = strcmp("str1", "str1");
	printf("\nstrcmp equal test: %d\n",strcmp_test);
	strcmp_test = strcmp("str2", "str1");
	printf("strcmp first diff: %d\n",strcmp_test);
	strcmp_test = strcmp("str1", "str2");
	printf("strcmp second diff: %d\n",strcmp_test);
	strcmp_test = strcmp("str1", "str");
	printf("strcmp length diff: %d\n",strcmp_test);
	strcmp_test = strcmp("", "");
	printf("strcmp empty string: %d\n",strcmp_test);
	return (0);
}