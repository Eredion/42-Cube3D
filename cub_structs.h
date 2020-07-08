/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:15:18 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 11:20:39 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

# define LEFT_CLICK 	1
# define RIGHT_CLICK 	2
# define MIDDLE_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define _1			18
# define _2			19
# define _3			20
# define _4			21
# define _Q			12
# define _W			13
# define _E			14
# define _R			15
# define _A			0
# define _S			1
# define _D			2
# define _I			34
# define _O			31
# define _P			35
# define _J			38
# define _K			40
# define _L			37
# define _T			17
# define _LEFT		123
# define _RIGHT		124
# define _UP	 	126
# define _DOWN		125
# define _SP		49

# define _TAB	48
# define _MAJ	257
# define _ESC	53

typedef struct	s_ray
{
	double	camx;
	double	ray_x;
	double	ray_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	delta_x;
	double	delta_y;
	double	walldist;
	int		hit;
	int		side;
	int		line_h;
	int		d_start;
	int		d_end;
	int		d_start_y;
	int		d_end_y;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		color;
	double	spr_x;
	double	spr_y;
	int		spr_h;
	int		spr_w;
	double	inv;
	double	trans_x;
	double	trans_y;
	int		spr_screenx;
	int		*sp_buff;
	int		stripe;
	int		wall;
}				t_ray;

typedef struct	s_mov
{
	int		up;
	int		left;
	int		right;
	int		down;
	int		turnl;
	int		turnr;
	int		int_posx;
	int		int_posy;
	double	posx;
	double	posy;
	float	speed;
	float	degrees;
	double	cx;
	double	cy;
	double	angle;
	double	plx;
	double	ply;
	double	mov_x;
	double	mov_y;
}				t_mov;

typedef struct	s_img
{
	int		endian;
	int		size;
	int		height;
	int		width;
	int		bpp;
	int		*data;
	void	*ptr;
}				t_img;

typedef struct	s_struct
{
	void	*init;
	int		key;
	void	*window;
	t_map	map;
	t_mov	mov;
	t_img	img;
	t_img	tex[4];
	t_img	spr;
	t_ray	ray;
	int		tex_off;
	int		spr_off;
	int		save;
}				t_struct;

#endif
