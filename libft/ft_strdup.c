/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:07:38 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/20 15:27:46 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	dst = (char *) malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
/*int	main()
{
	char	*s1 = NULL;
	
	if (!s1)
		printf("NULL");
	else
		printf("%s\n", ft_strdup(s1));
}*/