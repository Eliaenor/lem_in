/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:45:25 by vcourtin          #+#    #+#             */
/*   Updated: 2014/02/19 14:45:27 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_parsing(t_data *data, char *line)
{
	ft_putendl(line);
	if (ft_strcmp(line, "##start") == 0)
	{
		free(line);
		get_next_line(0, &line);
		ft_putendl(line);
		if (pars_room(data, line, FIRST) == 1)
			return (1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		free(line);
		get_next_line(0, &line);
		ft_putendl(line);
		if (pars_room(data, line, 2) == 1)
			return (1);
	}
	else if (line[0] == '#')
		free(line);
	else if (ft_strchr(line, ' ') != NULL)
	{
		if (pars_room(data, line, NORMAL) == 1)
			return (1);
	}
	else
	{
		if (data->first_room == NULL)
		{
			ft_putstr("ERROR : No Start Room.\n");
			return (1);
		}
		if (data->last_room == NULL)
		{
			ft_putstr("ERROR : No End Room.\n");
			return (1);
		}
		if (pars_link(data, line) == 1)
			return (2);
	}
	return (0);
}

int		pars_room(t_data *data, char *line, int special)
{
	t_room	*room;
	t_room	*tmp;

	if (check_line_room(line) == 1)
		return (1);
	room = ft_new_room(line, special);
	if (data->rooms == NULL)
		data->rooms = room;
	else
	{
		tmp = data->rooms;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = room;
	}
	if (special == FIRST)
		data->first_room = room;
	if (special == LAST)
		data->last_room = room;
	free(line);
	return (0);
}

int		pars_link(t_data *data, char *line)
{
	t_room	*src;
	t_room	*dest;
	char	**linesplit;

	linesplit = ft_strsplit(line, '-');
	free(line);
	if (linesplit[2] != NULL)
		return (1);
	src = data->first_room;
	while (src && ft_strcmp(src->name, linesplit[0]) != 0)
		src = src->next;
	if (src == NULL)
		return (1);
	dest = data->first_room;
	while (dest && ft_strcmp(dest->name, linesplit[1]) != 0)
		dest = dest->next;
	if (dest == NULL)
		return (1);
	ft_plus_connect(src, dest);
	free(linesplit);
	return (0);
}

int		check_line_room(char *line)
{
	char	**tbl;

	tbl = ft_strsplit(line, ' ');
	if (tbl[0] != NULL && tbl[1] != NULL && tbl[2] != NULL && tbl[3] == NULL)
	{
		if (ft_strchr(tbl[0], '-') != NULL)
			return (1);
		if (ft_isnumber(tbl[1]) == 0)
			return (1);
		if (ft_isnumber(tbl[2]) == 0)
			return (1);
		return (0);
	}
	return (1);
}
