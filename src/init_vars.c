/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:16:43 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/12 18:17:37 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_vars(t_info *structure)
{
    structure->nb_philo = 0;
    structure->time_to_die = 0;
    structure->time_to_eat = 0;
    structure->time_to_sleep = 0;
    structure->nb_times_eat = 0;    
}
