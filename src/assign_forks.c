/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:20:33 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 19:56:56 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nb;

	philo_nb = philo->data->philo_nb;
	philo->first_fork = &forks[(philo_position + 1) % philo_nb];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nb];
	}
}
