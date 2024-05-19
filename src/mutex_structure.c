/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:50:23 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 19:11:39 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


/*
Embed control on return status
*/
static void handle_mutex_error(int status, t_opcode opcode)
{
    if (status == 0)
        return ;

    if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
        ft_error("The value specified by mutex is invalid.\n");
    else if (status == EINVAL && opcode == INIT)
        ft_error("The value specified by attr is invalid.\n");
    else if (status == EDEADLK)
        ft_error("A deadlock would occur if the thread blocked waiting for mutex.\n");
    else if (status == EPERM)
        ft_error("The current thread does not hold a lock on mutex.\n");
    else if (status == ENOMEM)
        ft_error("The process cannot allocate enough memory to create another mutex.\n");
    else if (status == EBUSY)
        ft_error("Mutex is locked.\n");
}
/*
MUTEX SAFE

* init
* destroy
* lock
* unlock

*/

void mutex_handle(t_mtx *mutex, t_opcode opcode)
{
    if (opcode == LOCK)
        handle_mutex_error(pthread_mutex_lock(mutex), opcode);
    else if (opcode == UNLOCK)
        handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
    else if (opcode == INIT)
        handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
    else if (opcode == DESTROY)
        handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
    else
        ft_error("Wrong opcode for mutex handle\n");
    
}