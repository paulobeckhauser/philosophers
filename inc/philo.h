/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:04:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

typedef enum time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time_code;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	bool				dead;
	long				meal_counter;
	bool				full;
	long				last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	t_data				*data;
	t_mtx				philo_mutex;
}						t_philo;

typedef struct s_data
{
	long				philo_nb;
	long				time_to_sleep;
	long				time_to_eat;
	long				time_to_die;
	long				limit_meals;
	long				start_simulation;
	bool				end_simulation;
	t_fork				*forks;
	t_philo				*philos;
	bool				all_threads_ready;
	t_mtx				data_mutex;
	t_mtx				write_mutex;
	pthread_t			monitor;
}						t_data;

void					thinking(t_philo *philo, bool pre_simulation);
long					ft_atol(const char *str);
long					get_time(int time_code);
void					ft_usleep(long usec, t_data *data);
bool					data_init(t_data *data);
void					dinner_simulation(t_data *data);
void					*philo_routine(t_philo *philo);
void					set_bool(t_mtx *mutex, bool *dest, bool value);
bool					get_bool(t_mtx *mutex, bool *value);
void					set_long(t_mtx *mutex, long *dest, long value);
long					get_long(t_mtx *mutex, long *value);
bool					check_end_simulation(t_data *data);
bool					all_threads_running(t_mtx *mutex, long *threads,
							long philo_nb);
void					*ft_philo(void *arg);
void					write_status(t_philo_status status, t_philo *philo);
void					*monitor_dinner(void *data);
void					assign_forks(t_philo *philo, t_fork *forks,
							int philo_position);
void					philo_init(t_data *data);
void					free_data(t_data *data);
int						ft_error(char *str);
void					ft_putstr_fd(char *s, int fd);
void					store_args(int argc, char *argv[], t_data *data);
int						validate_args(t_data *data);

#endif