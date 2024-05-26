/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:14:18 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/26 20:02:38 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
