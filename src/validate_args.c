/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:45:12 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 19:54:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	validate_args(t_data *data)
{
	if (data->philo_nb > PHILO_MAX || data->philo_nb <= 0)
		return (ft_error("Not good number of philosophers\n"));
	if (data->time_to_die <= 0)
		return (ft_error("Time to die not correct\n"));
	if (data->time_to_eat <= 0)
		return (ft_error("Time to eat not correct\n"));
	if (data->time_to_sleep <= 0)
		return (ft_error("Time to sleep not correct\n"));
	if (data->limit_meals <= 0)
		return (ft_error("Numer of Meals not correct\n"));
	return (0);
}
