/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:47:47 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 19:20:08 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*

[time_ms] [philo_id] [action]


thread safe
*/

void write_status(t_philo_status status, t_philo *philo)
{
    long elapsed;
    
    elapsed = gettime(MILLISECOND);
    
    if (philo->if_full) //thread safe
        return ;
    
    mutex_handle(&philo->data->write_mutex, LOCK);
    
    if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK) 
        && !check_simulation_finished(philo->data))
        printf("%ld  %d has taken a fork\n", elapsed, philo->id);
    
    else if (status == EATING && !check_simulation_finished(philo->data))
        printf("%ld  %d is eating\n", elapsed, philo->id);
    
    
    else if (status == SLEEPING && !check_simulation_finished(philo->data))
        printf("%ld  %d is sleeping\n", elapsed, philo->id);
    
    else if (status == THINKING && !check_simulation_finished(philo->data))
        printf("%ld  %d is thinking\n", elapsed, philo->id);
    
    else if (status == DIED && !check_simulation_finished(philo->data))
        printf("%ld  %d is dead\n", elapsed, philo->id);
    
    
    mutex_handle(&philo->data->write_mutex, UNLOCK);
    
}