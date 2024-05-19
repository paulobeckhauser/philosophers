/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 19:04:58 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>




// ./philo 5 800 200 200 [5]


/*
MUTEX SAFE

* init
* destroy
* lock
* unlock

*/


/*
OPCODE for mutex | thread functions
*/
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
	
}	t_opcode;






typedef pthread_mutex_t t_mtx;

typedef struct s_info t_info;



typedef struct s_fork
{
	t_mtx fork;
	int fork_id;
}		t_fork;

typedef struct s_philo
{
	
	int			id;
	int			meals_counter; // maybe change to long
	bool		if_full;
	int			last_meal_time; // time passed from last meal

	t_fork *left_fork;
	t_fork *right_fork;
	pthread_t	thread; //a philo is a thread

	t_info *info;

	

	
	
	

	// int			eating;

}				t_philo;




typedef struct s_info
{
	int			nb_philo; //maybe long
	int			time_die; //maybe long
	int			time_eat; //maybe long
	int			time_sleep; //maybe long
	int			nb_limit_meals;  //maybe long [5] | FLAG if -1
	
	int			start_simulation;  //maybe long
	bool			end_simulation;  //maybe long -> Triggers when a philo die or all philos are full
	
	t_fork		*forks;
	t_philo		*philos; //array

	
}				t_info;




int				ft_atoi(const char *nptr);
void			init_vars(t_info *structure);
void parse_input(t_info *data, char *argv[]);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
void			ft_error(char *str);
void			*ft_malloc(size_t size);
void	ft_error(char *str);
void			ft_putstr_fd(char *s, int fd);
