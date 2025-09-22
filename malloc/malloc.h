#ifndef MALLOC_H
# define MALLOC_H

# include <sys/resource.h> // getrlimit
# include <sys/mman.h> // mmap/munmap
# include <stddef.h> // size_t
# include <unistd.h> // getpagesize

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

#endif
