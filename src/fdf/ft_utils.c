/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:59:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/14 11:13:36 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_message.h"
#include "parse_map.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	ft_allocate_coord(t_coord **coord)
{
	*coord = malloc(sizeof(t_coord *));
	if (!(*coord))
		terminate(ERR_MEM);
}

double	ft_degree_to_rad(float degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180.0);
	return (radians);
}

void	ft_free_two_dims(char ***twod_arr)
{
	int	i;

	i = 0;
	while (*twod_arr[i])
	{
		free(*twod_arr[i]);
		*twod_arr[i] = NULL;
		i++;
	}
	free(*twod_arr);
	*twod_arr = NULL;
}
