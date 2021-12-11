/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:18:32 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ESC 53
# define LEFT 0
# define RIGHT 2
# define DOWN 13
# define UP 1
# define LEFT_ROT 123
# define RIGHT_ROT 124

# include "../get_map_data/get_data.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_maps_data
{
	int		screen_width;
	int		screen_height;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	char	*s_tex;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	int		**world_map;
	int		row_max;
	int		col_max;
	int		start_row;
	int		start_col;
	char	start_dir;
	int		num_sprite;
}				t_maps_data;

typedef struct s_spr_temp
{
	double	spr_x;
	double	spr_y;
	double	inv_det;
	double	transf_x;
	double	transf_y;
	int		spr_scr_x;
	int		spr_height;
	int		draw_start_y;
	int		draw_start_x;
	int		draw_end_y;
	int		draw_end_x;
	int		spr_width;
	int		*spr_order;
	double	*spr_dist;
	int		x;
	int		y;
	int		d;
	int		i;

}				t_spr_temp;

typedef struct s_sprite
{
	double	x;
	double	y;
	int		type;
	int		texture;
}				t_sprite;

typedef struct s_draw {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_draw;

typedef struct s_step
{
	double	step;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	move_speed;
	double	rot_speed;
}				t_step;

typedef struct s_texture
{
	void	*img;
	char	*img_addr;
	int		width;
	int		height;
}				t_texture;

typedef struct s_time {
	double	time;
	double	old_time;
	double	frame_time;
	double	fps;
}				t_time;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			*get_data;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		old_dir_x;
	double		dir_y;
	double		plane_x;
	double		old_plane_x;
	double		plane_y;
	double		w;
	int			h;
	int			x;
	int			y;
	int			i;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			size_l;
	int			key_pressed[6];
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		wall_x;
	int			tex_used;
	double		*z_buffer;
	t_draw		draw;
	t_step		step;
	t_sprite	*sprite;
	t_texture	texture[5];
	t_maps_data	scene;
}				t_data;

typedef struct s_bmp
{
	int				size;
	char			*img;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

int			ft_render_frame(t_data *data);
int			ft_keypress(int keycode, t_data *data);
int			ft_keyrelease(int keycode, t_data *data);
int			ft_init(t_data *data);
void		ft_init_key(t_data *data);
void		ft_move_up(t_data *data);
void		ft_move_down(t_data *data);
void		ft_move_left(t_data *data);
void		ft_move_right(t_data *data);
void		ft_rot_left(t_data *data);
void		ft_rot_right(t_data *data);
void		ft_move(t_data *data);
void		ft_ray(t_data *data);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_step(t_data *data);
void		ft_init_start(t_data *data);
void		ft_init_draw(t_data *data);
void		ft_wall_dist(t_data *data);
void		ft_step_hit(t_data *data);
int			ft_texture(t_data *data);
int			ft_check_tex(t_data *data, int n_check);
void		ft_tex_used(t_data *data);
void		ft_draw_sf(t_data *data);
void		ft_draw_sprites(t_data *data);
int			ft_fill_sprite(t_data *data);
void		ft_srt_sprites(int *order, double *dist, int len);
int			create_rgb(int r, int g, int b);
void		start_position1(t_data *data);
void		start_position2(t_data *data);
int			init(t_data *data);
int			ft_quit(int button, t_data *vars);
void		ft_spr_tmp(t_spr_temp *tmp, t_data *data);
void		ft_spr_tmp2(t_spr_temp *tmp, t_data *data);
void		ft_spr_tmp3(t_spr_temp *tmp, t_data *data, int t_i);
void		set_header(unsigned char *header, int param);
void		imgbmp(t_data *data, t_bmp *bmp);
void		ft_header(t_data *data, t_bmp *bmp);
void		ft_bmp(t_data *data);
void		ft_bmpinit(t_data *data);
void		check_pos_screen(t_data *data);
t_maps_data	initmapdata(void);
void		get_data(char *file, t_maps_data *scene);
void		read_file(char *str, int *row, t_maps_data *scene);
int			ft_maps_is_last(t_maps_data *scene);
int			ft_allocate_matrix(t_maps_data *scene);
void		ft_identifier(char *str, t_maps_data *scene);
void		ft_error_msg(char *msg);
void		ft_id_r(char **tmp, char *str, t_maps_data *scene);
void		ft_id_no(char **tmp, char *str, t_maps_data *scene);
void		ft_id_so(char **tmp, char *str, t_maps_data *scene);
void		ft_id_we(char **tmp, char *str, t_maps_data *scene);
void		ft_id_ea(char **tmp, char *str, t_maps_data *scene);
void		ft_id_s(char **tmp, char *str, t_maps_data *scene);
void		ft_id_f(char **tmp, char *str, t_maps_data *scene);
void		ft_id_c(char **tmp, char *str, t_maps_data *scene);
void		ft_free_array_strings(char **tmp);
void		create_world_map(char *str, int *row, t_maps_data *scene);
void		player_pos(char *str, int *row, int col, t_maps_data *scene);
void		fill_seven_world_map(t_maps_data *scene);
void		check_row(t_maps_data *scene);
void		check_row_rev(t_maps_data *scene, int row);
void		check_col(t_maps_data *scene);
void		check_col_rev(t_maps_data *scene, int col);
void		ft_free_scene_struct(t_data *data);
void		ft_esc(t_data *data);
void		ft_check(t_maps_data *scene);

#endif