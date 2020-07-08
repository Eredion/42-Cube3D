/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:29:03 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 12:57:24 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "map/map.h"
# include "Libft/libft.h"
# include "cub_structs.h"
# include <string.h>

void			angle_ref(t_struct *t);
void			initial_pos(t_struct *t);
void			move_press(t_struct *t);
void			move_release(t_struct *t);
unsigned int	chose_color (t_struct *t, int y, int x);
void			pixel_put(t_struct *t, int x, int y, int color);
void			paint_square(t_struct *t, unsigned int color, int x, int y);
void			paint_map(t_struct *t, int x, int y);
int				press (int key, t_struct *t);
void			create_img(t_struct *t);
void			check_mov(t_struct *t);
void			sprite_sort(t_struct *t);
void			sprite_dist(t_struct *t);
void			movement(t_struct *t);
void			paint_pos(t_struct *t);
int				release(int key, t_struct *t);
void			raycast(t_struct *t);
void			magic_tex(t_struct *t);
int				waiting(t_struct *t);
void			load_texture(t_struct *t);
int				mouse(int x, int y, t_struct *t);
int				exit_win(t_struct *t);
void			magic_spr(t_struct *t);
void			save_bmp(t_struct *t);
void			sprite_sort(t_struct *t);
void			sprite_dist(t_struct *t);
void			load_sprite(t_struct *t);
void			save_bmp(t_struct *t);
void			bmp_header(t_struct *t, int fd);
void			bmp_image(t_struct *t, int fd);
void			movement(t_struct *t);
void			init_mov(t_struct *t);
void			start_raycast(t_struct *t, int x);
void			init_raycast(t_struct *t);
void			tex_color(t_struct *t, int i);
void			print_raycast(t_struct *t, int x);
void			print_raycast_tex(t_struct *t, int x);
void			start_raycast(t_struct *t, int x);
void			step_calculation(t_struct *t);
void			print_sprites(t_struct *t);
void			draw_calculation(t_struct *t);
void			hit_calculation(t_struct *t);
void			init_all(t_struct *t);
void			spr_col(t_struct *t);

#endif
