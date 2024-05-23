/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 11:28:20 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
#include <sys/time.h>
# include <limits.h>




// typedef enum e_philo_status
// {
// 	EATING,
// 	SLEEPING,
// 	THINKING,
// 	TAKE_FIRST_FORK,
// 	TAKE_SECOND_FORK,
// 	DIED,
// }	t_philo_status;


// // ./philo 5 800 200 200 [5]


// /*
// MUTEX SAFE

// * init
// * destroy
// * lock
// * unlock

// */


// /*
// OPCODE for mutex | thread functions
// */
// typedef enum e_opcode
// {
// 	LOCK,
// 	UNLOCK,
// 	INIT,
// 	DESTROY,
// 	CREATE,
// 	JOIN,
// 	DETACH,
	
// }	t_opcode;



// /*
// CODES for gettime
// */

// typedef enum e_time_code
// {
// 	SECOND,
// 	MILLISECOND,
// 	MICROSECOND,
// }	t_time_code;

// typedef pthread_mutex_t t_mtx;

// typedef struct s_info t_info;



// typedef struct s_fork
// {
// 	t_mtx fork;
// 	int fork_id;
// }		t_fork;

// typedef struct s_philo
// {
// 	int			id;
// 	bool dead;
// 	int			meals_counter; // maybe change to long
// 	bool		if_full;
// 	long		last_meal_time; // time passed from last meal
// 	t_fork 		*first_fork;
// 	t_fork 		*second_fork;
// 	pthread_t	thread_id; //a philo is a thread
// 	t_mtx 		philo_mutex; // useful for races with the monitor
// 	t_info 		*data;
// 	// int			eating;

// }				t_philo;




// typedef struct s_info
// {
// 	long			nb_philo; //maybe long
// 	long			time_die; //maybe long
// 	long			time_eat; //maybe long
// 	long			time_sleep; //maybe long
// 	long			nb_limit_meals;  //maybe long [5] | FLAG if -1
// 	long			start_simulation;  //maybe long
// 	bool		end_simulation;  //maybe long -> Triggers when a philo die or all philos are full
// 	t_fork		*forks;
// 	t_philo		*philos; //array
// 	bool 		all_threads_ready; // synchro philos
	
// 	t_mtx 		table_mutex; //avoid races while reading from data
// 	t_mtx		write_mutex;  //write state
	
// 	pthread_t monitor; //check for died philos

// 	long threads_running_nb;
	
	
	
// }				t_info;


// int				ft_atoi(const char *nptr);
// void			init_vars(t_info *structure);
// void 			parse_input(t_info *data, char *argv[]);
// void			ft_putstr_fd(char *s, int fd);
// size_t			ft_strlen(const char *s);
// void			ft_error(char *str);
// void			*ft_malloc(size_t size);
// void			ft_error(char *str);
// void			ft_putstr_fd(char *s, int fd);
// void 			set_bool(t_mtx *mutex, bool *dest, bool value);
// bool 			get_bool (t_mtx *mutex, bool *value);
// void 			set_long(t_mtx *mutex, long *dest, long value);
// long 			get_long (t_mtx *mutex, long *value);
// bool 			check_simulation_finished(t_info *data);
// void 			wait_all_threads(t_info *data);
// long gettime(t_time_code time_code);
// void ft_usleep(long usec, t_info *data);
// void write_status(t_philo_status status, t_philo *philo);
// void	clean_vars(t_info *data);
// bool	check_input(t_info *data, int argc, char *argv[]);
// void dinner_start(t_info *data);
// void mod_usleep(long msec, t_info *data);
// void eat(t_philo *philo);
// void thinking(t_philo *philo, bool pre_simulation);
// void *ft_philo(void *arg);

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>


typedef struct s_philo
{
	int id;
	int id_next;
	pthread_mutex_t fork;
	int food;
	struct s_info *data;
	pthread_t thread;
	int last_meal;
} t_philo;

typedef struct s_info
{
	int nb_philo;
	int time_die;
	int time_eat;
	int time_sleep;
	int nb_food;
	int dead;
	pthread_mutex_t ate;
	t_philo *philo;
	pthread_mutex_t print;
	struct timeval time;
} t_info;


int				ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
long 			get_time(struct timeval time);
void 			ft_usleep(int time);
void 			write_status(t_philo *philo, char *str);
int 			compare_philo_id(t_philo *philo);
int 			take_fork_and_eat(t_philo * philo);
void 			*ft_philo(void *arg);
void 			init_philo(t_info *data);
bool			init_vars(int argc, char *argv[], t_info *data);
void 			simulation(t_philo *philo);

#endif