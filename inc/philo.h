/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 21:22:21 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <unistd.h> // usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_create, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <stdio.h> //printf

# define PHILO_MAX 300




typedef struct s_philo
{
	pthread_t thread;

	int 			id;
	int eating;
	int meals_eaten;
	
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	int num_times_to_eat;

	
	size_t start_time;


	
	size_t last_meal;
	int num_of_philos;

	
	int *dead;

	
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;

	
	pthread_mutex_t *write_lock;
	pthread_mutex_t *dead_lock;
	pthread_mutex_t *meal_lock;	
} t_philo;




typedef struct s_program
{
	int dead_flag;
	t_philo *philos;
	
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t write_lock;

}	t_program;


int check_valid_args(char *argv[]);
int	ft_atoi(const char *str);
void init_program(t_program *program, t_philo *philos);
void init_forks(pthread_mutex_t *forks, int philo_num);
void init_input(t_philo *philo, char *argv[]);
void init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char *argv[]);
size_t get_current_time(void);
int thread_create(t_program *program, pthread_mutex_t *forks);
void *philo_routine(void *pointer);
int ft_usleep(size_t milliseconds);
void write_status(char *str, t_philo *philo, int id);
int	dead_loop(t_philo *philo);
void	*monitor(void *pointer);
void destroy_all(char *str, t_program *program, pthread_mutex_t *forks);
size_t	ft_strlen(const char *s);


# endif