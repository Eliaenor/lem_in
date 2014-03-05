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

int		check_way(t_data *data, int weight, t_room *room, t_room *prev)
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
