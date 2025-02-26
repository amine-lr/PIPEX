#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t  i;
    unsigned char   *dst_c;
    unsigned const char *src_c;

    dst_c = (unsigned char *)dst;
    src_c = (unsigned const char *)src;
    if (dst == NULL && src == NULL)
        return (NULL);
    i = 0;
    while (i < n)
    {
        dst_c[i] = src_c [i];
        i++;
    }
    return (dst_c);
}
/*int main()
{
    char    *src = "sniper";
    char    *dst;

    ft_memcpy(dst, src, 6);
    printf("src: %s\n", src);
    printf("dst: %s\n", dst);
    return 0;
}*/