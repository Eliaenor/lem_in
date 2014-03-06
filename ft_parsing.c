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
		if (pars_start_end(data, line, FIRST) == 1)
			return (1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (pars_start_end(data, line, LAST) == 1)
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
		return (split_parsing(data, line));
	return (0);
}

int		pars_start_end(t_data *data, char *line, int special)
{
	free(line);
	get_next_line(0, &line);
	ft_putendl(line);
	if (pars_room(data, line, special) == 1)
		return (1);
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
