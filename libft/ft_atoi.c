/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:45:46 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/19 14:49:13 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	rst;

	i = 0;
	s = 1;
	rst = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rst = (rst * 10) + (str[i] - '0');
		i++;
	}
	return (rst * s);
}
/*int	main()
{
	const char	*str1 = NULL;
	const char	*str2 = "      \n	-2465rfrrg";

	int	num1 = ft_atoi(str1);
	int	num2 = ft_atoi(str2);
	printf("converted number : %d\n", num1);
	printf("converted number : %d\n", num2);
	return (0);
}*/
