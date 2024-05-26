/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:58:42 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 19:59:13 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(int time_code)
{
	static struct timeval	start;
	static pthread_mutex_t	start_mutex = PTHREAD_MUTEX_INITIALIZER;
	struct timeval			now;

	(void) time_code;
	if (gettimeofday(&now, NULL) != 0)
	{
		printf("Error getting time\n");
		return (-1);
	}
	pthread_mutex_lock(&start_mutex);
	if (start.tv_sec == 0 && start.tv_usec == 0)
		start = now;
	pthread_mutex_unlock(&start_mutex);
	return (((now.tv_sec - start.tv_sec) * (1000))
		+ ((now.tv_usec - start.tv_usec) / 1000));
}
