/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:15:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 13:05:24 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

// #include "../inc/philo.h"

// int main(int argc, char* argv[])
// {
//     t_info data;

//     if (argc < 5 || argc > 6)
//         return(printf("Wrong number of arguments!\n"), 1);
//     if (check_input(&data, argc, argv) == false)
//         return (printf("Invalid input\n"), 1);
//     init_vars(&data);
//     dinner_start(&data);
//     clean_vars(&data);
//     return (0);
// }


#include "../inc/philo.h"

int main(int argc, char *argv[])
{
    t_info data;

    int i;

    i = 0;
    if (argc < 5 || argc > 6)
        return(printf("Wrong number of arguments!\n"), 1);
    if (!init_vars(argc, argv, &data))
        return(1);
    while (i < data.nb_philo)
    {
        pthread_create(&data.philo[i].thread, NULL, ft_philo, &data.philo[i]);
        i++;
    }
    i = 0;
    while (i < data.nb_philo)
    {
        pthread_join(data.philo[i].thread, NULL);
        i++;
    }
    free(data.philo);
    return (0);
}
