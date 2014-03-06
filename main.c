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
	int		ret;

	ft_setup(&data);
	get_next_line(0, &line);
	ft_putendl(line);
	if (get_nbr_ants(&data, line) == 1)
		return (1);
	while (get_next_line(0, &line))
	{
		ret = ft_parsing(&data, line);
		if (ret == 1)
		{
			ft_putstr("ERROR : Syntax Error\n");
			return (1);
		}
		if (ret == 2)
			break ;
	}
	way_manager(&data);
	return (0);
}

int		ft_setup(t_data *data)
{
	data-> rooms = NULL;
	data-> first_room = NULL;
	data-> last_room = NULL;
	data-> way = NULL;
	data-> first_way = NULL;
	data-> last_way = NULL;
	return (0);
}

int		display_moove(t_way **tbl, t_data *data)
{
	int		i;

	i = 0;
	while (i != data->nbr_ants)
	{
		if (tbl[i] && tbl[i] != data->first_way)
		{
			ft_putstr("L");
			ft_putnbr(i + 1);
			ft_putstr("-");
			ft_putstr(tbl[i]->name);
			ft_putstr(" ");
		}
		i++;
	}
	ft_putstr("\n");
	return (0);
}

int		get_nbr_ants(t_data *data, char *line)
{
	if (ft_isnumber(line) == 1)
		data->nbr_ants = ft_atoi(line);
	else
	{
		ft_putstr("ERROR : Incorect Number of ants.\n");
		return (1);
	}
	if (data->nbr_ants == 0)
	{
		ft_putstr("ERROR : Put at least 1 ant.\n");
		return (1);
	}
	return (0);
}

