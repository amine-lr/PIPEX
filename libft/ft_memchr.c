/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:05:54 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/13 14:09:50 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_c;

	if (!s)
		return (NULL);
	i = 0;
	s_c = (unsigned char *)s;
	while (i < n)
	{
		if (s_c[i] == (unsigned char)c)
			return (s_c + i);
		i++;
	}
	return (NULL);
}
/*int main()
{
    char    *data = NULL;
    char    *rst ;

    rst = (char *)ft_memchr(data, 'l', 10);
    if (rst)
        printf("found the characther at position : %ld\n", rst - data);
	else
		printf("charachter not found");
    return (0);
}*/
