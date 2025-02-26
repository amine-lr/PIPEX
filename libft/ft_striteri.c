/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:54:30 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/20 15:25:22 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void ft_toupper_ifeven(unsigned int i, char *c)
{
	if (i % 2 == 0)
        *c = ft_toupper(*c);
}
int main()
{
char *s1= NULL;
ft_striteri(s1,ft_toupper_ifeven);
printf("%s",s1);
}*/