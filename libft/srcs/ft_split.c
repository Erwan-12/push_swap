/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:36:43 by rsk               #+#    #+#             */
/*   Updated: 2024/05/27 10:41:13 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

static int	ft_count_words(char const *str, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*fill_word(char *str, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		str[j] = s[i - word_len];
		j++;
		word_len--;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_spliting_words(char const *s, char c, char **result, int nb_word)
{
	int	i;
	int	word_len;
	int	word;

	i = 0;
	word = 0;
	while (word < nb_word)
	{
		word_len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		result[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[word])
			return (free_array(result, word - 1));
		fill_word(result[word], s, i, word_len);
		word++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	num_words;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	if (!ft_spliting_words(s, c, result, num_words))
		return (NULL);
	result[num_words] = NULL;
	return (result);
}
