/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:43:33 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/20 14:34:41 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	tr_len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (len && ft_strrchr(set, s1[len - 1]))
		len --;
	tr_len = len - i;
	return (ft_substr(s1, i, tr_len));
}
/*int	main ()
{
	char *str = "amine";
	char *set = NULL;
	printf("%s", ft_strtrim(str,set));
}*/