/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:31:12 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 19:32:56 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_data(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->philo_nb)
	{
		philo = data->philos + i;
		pthread_mutex_destroy(&philo->philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->data_mutex);
	free(data->philos);
	free(data->forks);
}
