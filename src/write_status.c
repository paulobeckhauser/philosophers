/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:05 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:04:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND);
	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->data->write_mutex);
	if ((!check_end_simulation(philo->data)) && (TAKE_FIRST_FORK == status
			|| TAKE_SECOND_FORK == status))
		printf("%ld  %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !check_end_simulation(philo->data))
		printf("%ld  %d is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !check_end_simulation(philo->data))
		printf("%ld  %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !check_end_simulation(philo->data))
		printf("%ld  %d is thinking\n", elapsed, philo->id);
	else if (DIED == status && check_end_simulation(philo->data))
		printf("%ld  %d is dead\n", elapsed, philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
}
