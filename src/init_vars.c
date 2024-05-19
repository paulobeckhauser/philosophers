/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:16:43 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 18:49:33 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_vars(t_info *data)
{
    data->end_simulation = false;
    data->philos = ft_malloc((data->nb_philo + 1) * sizeof(t_philo));
    // data->philos = malloc((data->nb_philo + 1) * sizeof(t_philo));
    
    
    data->nb_philo = 0;
    data->time_die = 0;
    data->time_eat = 0;
    data->time_sleep = 0;
    data->nb_limit_meals = 0;    
}
