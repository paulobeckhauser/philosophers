/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:05:49 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:07:26 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}
