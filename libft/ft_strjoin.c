/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:10:23 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/21 17:53:24 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	tot_len;
	size_t	len_s1;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	tot_len = len_s1 + ft_strlen(s2);
	str = (char *)malloc(tot_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, tot_len + 1);
	return (str);
}
/*int main()
{
	char *s1 = "Brouno";
	char *s2 = "Black";
	printf("%s",ft_strjoin(s1,s2));
}*/