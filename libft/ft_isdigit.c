/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:35:22 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/19 15:07:54 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int main()
{
    int bla = '2';
    int A = 'S';
    int B = '9';
    int f = 0;

    printf("%d.\n", ft_isdigit(bla));
    printf("%d.\n", ft_isdigit(A));
    printf("%d.\n", ft_isdigit(B));
    printf("%d.\n", ft_isdigit(f));
    return (0);
}*/
