/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:16:43 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 11:24:28 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	init_vars(int argc, char *argv[], t_info *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->nb_food = 0;
	if (argc == 6)
		data->nb_food = ft_atoi(argv[5]);
	
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (printf("Memory allocation fail!\n"), false);
	data->dead = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->ate, NULL);
	gettimeofday(&data->time, NULL);
	init_philo(data);
	return (true);
}
