/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:22:51 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 22:25:38 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void thinking(t_philo *philo)
{
    write_status("is thinking", philo, philo->id);
}

static void sleeping(t_philo *philo)
{
    write_status("is sleeping", philo, philo->id);
    ft_usleep(philo->time_to_sleep);
}

static void eating(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    write_status("has taken a fork", philo, philo->id);
    if (philo->num_of_philos == 1)
    {
        ft_usleep(philo->time_to_die);
        pthread_mutex_unlock(philo->r_fork);
        return ;
    }

    pthread_mutex_lock(philo->l_fork);
    write_status("has taken a fork", philo, philo->id);
    philo->eating = 1;
    write_status("is eating", philo, philo->id);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->time_to_eat);
    // pthread_mutex_lock(philo->meal_lock);
    philo->eating = 0;    
    // pthread_mutex_unlock(philo->meal_lock);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}


void *philo_routine(void *pointer)
{
    t_philo *philo;

    philo = (t_philo *)pointer;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    while(!dead_loop(philo))
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (pointer);
}
