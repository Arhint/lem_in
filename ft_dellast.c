/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:21:21 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 16:21:21 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

t_road	*ft_dellastr(t_road *road)
{
	t_road	*tmp;

	tmp = road;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
	return (road);
}

t_lem	*ft_dellast(t_lem *lst)
{
	t_lem	*tmp;

	tmp = lst;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
	return (lst);
}

t_room	*ft_dellastroom(t_room *lst)
{
	t_room	*tmp;

	tmp = lst;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
	return (lst);
}

t_way	*ft_dellastw(t_way *lst)
{
	t_way	*tmp;

	tmp = lst;
	if (tmp && tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
	return (lst);
}

int		ft_sharp2(t_sec *sec, char *s)
{
	ft_sharp(s, sec);
	return (1);
}
