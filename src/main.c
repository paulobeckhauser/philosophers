/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:15:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/14 18:32:48 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

#include "../inc/philo.h"

// void *myThread(void *vargp)
// {
//     printf("Printing Thread\n");
//     (void)vargp;
//     return (NULL);
// }

void *thread_func(void *arg)
{
    printf("is thinking\n");
    (void)arg;
    return (NULL);
}


int main(int argc, char* argv[])
{
    t_info data;
    int i;
    
    i = 0;
    init_vars(&data);
    if (argc == 5 || argc == 6)
    {
        data.nb_philo = ft_atoi(argv[1]);
        data.time_die = ft_atoi(argv[2]);
        data.time_eat = ft_atoi(argv[3]);
        data.time_sleep = ft_atoi(argv[4]);
        if (argc == 6)
            data.nb_eat = ft_atoi(argv[5]);
        
        // printf("%d\n", data.nb_philo);
        i = 0;
        while(i < data.nb_philo)
        {
            pthread_create(&data.philo[i].thread, NULL, thread_func, NULL);
            i++;
        }
        // {
        //     if (pthread_create(&data.philo[i].thread, NULL, thread_func, NULL) != 0)
        //     {
        //         ft_putstr_fd("Failed to create thread\n", 2);
        //         return(1);
        //     }
        //     i++;
        // }
        
        i = 0;
        while (i < data.nb_philo)
        {
            pthread_join(data.philo[i].thread, NULL);
            i++;
        }        
    }
    else if (argc <= 5)
        printf("Too few arguments, please include more!\n");
    else
        printf("Too much arguments, please correct!\n");
    return (0);
}
