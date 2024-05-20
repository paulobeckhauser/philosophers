/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:17:52 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 12:17:19 by pabeckha         ###   ########.fr       */
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
        ft_error("The value specified by attr is invalid.\n");
    else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
        ft_error("The value specified by thread is not joinable.\n");
    else if (status == ESRCH)
        ft_error("No thread could be found corresponding to that specified by the given thread ID, thread.\n");
    else if (status == EDEADLK)
        ft_error("A deadlock was detected or the value of thread specifies the calling thread.\n");
    // else if (status == EDEADLK)
    //     ft_error("A deadlock would occur if the thread blocked waiting for mutex.\n");
    // else if (status == ENOMEM)
    //     ft_error("The process cannot allocate enough memory to create another mutex.\n");
    // else if (status == EBUSY)
    //     ft_error("Mutex is locked.\n");
}


void thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
    if (opcode == CREATE)
        handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
    else if (opcode == JOIN)
        handle_thread_error(pthread_join(*thread, NULL), opcode);
    else if (opcode == DETACH)
        handle_thread_error(pthread_detach(*thread), opcode);
    else
        ft_error("Wrong opcode for thread_handle.\n");
}