/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:17 by oadewumi          #+#    #+#             */
/*   Updated: 2023/11/13 14:03:11 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*	AI	*/
//size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	remaining_space;

// 	remaining_space = dstsize - strlen(dst) - 1;
// 	while (*src != '\0' && remaining_space > 0)
// 	{
// 		dst[strlen(dst)] = *src;
// 		src++;
// 		remaining_space--;
// 	}
// 	dst[strlen(dst)] = '\0';
// 	return (strlen(dst) + strlen(src));
// }

/*	from Github by old HIVE student	*/
// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	char	*s;
// 	size_t	l_dst;
// 	size_t	res;
// 	size_t	l_src;
// 	size_t	i;

// 	l_dst = 0;
// 	l_src = 0;
// 	s = (char *)src;
// 	while (dst[l_dst] != '\0')
// 		l_dst++;
// 	while (s[l_src] != '\0')
// 		l_src++;
// 	res = 0;
// 	i = 0;
// 	if (size > l_dst)
// 		res = l_src + l_dst;
// 	else
// 		res = l_src + size;
// 	while (s[i] && (l_dst + 1) < size)
// 	{
// 		dst[l_dst] = s[i];
// 		l_dst++;
// 		i++;
// 	}
// 	dst[l_dst] = '\0';
// 	return (res);
// }

#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	d[70] = "Hello, you are doing alright";
	char	s[] = ", yes it is true";
	int	t = 20;

	printf("%zu\n", ft_strlcat(d, s, t));
	printf("%s\n", d);

	char	dx[70] = "Hello, you are doing alright";
	char	sx[] = ", yes it is true";
	int		tx = 20;

	int		a = strlcat(dx, sx, tx);

	printf("%d\n", a);
	printf("%s\n", dx);

}
