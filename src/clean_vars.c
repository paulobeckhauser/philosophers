/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:35:49 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/21 10:53:03 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// destroy the mutex's and free the elements

void	clean_vars(t_info *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = data->philos + i;
		pthread_mutex_destroy(&philo->philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->table_mutex);
	free(data->forks);
	free(data->philos);
}
