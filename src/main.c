/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:15:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 12:18:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

#include "../inc/philo.h"

void *thread_func(void *arg)
{
    printf("is thinking\n");
    (void)arg;
    return (NULL);
}

int error_exit(const char *error)
{
    ft_putstr_fd((char *)error, 2);
    ft_putstr_fd("\n", 2);
    return (1);
    
}


int main(int argc, char* argv[])
{
    t_info data;
    int i;

    i = 0;
    
    if (argc == 5 || argc == 6)
    {
        parse_input(&data, argv);
        init_vars(&data);
    
        // data.philos = ft_malloc((data.nb_philo + 1) * sizeof(t_philo));
        // if (data.philos == NULL)
        // {
        //     printf("Malloc failed to allocate memory\n");
        //     return (1);
        // }

        i = 0;
        while(i < data.nb_philo)
        {
            // dataphilo.id = i + 1;
            data.philos->id = i + 1;
            // printf("here\n");
            if (pthread_create(&data.philos[i].thread, NULL, thread_func, NULL) != 0)
            {
                ft_putstr_fd("Failed to create thread\n", 2);
                return(1);
            }
            i++;
        }        
        i = 0;
        while (i < data.nb_philo)
        {
            pthread_join(data.philos[i].thread, NULL);
            i++;
        }
        
        free(data.philos);



    }





    else if (argc <= 5)
        printf("Too few arguments, please include more!\n");
    else
        printf("Too much arguments, please correct!\n");
    return (0);
}
