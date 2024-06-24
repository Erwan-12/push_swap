/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:17:22 by rsk               #+#    #+#             */
/*   Updated: 2024/05/27 10:06:50 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *string)
{
	int	sign;
	int	number;

	sign = 1;
	while (is_whitespace(*string))
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	number = 0;
	while (*string != '\0' && (*string >= '0' && *string <= '9'))
	{
		number = number * 10 + *string - '0';
		string++;
	}
	return (number * sign);
}
