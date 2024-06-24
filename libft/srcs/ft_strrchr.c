/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:43:06 by rsk               #+#    #+#             */
/*   Updated: 2024/05/27 10:29:38 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	c = (char)c;
	while (*s != '\0')
	{
		if (*s == c)
			result = ((char *)s);
		s++;
	}
	if (c == '\0')
		result = ((char *)s);
	return (result);
}
