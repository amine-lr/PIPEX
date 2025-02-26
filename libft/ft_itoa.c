/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:13:17 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/25 16:55:42 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*str;
	long	nbr;

	len = count_size(num);
	nbr = num;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[len--] = '\0';
	while (nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		len--;
		nbr /= 10;
	}
	return (str);
}
/*int	main()
{
	int n;

	n = -123;
	printf("%s", ft_itoa(n));
}*/