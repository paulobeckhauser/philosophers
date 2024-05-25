/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:18:22 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 13:40:10 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program ->philos = philos;
    
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
}


void init_forks(pthread_mutex_t *forks, int philo_num)
{
    int i;

    i = 0;
    while(i < philo_num)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }    
}


void init_input(t_philo *philo, char *argv[])
{
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    philo->num_of_philos = ft_atoi(argv[1]);
    if (argv[5])
        philo->num_times_to_eat = ft_atoi(argv[5]);
    else
        philo->num_times_to_eat = -1;
}

void init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char *argv[])
{
    int i;

    i = 0;
    while(i < ft_atoi(argv[1]))
    {
        philos[i].id = i + 1;
        philos[i].eating = 0;
        philos[i].meals_eaten = 0;
        init_input(&philos[i], argv);
        philos[i].start_time = get_current_time();
        philos[i].last_meal = get_current_time();
        philos[i].write_lock = &program->write_lock;
        philos[i].dead_lock = &program->dead_lock;
        philos[i].meal_lock = &program->meal_lock;
        philos[i].dead = &program->dead_flag;
        philos[i].l_fork = &forks[i];
        if (i == 0)
            philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
        else
            philos[i].r_fork = &forks[i - 1];
        i++;
    }
}
