/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:36:04 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/20 14:04:42 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (!c)
		return (0);
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*int main() {
    char ch = 0;
    
    if (!ch)
		printf("NULL");
	else
    printf(" %c\n", ft_tolower(ch));
    return 0;
}*/
