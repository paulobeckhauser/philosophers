/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:24 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:30:41 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_dinner(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	set_bool(&data->data_mutex, &data->end_simulation, true);
	pthread_join(data->monitor, NULL);
}

static void	start_dinner(t_data *data)
{
	int	i;

	i = 0;
	if (data->limit_meals == 0)
		return ;
	else if (data->philo_nb == 1)
		pthread_create(&data->philos[0].thread, NULL, ft_philo,
			&data->philos[0]);
	else
	{
		while (i < data->philo_nb)
		{
			pthread_create(&data->philos[i].thread, NULL, ft_philo,
				&data->philos[i]);
			i++;
		}
	}
	pthread_create(&data->monitor, NULL, monitor_dinner, data);
	data->start_simulation = get_time(MILLISECOND);
}

void	dinner_simulation(t_data *data)
{
	start_dinner(data);
	end_dinner(data);
}
