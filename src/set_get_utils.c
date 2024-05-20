/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:08:08 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 16:14:29 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void set_bool(t_mtx *mutex, bool *dest, bool value)
{
    mutex_handle(mutex, LOCK);

    *dest = value;

    mutex_handle(mutex, UNLOCK);
    
}



bool get_bool (t_mtx *mutex, bool *value)
{
    bool ret;

    mutex_handle(mutex, LOCK);
    

    //READING thread safe
    ret = *value;
    
    mutex_handle(mutex, UNLOCK);
    return (ret);
}

void set_long(t_mtx *mutex, long *dest, long value)
{
    mutex_handle(mutex, LOCK);

    *dest = value;

    mutex_handle(mutex, UNLOCK);
    
}



long get_long (t_mtx *mutex, long *value)
{
    long ret;

    mutex_handle(mutex, LOCK);
    

    //READING thread safe
    ret = *value;
    
    mutex_handle(mutex, UNLOCK);
    return (ret);
}