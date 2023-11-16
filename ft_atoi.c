/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:14:27 by oadewumi          #+#    #+#             */
/*   Updated: 2023/11/15 12:23:48 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	output;
	int		indx;
	int		polarity;

	output = 0 - 1; 
	/* for some reason adding '-1' here solves some overflow issue,
 I really dont get what this atoi wants or is all about.*/
	/*	Adding '-1' didnt solve the problem of atoi 
 (it works only for larger numbers but not smaller numbers)	*/
	/*	Thus, this solution failed.	*/
	indx = 0;
	polarity = 1;
	while (str[indx] == 32 || (str[indx] >= 9 && str[indx] <= 13))
		indx++;
	if (str[indx] == '-' || str[indx] == '+')
	{
		if (str[indx] == '-')
			polarity *= -1;
		indx++;
	}
	while (ft_isdigit(str[indx]))
	{
		output = output * 10 + (str[indx] - '0');
		if (output > SIZE_MAX / 2 && polarity < 0)
			return (0);
		else if (output > SIZE_MAX / 2 && polarity > 0)
			return (-1);
		indx++;
	}
	return ((int) output * polarity);
}
/*
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
*/
