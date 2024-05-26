/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:05:18 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:07:10 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}
