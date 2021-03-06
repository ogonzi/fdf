/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:28:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 09:39:16 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "graphics_bonus.h"
# include "colors_bonus.h"
# include "line_bonus.h"

/* ft_utils_1_bonus.c */

void	ft_free_two_dims(char **twod_arr);
void	ft_allocate_coord(t_map_data *map_data);
void	terminate(char *s);
double	ft_degree_to_rad(float degrees);
int		ft_pixel_in_screen(int x, int y, t_screen screen);

/* ft_utils_2_bonus.c */

void	ft_protect_line_split(char ***line_split, int fd, int read_flag,
			t_map_data *map_data);
void	ft_init_gradient(t_grad *gradient);
void	ft_init_map_data(t_map_data *map_data);
void	ft_init_img(t_img *img, t_screen screen, t_data *img_data);
void	ft_init_mlx(t_vars *vars, t_data *img, t_screen *screen,
			t_map_data *map_data);

/* ft_utils_3_bonus.c */

void	ft_free_all(t_map_data *map_data);
void	ft_clear_image(t_vars *vars);
int		ft_destroy_window(t_vars *vars);
#endif
