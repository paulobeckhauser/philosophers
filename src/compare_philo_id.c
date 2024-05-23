/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_philo_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:23:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 10:37:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int compare_philo_id(t_philo *philo)
{
    if (philo->id < philo->id_next)
    {
        pthread_mutex_lock(&philo->data->philo[philo->id].fork);
        write_status(philo, "has taken a fork");
        if (philo->data->time_die <= get_time(philo->data->time) - philo->last_meal)
        {
            write_status(philo, "died");
            pthread_mutex_unlock(&philo->data->philo[philo->id].fork);
            return (1);
        }
        pthread_mutex_lock(&philo->data->philo[philo->id_next].fork);
        return (0);
    }
    pthread_mutex_lock(&philo->data->philo[philo->id_next].fork);
    write_status(philo, "has taken a fork");
    if (philo->data->time_die <= get_time(philo->data->time) - philo->last_meal)
    {
        write_status(philo, "died");
        pthread_mutex_unlock(&philo->data->philo[philo->id_next].fork);
        return (1);
    }
    pthread_mutex_lock(&philo->data->philo[philo->id].fork);
    return (0);
}
