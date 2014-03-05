/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:53 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/03 11:01:54 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		aff_test_rev_way(t_data *data)
{
	t_room	*room;

	room = data->last_room;
	while (room->prev_way)
	{
		ft_putstr(room->name);
		ft_putstr(" - ");
		room = room->prev_way;
	}
	ft_putstr(room->name);
	return (0);
}

int		aff_test_way(t_data *data)
{
	t_way	*way;

	way = data->way;
	while (way->next)
	{
		ft_putstr(way->name);
		ft_putstr(" - ");
		way = way->next;
	}
	ft_putstr(way->name);
	return (0);
}
