/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 21:08:05 by vcourtin          #+#    #+#             */
/*   Updated: 2014/02/11 21:08:07 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "./libft/includes/libft.h"

# define FIRST		1
# define LAST		2
# define NORMAL		0

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					weight;
	int					special;
	struct s_room		*prev_way;
	struct s_room		**connect_room;
	struct s_room		*next;
}						t_room;

typedef struct			s_way
{
	char				*name;
	int					ant;
	struct s_way		*prev;
	struct s_way		*next;
}						t_way;

typedef struct	s_data
{
	int			nbr_ants;
	int			nbr_rooms;
	t_room		*rooms;
	t_room		*first_room;
	t_room		*last_room;
	t_way		*way;
	t_way		*first_way;
	t_way		*last_way;
}				t_data;

/*
** main.c **
*/

int		ft_setup(t_data *data);
int		display_moove(t_way **tbl, t_data *data);
int		get_nbr_ants(t_data *data, char *line);

/*
** way.c **
*/

int		get_way(t_data *data);
t_way	*ft_new_room_way(t_room *room, t_way *next_room);
int		way_manager(t_data *data);
int		ants_moove(t_data *data);
int		init_tbl_ants(t_data *data, t_way **tbl);

/*
** ft_parsing.c **
*/

int		ft_parsing(t_data *data, char *line);
int		pars_start_end(t_data *data, char *line, int special);
int		pars_room(t_data *data, char *line, int special);
int		check_line_room(char *line);


/*
** ft_dijktra.c **
*/

int		check_way(t_data *data, int weight, t_room *room, t_room *prev);
int		ft_plus_connect(t_room *room, t_room *newdest);
t_room	*ft_new_room(char *line, int special);

/*
** main.c **
*/

int		split_parsing(t_data *data, char *line);
int		pars_link(t_data *data, char *line);


#endif
