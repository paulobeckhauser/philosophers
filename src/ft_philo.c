/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:18:01 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 21:06:39 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILLISECOND));
	write_status(TAKE_FIRST_FORK, philo);
	while (!check_end_simulation(philo->data))
		ft_usleep(100, philo->data);
	return (NULL);
}

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_nb == 1)
		one_philo(philo);
	if (philo->id % 2 == 0)
		write_status(THINKING, philo);
	philo_routine(philo);
	return (NULL);
}
