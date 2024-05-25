/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:15:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 22:27:44 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{

    t_program program;
    t_philo philos[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];

    // printf("test\n");
    if (argc != 5 && argc != 6)
        return(write(2, "Wrong argument count\n", 22), 1);
    if (check_valid_args(argv) == 1)
        return (1);
    // INITIALIZE
    init_program(&program, philos);
    init_forks(forks, ft_atoi(argv[1]));
    init_philos(philos, &program, forks, argv);
    // INITIALIZE
    thread_create(&program, forks);
    destroy_all(NULL, &program, forks);
    return (0);    
}
