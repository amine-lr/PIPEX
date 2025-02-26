/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:38:51 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/25 16:56:07 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > strlen)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > strlen - start)
		len = strlen - start;
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	substr[len + 1] = '\0';
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/*int main()
{
	char *str = "NULL";
	int start = 0;
	size_t len = 4;
	char *result = ft_substr(str, start, len);
	if (!result)
		printf("NULL\n");
	else
		printf("%s\n",result);
}*/