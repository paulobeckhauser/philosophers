/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:34:19 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 19:42:41 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


/*
eat routine:

1) grab the forks: here first & second fork is handy
2) eat: write eat, update last meal, update meals counter
3) release the forks
*/

static void eat(t_philo *philo)
{
    // 1)
    mutex_handle(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo);
    mutex_handle(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo);

    // 2)
    set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
    
    philo->meals_counter++;

    write_status(EATING, philo);

    ft_usleep(philo->data->time_eat, philo->data);


    if (philo->data->nb_limit_meals > 0)
    
    
}


bool check_simulation_finished(t_info *data)
{
    bool ret;
    
    ret = get_bool(&data->table_mutex, &data->end_simulation);
    return (ret); 
}


/*

0) wait all philos, synchro start
1) endless loop philo


*/

void *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;


    //spinlock
    wait_all_threads(philo->data);
    
    // set last meal time
    
    while (!check_simulation_finished(philo->data))
    {
        // 1) is philo full?
        if (philo->if_full)
            break ;
            
        // 2) eat
        eat(philo);

        // 3)sleep -> write_status & precise u_sleep
        write_status(SLEEPING, philo);
        ft_usleep(philo->data->time_sleep, philo->data);

        //4)think
        thinking(philo); // TODO

    }

    return (NULL);
}
















/*

./philo 5 800 200 200 [5]


0) If no meals, return ->[0]
0.1) If only one philo -> ad hoc function
1) Create all threads, all philos
2) Create a monitor thread -> dead
3) Synchronize the begginning of the simulation
    pthread_create-> philo starts running!
    every philo start simultaneously
4) JOIN everyone


*/






void dinner_start(t_info *data)
{
    int i;

    i = 0;
    
    
    
    if (data->nb_limit_meals == 0)
        return ; //back to main, clean
    else if (data->nb_philo == 1)
        ; // TO-DO
    else
    {
        while (i < data->nb_philo)
        {
            thread_handle(&data->philos[i].thread, dinner_simulation, &data->philos[i], CREATE);
            i++;
        }
    }
    // start of simulation
    data->start_simulation = gettime(MILLISECOND);
    

    // now all threads are ready!!
    set_bool(&data->table_mutex, &data->all_threads_ready, true);


    // Wait for everyone

    i = 0;
    while (i < data->nb_philo)
    {
        thread_handle(data->philos[i].thread, NULL, NULL, JOIN);
        i++;
    }

    // If we manage to reach this line, all philos are FULL!

    
    

}

