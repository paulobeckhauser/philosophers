/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:16 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 21:07:21 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	time_to_die = philo->data->time_to_die - 1;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_data	*table;

	table = (t_data *)data;
	while (!check_end_simulation(table))
	{
		i = 0;
		while (i < table->philo_nb && !check_end_simulation(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->data_mutex, &table->end_simulation, true);
				write_status(DIED, table->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}
