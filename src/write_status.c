/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:29:24 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 14:31:00 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void write_status(char *str, t_philo *philo, int id)
{
    size_t time;

    pthread_mutex_lock(philo->write_lock);
    time = get_current_time() - philo->start_time;

    if (!dead_loop(philo))
        printf("%zu %d %s\n", time, id, str);
    pthread_mutex_unlock(philo->write_lock);
}
