/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:37:03 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/05 06:37:05 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_isnumber(char *str)
{
	int		i;
	int		test;

	i = 0;
	test = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			test++;
		i++;
	}
	if ((int)ft_strlen(str) == test)
		return (1);
	else
		return (0);
}
