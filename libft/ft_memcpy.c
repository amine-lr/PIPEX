/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:06:03 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/30 15:19:53 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	char		*s;

	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dst);
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
