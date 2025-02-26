/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:20:08 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/20 15:35:26 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	size_t	i;
	char	a;

	if (!s)
		return (NULL);
	i = 0;
	a = (char)c;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *) &s[i]);
		i++;
	}
	if (a == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
/*int main()
{
    char c = 'l';
    const char *s= "amine bla";

	if (!s)
		printf ("NULL");
    char    *rslt = ft_strchr(s, c);
    if (rslt != NULL)
        printf("Character %c found in %s: %s\n", c, s, rslt);
    else
        printf("Character %c not fount in %s\n", c, s);
    return (0);
}*/
