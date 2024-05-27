/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:05 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:51 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->data->write_mutex);
	elapsed = get_time(MILLISECOND);
	if ((!check_end_simulation(philo->data)) && (TAKE_FIRST_FORK == status
			|| TAKE_SECOND_FORK == status))
		printf("%s%ld %d has taken a fork\n", GREEN, elapsed, philo->id);
	else if (EATING == status && !check_end_simulation(philo->data))
		printf("%s%ld %d is eating\n", WHITE, elapsed, philo->id);
	else if (SLEEPING == status && !check_end_simulation(philo->data))
		printf("%s%ld %d is sleeping\n", PURPLE, elapsed, philo->id);
	else if (THINKING == status && !check_end_simulation(philo->data))
		printf("%s%ld %d is thinking\n", YELLOW, elapsed, philo->id);
	else if (DIED == status && check_end_simulation(philo->data))
		printf("%s%ld %d is dead\n", RED, elapsed, philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
}
