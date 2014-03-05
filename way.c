/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:03:00 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/03 11:03:01 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		get_way(t_data *data)
{
	t_room	*room;

	room = data->last_room;
	data->way = NULL;
	while (room->prev_way)
	{
		data->way = ft_new_room_way(room, data->way);
		if (data->last_way == NULL)
			data->last_way = data->way;
		room = room->prev_way;
	}
	data->way = ft_new_room_way(room, data->way);
	data->first_way = data->way;
	return (0);
}

t_way	*ft_new_room_way(t_room *room, t_way *next_room)
{
	t_way	*new_way;

	new_way = (t_way *)malloc(sizeof(t_way));
	new_way->name = room->name;
	new_way->ant = 0;
	new_way->prev = NULL;
	new_way->next = next_room;
	return (new_way);
}

int		way_manager(t_data *data)
{
	check_way(data, 0, data->first_room, NULL);
	get_way(data);
	if (data->first_way->next == NULL)
	{
		ft_putstr("ERROR : No complete way.\n");
		return (1);
	}
	/*aff_test_rev_way(&data);
	ft_putstr("\n");
	aff_test_way(&data);
	ft_putstr("\n");*/
	ants_moove(data);
	return (0);
}

int		ants_moove(t_data *data)
{
	t_way	*tbl[data->nbr_ants];
	int		tmp;
	int		i;

	init_tbl_ants(data, tbl);
	tmp = 0;
	while (tbl[data->nbr_ants - 1] != data->last_way)
	{
		i = 0;
		while (i != tmp + 1)
		{
			if (tbl[i] && tbl[i]->next)
				tbl[i] = tbl[i]->next;
			else
				tbl[i] = NULL;
			i++;
		}
		display_moove(tbl, data);
		if (tmp < data->nbr_ants - 1)
			tmp++;
	}
	return (0);
}

int		init_tbl_ants(t_data *data, t_way **tbl)
{
	int		tmp;

	tmp = 0;
	while (tmp != data->nbr_ants)
	{
		tbl[tmp] = data->first_way;
		tmp++;
	}
	return (0);
}
