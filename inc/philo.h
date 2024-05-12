/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:35:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/12 18:24:30 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <pthread.h>



typedef struct s_info
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_times_eat;
    
} t_info;

int ft_atoi(const char *nptr);
void init_vars(t_info *structure);
