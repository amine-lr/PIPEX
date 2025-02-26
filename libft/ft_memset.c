/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:02:39 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/13 14:04:59 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*void_ptr;

	if (!ptr)
		return (NULL);
	void_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		void_ptr[i] = c;
		i++;
	}
	return (ptr);
}
/*int main(void) 
{
	char str[] = "Brouno";
	//char *str = NULL; 

	ft_memset(str, '8', 5);
	if (!str)
		printf("Received NULL pointer.\n");
	else
		printf("%s\n", str);
}*/
