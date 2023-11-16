/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_beta_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:19:26 by oadewumi          #+#    #+#             */
/*   Updated: 2023/11/16 17:12:51 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	nbr;
	int		polarity;

	nbr = 0;
	polarity = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			polarity *= -1;
	}
	while (ft_isdigit(*str))
	{
		if (nbr > FT_LONG_MAX / 10 || (nbr == FT_LONG_MAX / 10 && *str > '7'))
		{
			if (polarity > 0)
				return (-1);
			else
				return (0);
		}
		nbr = nbr * 10 + (*(str++) - '0');
	}
	return ((int) nbr * polarity);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int	mine;
	int	org;

	if (ac == 2)
	{
		mine = ft_atoi(av[1]);
		org = atoi(av[1]);
		printf("mine: %d | org: %d\n", mine, org);
	}
	return (0);
}