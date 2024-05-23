/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:15:07 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 09:54:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long get_time(struct timeval time)
{
    struct timeval now;
    int diff;

    gettimeofday(&now, NULL);
    diff = (now.tv_sec * 1000 + now.tv_usec / 1000) - (time.tv_sec * 1000 + time.tv_usec / 1000);
    return (diff);
}
