/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 09:50:17 by vcourtin          #+#    #+#             */
/*   Updated: 2014/02/12 09:50:20 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*ft_new_room(char *line, int special)
{
	char		**tmp;
	t_room		*room;

	room = (t_room *)malloc(sizeof(t_room));
	tmp = ft_strsplit(line, ' ');
	room->name = ft_strdup(tmp[0]);
	room->x = ft_atoi(tmp[1]);
	room->y = ft_atoi(tmp[2]);
	room->weight = -1;
	room->connect_room = (t_room **)malloc(sizeof(t_room *));
	room->connect_room[0] = NULL;
	room->prev_way = NULL;
	room->next = NULL;
	if (special == FIRST)
	{
		room->weight = 0;
		room->special = FIRST;
	}
	else if (special == 2)
		room->special = 2;
	else
		room->special = NORMAL;
	return (room);
}

int		ft_plus_connect(t_room *room, t_room *newdest)
{
	t_room	**newtab;
	int		i;

	i = 0;
	while (room->connect_room[i] != NULL)
		i++;
	newtab = (t_room **)malloc(sizeof(t_room *) * (i + 2));
	i = 0;
	while (room->connect_room[i] != NULL)
	{
		newtab[i] = room->connect_room[i];
		i++;
	}
	newtab[i] = newdest;
	newtab[i + 1] = NULL;
	free(room->connect_room);
	room->connect_room = newtab;
	return (0);
}
