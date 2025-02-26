/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:56:20 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/13 14:00:51 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	if (!src)
		return (0);
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dest_size)
		return (src_size + dstsize);
	i = 0;
	while (src[i] && (dest_size + i) < (dstsize - 1))
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (dest_size + src_size);
}
/*int	main(void)
{
	char *dst = NULL;
	char *src = NULL;

	if (!dst)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	dst[0] = '\0';
	
	printf("%zu\n", ft_strlcat(dst, src, 15));
	printf("%s\n", dst);
}*/
