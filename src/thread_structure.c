/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:17:52 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 21:52:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static void handle_thread_error(int status, t_opcode opcode)
{
    if (status == 0)
        return ;
    if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
        ft_error("The value specifier by mutex is invalid.\n");
    else if (status == EINVAL && opcode == INIT)
        ft_error("The value specified by attr is invalid\n");
    else if (status == EDEADLK)
        ft_error("A deadlock would occur if the thread blocked waiting for mutex\n");
    
}


void thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
    if (opcode == CREATE)
        handle_thread_error
}