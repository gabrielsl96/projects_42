#ifndef FILE_H
#define FILE_H
#include <stddef.h>

    void    *ft_memset(void *s, int c, size_t n);
    void    ft_bzero(void *s, size_t n);
    void    *ft_memcpy(void *dest, const void *src, size_t n);
    void    *ft_memccpy(void *dest, const void *src, int c, size_t n);
#endif