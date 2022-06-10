/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:04:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/10 18:13:39 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord.h"
#include "parse_map.h"
#include "libft.h"
#include "error_message.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

static t_dim	ft_get_max_dims(t_coord *coord, unsigned int size)
{
	unsigned int	i;
	t_dim			max_dims;
	t_lim_dim		lim_coord;
	t_coord			*tmp;

	tmp = coord;
	i = 0;
	lim_coord.min_x = 0;
	lim_coord.max_x = 0;
	lim_coord.min_y = 0;
	lim_coord.max_y = 0;
	max_dims.width = 0;
	max_dims.height = 0;
	max_dims.min_elevation = 0;
	max_dims.max_elevation = 0;
	while (i < size)
	{
		if (tmp[i].x < lim_coord.min_x)
			lim_coord.min_x = tmp[i].x;
		if (tmp[i].y < lim_coord.min_y)
			lim_coord.min_y = tmp[i].y;
		if (tmp[i].x > lim_coord.max_x)
			lim_coord.max_x = tmp[i].x;
		if (tmp[i].y > lim_coord.max_y)
			lim_coord.max_y = tmp[i].y;
		if (tmp[i].z < max_dims.min_elevation)
			max_dims.min_elevation = tmp[i].z;
		if (tmp[i].z > max_dims.max_elevation)
			max_dims.max_elevation = tmp[i].z;
		i++;
	}
	max_dims.width = ft_abs_value(lim_coord.max_x - lim_coord.min_x);
	max_dims.height = ft_abs_value(lim_coord.max_y - lim_coord.min_y);
	return (max_dims);
}

static void	ft_center(t_coord *coord, t_dim max_dims, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		coord[i].x = coord[i].x + (1920 - max_dims.width) / 2;
		coord[i].y = coord[i].y + (1080 - max_dims.height) / 2;
		i++;
	}
}

static void	ft_scale_to_fit(t_coord *coord, t_dim max_dims, unsigned int size)
{
	unsigned int	i;
	float			scale_factor;
	float			scale_x_factor;
	float			scale_y_factor;

	scale_x_factor = max_dims.width / 1920.0;
	scale_y_factor = max_dims.height / 1080.0;
	if (scale_x_factor > scale_y_factor)
		scale_factor = 0.50 / scale_x_factor;
	else
		scale_factor = 0.50 / scale_y_factor;
	i = 0;
	while (i < size)
	{
		coord[i].x = (int)scale_factor * coord[i].x;
		coord[i].y = (int)scale_factor * coord[i].y;
		i++;
	}
}

static void	ft_to_isometric(t_coord *coord, unsigned int size)
{
	unsigned int	i;
	t_coord			tmp;
	float			u;
	float			v;
	double			angle;

	i = 0;
	angle = 1;
	while (i < size)
	{
		tmp.x = coord[i].x;	
		tmp.y = coord[i].y;
		printf("y = %d\n", tmp.y);
		tmp.z = coord[i].z;
		u = tmp.x + cos(angle) * tmp.z - cos(angle) * tmp.y;
		v = -tmp.y * sin(angle) - tmp.z * sin(angle);
		coord[i].x = (int)u;
		coord[i].y = (int)v;
		printf("y = %d\n", coord[i].y);
		i++;
	}
}

void	ft_scale_and_center(t_coord *coord, unsigned int size)
{
	t_dim			max_dims;

	max_dims = ft_get_max_dims(coord, size);
	ft_scale_to_fit(coord, max_dims, size);
	ft_to_isometric(coord, size);
	max_dims = ft_get_max_dims(coord, size);
	printf("max dims = (%d, %d)\n", max_dims.width, max_dims.height); 
	ft_center(coord, max_dims, size);
}