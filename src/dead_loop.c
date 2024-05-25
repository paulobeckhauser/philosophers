/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:34:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 15:37:11 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int dead_loop(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
        return (pthread_mutex_unlock(philo->dead_lock), 1);
    pthread_mutex_unlock(philo->dead_lock);
    return (0);
}
