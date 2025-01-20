#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

extern unsigned int	ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern int ft_write(unsigned int fd, const void *buf, unsigned int count);
extern int ft_read(int fd, void *buf, unsigned int count);
extern char *ft_strdup(const char *s);

void	ft_test_strlen(void)
{
	char	*str = "Hola Mundo!";
	unsigned int	strlen_test;

	printf("\n##### ft_strlen tests #####\n");
	strlen_test = ft_strlen(str);
	printf("ft_strlen:\t%d\n", strlen_test);
	strlen_test = strlen(str);
	printf("strlen:\t\t%d\n", strlen_test);
}

void	ft_test_strcpy(void)
{
	char dest[13];
	char *src = "Hello World!";
	char *ret;

	printf("\n##### ft_strcpy tests #####\n");
	ret = ft_strcpy(dest, src);
	printf("ft_strcpy test:\tdest_str: %s, src_str: %s, dest_addr: %p, return_addr: %p\n", dest, src, dest, ret);
	memset(dest, 0, 13);
	ret = strcpy(dest, src);
	printf("strcpy test:\tdest_str: %s, src_str: %s, dest_addr: %p, return_addr: %p\n", dest, src, dest, ret);
}

void	ft_test_strcmp(void)
{
	int		strcmp_test;

	printf("\n##### ft_strcmp tests #####\n");
	strcmp_test = ft_strcmp("str1", "str1");
	printf("ft_strcmp equal test:\t%d\n",strcmp_test);
	strcmp_test = ft_strcmp("str2", "str1");
	printf("ft_strcmp first diff:\t%d\n",strcmp_test);
	strcmp_test = ft_strcmp("str1", "str2");
	printf("ft_strcmp second diff:\t%d\n",strcmp_test);
	strcmp_test = ft_strcmp("str1", "str");
	printf("ft_strcmp length diff:\t%d\n",strcmp_test);
	strcmp_test = ft_strcmp("", "");
	printf("ft_strcmp empty string:\t%d\n",strcmp_test);

	strcmp_test = strcmp("str1", "str1");
	printf("\nstrcmp equal test:\t%d\n",strcmp_test);
	strcmp_test = strcmp("str2", "str1");
	printf("strcmp first diff:\t%d\n",strcmp_test);
	strcmp_test = strcmp("str1", "str2");
	printf("strcmp second diff:\t%d\n",strcmp_test);
	strcmp_test = strcmp("str1", "str");
	printf("strcmp length diff:\t%d\n",strcmp_test);
	strcmp_test = strcmp("", "");
	printf("strcmp empty string:\t%d\n",strcmp_test);
}

void ft_test_write(void)
{
	int write_test;

	dprintf(1, "\n##### ft_write tests #####\n");
	dprintf(1, "ft_write stdout print:\t");
	write_test = ft_write(1, "Hola Mundo\n", 11);
	dprintf(1, "return value:\t\t%d\n", write_test);
	dprintf(1, "errno test with: ft_write(69, \"69\", 2);\n");
	write_test = ft_write(69, "69", 2);
	dprintf(1, "return value:\t\t%d\nerrno:\t\t\t%d\n", write_test, errno);
	dprintf(1, "perror:\t\t\t");
	perror("ft_write");

	dprintf(1, "\nwrite stdout print:\t");
	write_test = write(1, "Hola Mundo\n", 11);
	dprintf(1, "return value:\t\t%d\n", write_test);
	dprintf(1, "errno test with: write(69, \"69\", 2);\n");
	write_test = write(69, "69", 2);
	dprintf(1, "return value:\t\t%d\nerrno:\t\t\t%d\n", write_test, errno);
	dprintf(1, "perror:\t\t\t");
	perror("write");
}

void	ft_test_read(void)
{
	char	buff[17];
	int		read_test;
	int		fd;

	printf("\n##### ft_read tests #####\n");
	fd = open("read_test.txt", O_RDONLY);
	if (fd == -1)
		return (perror("unexpected error"));
	read_test = ft_read(fd, buff, 16);
	buff[17] = 0;
	printf("buff:\t\t%s\nreturn value:\t%d\n", buff, read_test);
	close(fd);
	printf("errno test with closed file\n");
	read_test = ft_read(fd, buff, 16);
	printf("return value\t%d\n", read_test);
	perror("ft_read");

	fd = open("read_test.txt", O_RDONLY);
	if (fd == -1)
		return (perror("unexpected error"));
	read_test = read(fd, buff, 16);
	buff[17] = 0;
	printf("\nbuff:\t\t%s\nreturn value:\t%d\n", buff, read_test);
	close(fd);
	printf("errno test with closed file\n");
	read_test = read(fd, buff, 16);
	printf("return value\t%d\n", read_test);
	perror("read");
}

void ft_test_strdup(void)
{
	char	*ret;

	printf("\n##### ft_strdup tests #####\n");
	ret = ft_strdup("Hola Mundo!");
	printf("ft_strdup:\t%s\n", ret);
	free(ret);
	ret = strdup("Hola Mundo!");
	printf("strdup:\t\t%s\n", ret);
	free(ret);
}

int	main(void)
{
	ft_test_strlen();
	ft_test_strcpy();
	ft_test_strcmp();
	ft_test_write();
	ft_test_read();
	ft_test_strdup();
	return (0);
}