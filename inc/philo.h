/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/14 18:22:34 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_philo
{
	pthread_t	thread;
}				t_philo;

typedef struct s_info
{
	int			nb_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			nb_eat;
	t_philo		*philo;
}				t_info;

int				ft_atoi(const char *nptr);
void			init_vars(t_info *structure);
void			ft_putstr_fd(char *s, int fd);
