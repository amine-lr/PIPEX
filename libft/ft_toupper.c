/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:24:36 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/11 10:45:07 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (!c)
		return (0);
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*int	main()
{
	char ch = 'r';

	if (!ch)
		printf("NULL");
	else
    	printf("Uppercase of %c is %c\n", ch, ft_toupper(ch));
    return (0);
}*/
