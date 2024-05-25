/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:24:15 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 14:25:24 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_usleep(size_t milliseconds)
{
    size_t start;

    start = get_current_time();
    
    while ((get_current_time() - start) < milliseconds)
        usleep(500);
    return (0);
}
