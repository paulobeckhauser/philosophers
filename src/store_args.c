/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:44:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 19:54:51 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	store_args(int argc, char *argv[], t_data *data)
{
	data->philo_nb = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->limit_meals = ft_atol(argv[5]);
	else
		data->limit_meals = INT_MAX;
}
