/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 21:06:43 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->philo_nb)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meal_counter = 0;
		philo->data = data;
		philo->last_meal_time = get_time(MILLISECOND);
		pthread_mutex_init(&philo->philo_mutex, NULL);
		assign_forks(philo, data->forks, i);
	}
}

bool	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->end_simulation = false;
	data->philos = malloc(data->philo_nb * sizeof(t_philo));
	data->forks = malloc(data->philo_nb * sizeof(t_fork));
	if (!data->philos || !data->forks)
		return (printf("Memory allocation fail!\n"), false);
	pthread_mutex_init(&data->data_mutex, NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	while (i < data->philo_nb)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		data->forks->fork_id = i;
		i++;
	}
	philo_init(data);
	return (true);
}
