/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:42 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/19 18:49:07 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error("Malloc failed to allocate memory\n");
	return (ptr);
}
