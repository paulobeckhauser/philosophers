/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:34:19 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 11:08:27 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void simulation(t_philo *philo)
{
    while (1)
    {
        pthread_mutex_lock(&philo->data->print);
        if (philo->data->dead == 1)
        {
            pthread_mutex_unlock(&philo->data->print);
            break ;
        }
        pthread_mutex_unlock(&philo->data->print);
        if (take_fork_and_eat(philo) == 1)
            break ;
        write_status(philo, "is sleeping");
        ft_usleep(philo->data->time_sleep);
        write_status(philo, "is thinking");
        pthread_mutex_lock(&philo->data->ate);
        if (philo->data->nb_food && ++philo->food == philo->data->nb_food)
        {
            pthread_mutex_unlock(&philo->data->ate);
            break ;
        }
        pthread_mutex_unlock(&philo->data->ate);
    }
}
