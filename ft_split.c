/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:28:55 by oadewumi          #+#    #+#             */
/*   Updated: 2023/11/28 17:52:32 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_substr_poll(char const *str, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;

	while (*str)
	{
		if (*str != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*str == c && in_substring > 0)
		{
			in_substring = 0;
		}
		str++;
	}
	return (count);
}

static char	**ft_free_function(char **s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (0);
}

static char	**making_substr(char **split_res, char const *s, char c)

{
	size_t	start;
	size_t	len;
	size_t	j;

	start = 0;
	j = 0;
	while (s[start] != '\0' && j < ((size_t)ft_substr_poll(s, c))) // this J<(typecasted) ft_substr_polls is to prevent the array indexing from going over the limit of the array.
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] == '\0')
			return (split_res);
		len = start;
		while (s[len] != c && s[len] != '\0')
			len++;
		split_res[j++] = ft_substr(s, start, (len - start));
		if (!split_res[j])
			return (ft_free_function(split_res));
		start = len;
	}
	split_res[j++] = NULL; // This here is to stopthe array index from going beyond the limit of the array
	return (split_res);
}

char	**ft_split(char const *s, char c)
{
	char	**split_res;
	// size_t	start;
	// size_t	len;
	// size_t	j;

	// start = 0;
	// j = 0;
	split_res = (char **)malloc((ft_substr_poll(s, c) + 1) * sizeof(char *));
	if (!split_res)
		return (0);
	// while (s[start] != '\0' && j < ((size_t)ft_substr_poll(s, c)))
	// {
	// 	while (s[start] == c && s[start] != '\0')
	// 		start++;
	// 	if (s[start] == '\0')
	// 		return (split_res);
	// 	len = start;
	// 	while (s[len] != c && s[len] != '\0')
	// 		len++;
	// 	split_res[j++] = ft_substr(s, start, (len - start));
	// 	if (!split_res[j])
	// 		return (ft_free_function(split_res));
	// 	start = len;
	// }
	// split_res[j++] = NULL;
	split_res = making_substr(split_res, s, c);
	return (split_res);
}

#include <stdio.h>

int	main(void)
{
	char const	str[] = "-Hello-gentle-world-";
	char		d;
	char		**res;

	d = '-';
	res = ft_split(str, d);
	while (*res != 0)
	{
		printf("%s\n", *res);
		res++;
	}
}
