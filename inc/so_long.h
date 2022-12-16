/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:04:46 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/16 11:17:09 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> 	/* open */
# include <stdio.h> 	/* perror */
# include <errno.h> 	/* errno */
# include <stdlib.h> 	/* exit */
# include <unistd.h> 	/* write, access */

# ifdef __APPLE__
#  include "../minilibx-mac/mlx.h"
#  define W_UP 13
#  define S_DOWN 5
#  define A_LEFT 0
#  define D_RIGHT 2
#  define ESC 53
# endif
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define W_UP 119
#  define S_DOWN 115
#  define A_LEFT 97
#  define D_RIGHT 100
#  define ESC 65307
# endif

# define PIXEL 64

# define TITLE "so_long"

typedef struct s_img
{
	void			*wall;
	void			*way;
	void			*coin;
	void			*exit;
	void			*pr;
	void			*pl;
	void			*ple;
	void			*pu;
	void			*pd;
	int				img_h;
	int				img_w;
}					t_img;

typedef struct s_map
{
	char			**map;
	int				x;
	int				y;
}					t_map;

typedef struct s_main
{
	int				last;
	void			*mlx;
	void			*win;
	void			*audio;
	int				p_x;
	int				p_y;
	int				coincount;
	int				ccoincount;
	int				mcount;
	int				pcount;
	int				ecount;
	t_map			*map;
	t_img			*img;
}					t_main;

// INIT
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
t_main				*main_init(char *path);
void				xpm_to_img(t_main *main);

// UTILS
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
int					ft_key_esc(t_main *game);

//UTILS2.c
void				check_cn(t_main *main);

// EVENT
int					key_event(int key, t_main *main);
int					check_esc(t_main *main, int key);

// RENDER
int					render(t_main *main);
int					render_p(t_main *main);

//DRAW
void				ft_error(char *errorcode, t_main *main);
void				draw_map(t_main *main);

//MAP //Map check
char				**map_init(char *path, t_main *main);

//MAIN
void				write_move_count(t_main *main);
void				ft_free(t_main *main);

//MAP_CHECK.c
void				map_check(t_main *main);

#endif
