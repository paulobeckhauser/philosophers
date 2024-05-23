/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:47:47 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 10:09:34 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void write_status(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->data->print);
    

    if (philo->data->dead == 1)
    {
        pthread_mutex_unlock(&philo->data->print);
        return ;
    }
    if (ft_strcmp(str, "died") == 0)
    {
        philo->data->dead = 1;
        printf("%ld %d %s\n", get_time(philo->data->time), philo->id + 1, str);
        pthread_mutex_unlock(&philo->data->print);
        return ;
    }
    printf("%ld %d %s\n", get_time(philo->data->time), philo->id + 1, str);
    pthread_mutex_unlock(&philo->data->print);
}
