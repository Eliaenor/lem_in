/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 21:07:53 by vcourtin          #+#    #+#             */
/*   Updated: 2014/02/11 21:07:54 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	char	*line;
	t_data	data;
	int		i;
	int		test;
	t_room	*room;
	t_room	*tmp;

	i = 0;
	test = 0;
	get_next_line(0, &line);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			test++;
		i++;
	}
	if ((int)ft_strlen(line) - 1 == test)
		data.nbr_ants = ft_atoi(line);
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			free(line);
			get_next_line(0, &line);
			room = ft_new_room(&data, line);
			if (data.rooms == NULL)
				data.rooms = room;
			else
			{
				tmp = data.rooms;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = room;
			}
			data.first_room = room;
			data.first_room->special = 1;
			free(line);
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			free(line);
			get_next_line(0, &line);
			ft_putstr("TEST");
			room = ft_new_room(&data, line);
			if (data.rooms == NULL)
				data.rooms = room;
			else
			{
				tmp = data.rooms;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = room;
			}
			data.last_room = room;
			data.last_room->special = LAST;
			free(line);
		}
		else if (line[0] == '#')
			free(line);
		else if (ft_strchr(line, ' ') != NULL)
		{
			if (data.rooms == NULL)
				data.rooms = ft_new_room(&data, line);
			else
			{
				tmp = data.rooms;
				room = ft_new_room(&data, line);
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = room;
			}
			free(line);
		}
		else
		{
			ft_putstr("Else : ");
			ft_putendl(line);
			free(line);
		}
	}
	data.nbr_rooms = 0;
	tmp = data.rooms;
	while (tmp->next != NULL)
	{
		data.nbr_rooms++;
		tmp = tmp->next;
		if (tmp->next == NULL)
			data.nbr_rooms++;
	}
	ft_putstr("Number of ants = ");
	ft_putnbr(data.nbr_ants);
	ft_putstr("\n");
	ft_putstr("Number of room = ");
	ft_putnbr(data.nbr_rooms);
	tmp = data.rooms;
	while (tmp->next != NULL)
	{
		if (tmp->special == FIRST)
		{
			ft_putstr("\nFirst = ");
			ft_putstr(tmp->name);
			ft_putstr(" x = ");
			ft_putnbr(tmp->x);
			ft_putstr(" y = ");
			ft_putnbr(tmp->y);
		}
		tmp = tmp->next;
		if (tmp->next == NULL && tmp->special == FIRST)
		{
			ft_putstr("\nFirst = ");
			ft_putstr(tmp->name);
			ft_putstr(" x = ");
			ft_putnbr(tmp->x);
			ft_putstr(" y = ");
			ft_putnbr(tmp->y);
		}
	}
	tmp = data.rooms;
	while (tmp->next != NULL)
	{
		if (tmp->special == LAST)
		{
			ft_putstr("\nLast = ");
			ft_putstr(tmp->name);
			ft_putstr(" x = ");
			ft_putnbr(tmp->x);
			ft_putstr(" y = ");
			ft_putnbr(tmp->y);
		}
		tmp = tmp->next;
		if (tmp->next == NULL && tmp->special == LAST)
		{
			ft_putstr("\nLast = ");
			ft_putstr(tmp->name);
			ft_putstr(" x = ");
			ft_putnbr(tmp->x);
			ft_putstr(" y = ");
			ft_putnbr(tmp->y);
		}
	}
	tmp = data.rooms;
	while (tmp->next != NULL)
	{
		if (tmp->special == NORMAL)
		{
			ft_putstr("\nRoom = ");
			ft_putstr(tmp->name);
			ft_putstr(" x = ");
			ft_putnbr(tmp->x);
			ft_putstr(" y = ");
			ft_putnbr(tmp->y);
		}
		tmp = tmp->next;
		if (tmp->next == NULL && tmp->special == NORMAL)
		{
			ft_putstr("\nRoom = ");
			ft_putstr(tmp->name);
			ft_putstr(" x = ");
			ft_putnbr(tmp->x);
			ft_putstr(" y = ");
			ft_putnbr(tmp->y);
		}
	}
	ft_putstr("\n");
	return (0);
}
