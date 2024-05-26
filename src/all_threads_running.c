/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_threads_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:19:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 19:19:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Monitor waits untill all threads running
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nb)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(mutex);
	if (*threads == philo_nb)
		ret = true;
	pthread_mutex_unlock(mutex);
	return (ret);
}
