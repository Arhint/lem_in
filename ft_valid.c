/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:02:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 16:13:43 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

void	ft_check_coord(t_room *room)
{
	t_room	*tmp;
	t_room	*nex;

	tmp = room;
	while (tmp->next)
	{
		nex = tmp->next;
		while (nex)
		{
			if (!(ft_strcmp(tmp->s, nex->s)))
				ft_error_manage(1);
			if (tmp->x == nex->x && tmp->y == nex->y)
				ft_error_manage(2);
			nex = nex->next;
		}
		tmp = tmp->next;
	}
}

int		ft_compare(char *s, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp && tmp->next)
	{
		if (!ft_strcmp(s, tmp->s))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_check_ways(char *s1, char *s2, t_room *room)
{
	if (!ft_strcmp(s1, s2))
		return (0);
	if (!ft_compare(s1, room) || !ft_compare(s2, room))
		return (0);
	return (1);
}

int		ft_blaks(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_delonelem(t_lem *lem)
{
	t_lem	*tmp;
	t_lem	*fre;

	tmp = lem;
	while (tmp && tmp->next)
	{
		if (!tmp->s)
		{
			while (tmp)
			{
				fre = tmp;
				if (tmp->s)
					ft_strdel(&tmp->s);
				free(fre);
				tmp = tmp->next;
			}
		}
		if (tmp)
			tmp = tmp->next;
	}
}
