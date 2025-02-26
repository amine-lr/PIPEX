/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:19:05 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/25 16:54:15 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t elements_size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(num_elements * elements_size);
	if (!temp)
		return (NULL);
	while (i < num_elements * elements_size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
/*int	main()
{
	size_t	num = 6;
	size_t	size = sizeof(char) ;
	printf("%s\n", (char *)ft_calloc(num, size));
}*/