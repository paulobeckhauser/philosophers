/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:16:43 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/21 10:56:05 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
EVEN ODD fork assignment
*/

static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
    int philo_nbr;

    philo_nbr = philo->data->nb_philo;
    
    philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
    philo->second_fork = &forks[philo_position];
    
    if (philo->id % 2 == 0)
    {
        philo->first_fork = &forks[philo_position];
        philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
    }          
}



static void philo_init(t_info *data)
{
    int i;
    t_philo *philo;

    i = 0;

    while (i < data->nb_philo)
    {
        philo = data->philos + i;
        philo->id = i + 1;
        philo->meals_counter = 0;
        philo->if_full = false;
        philo->data = data;
        
        mutex_handle(&philo->philo_mutex, INIT);
        // ASSIGN FORKS
        
        assign_forks(philo, data->forks, i);


        i++;
    }
}



void init_vars(t_info *data)
{
    int i;
    
    i = 0;
    data->end_simulation = false;
    data->all_threads_ready = false;
    data->threads_running_nb = 0;
    data->philos = ft_malloc((data->nb_philo + 1) * sizeof(t_philo));
    mutex_handle(&data->table_mutex, INIT);
    data->forks = ft_malloc((data->nb_philo + 1) * sizeof(t_fork));
    // data->philos = malloc((data->nb_philo + 1) * sizeof(t_philo));
    
    while (i < data->nb_philo)
    {
        mutex_handle(&data->forks[i].fork, INIT);
        data->forks[i].fork_id = i;
        i++;
    }


    philo_init(data);




    
    
    // data->nb_philo = 0;
    // data->time_die = 0;
    // data->time_eat = 0;
    // data->time_sleep = 0;
    // data->nb_limit_meals = 0;    
}
