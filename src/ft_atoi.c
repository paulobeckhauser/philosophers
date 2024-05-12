/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:57:28 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/12 17:47:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nptr)
{
	int	value_int;
	int	i;
	int	parity;

	value_int = 0;
	i = 0;
	parity = 0;
	if (nptr[i] == '-')
	{
		parity = 1;
		i++;
	}
	if (nptr[i] == '+')
		i++;
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i])
		{
			value_int = (value_int * 10) + (nptr[i] - '0');
			i++;
		}
	}
	if (parity == 1)
		value_int = -value_int;
	return (value_int);
}
