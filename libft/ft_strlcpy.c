/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:49:32 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/13 13:55:03 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize -1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*int main(void)
{
    char *src = "Amine";
    char dst[20];
    size_t ret;

	if (!src || !dst)
		printf("NULL\n");
	else
	{
    	ret = ft_strlcpy(dst, src, sizeof(dst));
    	printf("Destination: '%s'\n", dst);
    	printf("Returned length of src: %zu\n", ret);
    	ret = ft_strlcpy(dst, src, 6);
    	printf("destination: '%s'\n", dst);
    	printf("Returned length of src: %zu\n", ret);
	}
    return 0;
}*/
