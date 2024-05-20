/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:15:07 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 18:12:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long gettime(t_time_code time_code)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        ft_error("gettimeofday failed\n");

    if (time_code == SECOND)
        return (tv.tv_sec + (tv.tv_usec / 1e6));
    else if (time_code == MILLISECOND)  
        return ((tv.tv_usec * 1e3) + (tv.tv_usec / 1e3));
    else if (time_code == MICROSECOND)
        return ((tv.tv_usec * 1e6) + tv.tv_usec);
    else
        ft_error("Wrong input to gettime!\n");
    return (1);
    


}
