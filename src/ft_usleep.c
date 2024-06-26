/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:34:46 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:04:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_usleep(long msec, t_data *data)
{
	long	start_time;
	long	elapsed_time;

	start_time = get_time(1);
	elapsed_time = start_time;
	while ((elapsed_time - start_time) < msec)
	{
		if (check_end_simulation(data))
			break ;
		if (msec - (elapsed_time - start_time) > 10)
			usleep((msec - (elapsed_time - start_time)) * 500);
		elapsed_time = get_time(1);
	}
}
