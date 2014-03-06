/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 13:29:18 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/06 13:29:20 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		split_parsing(t_data *data, char *line)
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
