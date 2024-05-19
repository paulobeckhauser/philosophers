/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:17:52 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 19:20:04 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static void handle_thread_error(int status, t_opcode opcode)
{
    if (status == 0)
        return ;
    
}


void thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
    if (opcode == CREATE)
        handle_thread_error
}