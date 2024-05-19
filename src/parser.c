/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:51:21 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 18:16:40 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/philo.h"

// Check:
// 1. Actual numbers
// 2. Not > INT_MAX
// 3. timestamps > 60ms



void parse_input(t_info *data, char *argv[])
{
    // PARSE INPUT
    // 1. Errors checking, Filling table
    // 2. Data init -> creating the actual thing
    // 3. dinner_start
    // 4. clean -> no leaks -> philos(full) | 1 philo died 
    data->nb_philo = ft_atoi(argv[1]);
    data->time_die = ft_atoi(argv[2]);
    data->time_eat = ft_atoi(argv[3]);
    data->time_sleep = ft_atoi(argv[4]);
    if (argv[5])
        data->nb_limit_meals = ft_atoi(argv[5]);
    else
        data->nb_limit_meals = -1;
}