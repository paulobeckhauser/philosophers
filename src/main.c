/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:15:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/12 21:08:54 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

#include "../inc/philo.h"

void *myThread(void *vargp)
{
    printf("Printing Thread\n");
    (void)vargp;
    return (NULL);
}


int main(int argc, char* argv[])
{
    t_info structure;
    pthread_t thread_id;
    
    
    init_vars(&structure);
    if (argc == 5 || argc == 6)
    {
        structure.nb_philo = ft_atoi(argv[1]);
        structure.time_to_die = ft_atoi(argv[2]);
        structure.time_to_eat = ft_atoi(argv[3]);
        structure.time_to_sleep = ft_atoi(argv[4]);
        if (argc == 6)
            structure.nb_times_eat = ft_atoi(argv[5]);
    

    // CREATION OF THREAD
        pthread_create(&thread_id, NULL, myThread, NULL);
        pthread_join(thread_id, NULL);
        
        printf("Number of philosophers: %d\n", structure.nb_philo);
        
    }
    else if (argc <= 5)
        printf("Too few arguments, please include more!\n");
    else
        printf("Too much arguments, please correct!\n");
    return (0);
}