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
	int					special;
	int					ants_here;
	struct	s_room		**connect_room;
	struct	s_room		*next;
}						t_room;

typedef struct			s_link
{
	t_room				*room1;
	t_room				*room2;
	struct	s_link		*next;
}						t_link;

typedef struct	s_data
{
	int			nbr_ants;
	int			nbr_rooms;
	t_room		*rooms;
	t_room		*first_room;
	t_room		*last_room;
	t_link		*links;
}				t_data;

t_room	*ft_new_room(t_data *data, char *line);

#endif
