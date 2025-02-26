/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:19:07 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/20 14:43:23 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*char transform(unsigned int index, char c)
{
    return (char)ft_toupper(c + index);
}

int main(void)
{
    char *input = NULL;
    char *result = ft_strmapi(input, transform);
    if (result)
    {
        printf("Transformed string: %s\n", result);
        free(result);
    }
    else
        printf("Error: ft_strmapi returned NULL.\n");
    return 0;
}*/