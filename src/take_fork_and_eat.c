/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork_and_eat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:17 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 10:40:28 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int take_fork_and_eat(t_philo * philo)
{
    t_philo *philo_next;

    if (philo->data->nb_philo == 1)
        ft_usleep(philo->data->time_die);
        
    philo_next = &philo->data->philo[philo->id_next];
    if (compare_philo_id(philo) == 1)
        return (1);
    write_status(philo, "has taken a fork");
    write_status(philo, "is eating");
    philo->last_meal = get_time(philo->data->time);
    ft_usleep(philo->data->time_eat);
    pthread_mutex_unlock(&philo->data->philo[philo->id].fork);
    pthread_mutex_unlock(&philo->data->philo[philo->id_next].fork);
    return (0);
}
