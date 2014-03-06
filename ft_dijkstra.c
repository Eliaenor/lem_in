/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 22:50:07 by vcourtin          #+#    #+#             */
/*   Updated: 2014/02/20 22:50:10 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			check_way(t_data *data, int weight, t_room *room, t_room *prev)
{
	int		i;

	if (weight <= room->weight || room->weight == -1)
		room->weight = weight;
	else
		return (0);
	i = 0;
	room->prev_way = prev;
	while (room->connect_room[i])
	{
		if ((room->connect_room[i]->weight > weight + 1
			|| room->connect_room[i]->weight == -1))
		{
			check_way(data, weight + 1, room->connect_room[i], room);
		}
		i++;
	}
	return (0);
}

t_room		*ft_new_room(char *line, int special)
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

int			ft_plus_connect(t_room *room, t_room *newdest)
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
