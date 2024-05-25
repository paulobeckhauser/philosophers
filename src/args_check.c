/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:19:15 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/25 13:03:40 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int check_arg_content(char *argv)
{
    int i;

    i = 0;
    while(argv[i] != '\0')
    {
        if (argv[i] < '0' || argv[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

int check_valid_args(char *argv[])
{
    if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0 || check_arg_content(argv[1]) == 1)
        return (write(2, "Invalid philosophers number\n", 29), 1);
    if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (write(2, "Invalid number of times each philosopher must eat\n", 51), 1);
    return (0);
}
