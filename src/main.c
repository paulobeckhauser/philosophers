/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:15:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/12 17:47:36 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

#include "../inc/philo.h"

int main(int argc, char* argv[])
{
    t_info structure;

    if (argc == 5 || argc == 6)
    {
        structure.nb_philo = ft_atoi(argv[1]);
        printf("%d\n", structure.nb_philo);
    }
    else if (argc <= 5)
        printf("Too few arguments, please include more!\n");
    else
        printf("Too much arguments, please correct!\n");
    return (0);
}