/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:01:10 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/21 11:26:06 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool check_input(t_info *data, int argc, char *argv[])
{
    data->nb_philo = ft_atoi(argv[1]);
    if (data->nb_philo > 200)
        return (false);

    data->time_die = ft_atoi(argv[2]);
    data->time_eat = ft_atoi(argv[3]);
    data->time_sleep = ft_atoi(argv[4]);

    if (argc == 6)
        data->nb_limit_meals = ft_atoi(argv[5]);
    else
        data->nb_limit_meals = INT_MAX;


    if ( d)
    
}