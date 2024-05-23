/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:16:22 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 11:19:29 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_philo(t_info *data)
{
    int i;

    i = 0;
    while(i < data->nb_philo)
    {
        pthread_mutex_init(&data->philo[i].fork, NULL);
        data->philo[i].id = i;
        data->philo[i].last_meal = get_time(data->time);
        if (data->nb_philo == i + 1)
            data->philo[i].id_next = 0;
        else
            data->philo[i].id_next = i + 1;
        data->philo[i].food = 0;
        data->philo[i].data = data;
        i++;
    }
}
