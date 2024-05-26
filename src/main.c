/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:18 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:32:18 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* 1. arg: Number of philos,
 * 2. arg: time philos have until they die,
 * 3. arg: time they need to eat,
 * 4. arg: time they need to sleep,
 * 5. arg: (optional) how many meals each eats until simulation stops; 
 */
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (ft_error("Wrong number of arguments!\n"));
	store_args(argc, argv, &data);
	if (validate_args(&data) == 1)
		return (1);
	data_init(&data);
	dinner_simulation(&data);
	free_data(&data);
	return (0);
}
