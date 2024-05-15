/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/15 14:27:46 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// struct s_fork
// {

// }

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			eating;
	int			meals_counter;
	bool		if_full;
	int last_meal_time; // time passed from last meal

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
size_t			ft_strlen(const char *s);
void			ft_error(char *str);
void			*ft_malloc(size_t size);
void			ft_putstr_fd(char *s, int fd);
