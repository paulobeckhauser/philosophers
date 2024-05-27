/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:26:00 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/27 18:13:57 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

	// THINKING routine  
void	thinking(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		write_status(THINKING, philo);
	if (philo->data->philo_nb % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think, philo->data);
}

static	void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_status(TAKE_FIRST_FORK, philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILLISECOND));
	philo->meal_counter++;
	write_status(EATING, philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->limit_meals > 0
		&& philo->meal_counter == philo->data->limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

void	*philo_routine(t_philo *philo)
{
	while (!check_end_simulation(philo->data))
	{
		if (philo->full)
			break ;
		eating(philo);
		write_status(SLEEPING, philo);
		ft_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo, false);
	}
	return (NULL);
}
