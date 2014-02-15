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

t_room	*ft_new_room(t_data *data, char *line)
{
	char		**tmp;
	t_room		*room;

	(void)data;
	room = (t_room *)malloc(sizeof(t_room));
	tmp = ft_strsplit(line, ' ');
	room->name = ft_strdup(tmp[0]);
	room->x = ft_atoi(tmp[1]);
	room->y = ft_atoi(tmp[2]);
	room->next = NULL;
	room->special = 0;
	return (room);
}
