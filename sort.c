/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:50:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/02 19:58:35 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

t_road	*ft_sort_by_len(t_road *road)
{
	t_road	*a;
	int		*mas;
	int		dl;

	a = road;
	while (a && a->next)
	{
		if (a->len > a->next->len)
		{
			dl = a->len;
			mas = a->path;
			a->len = a->next->len;
			a->path = a->next->path;
			a->next->len = dl;
			a->next->path = mas;
			a = road;
		}
		else
			a = a->next;
	}
	return (road);
}

int		ft_check_unipat(t_road *a, t_road *b)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	if (a->len == 2)
		return (1);
	while (a->len - i != 1 && b->len - j != 1)
	{
		while (a->len - i != 1 && b->len - j != 1)
		{
			if (a->path[i] == b->path[j])
				return (0);
			j++;
		}
		i++;
		j = 1;
	}
	return (1);
}

t_road	*ft_del_one_node(t_road *c, t_road *b)
{
	t_road	*tmp;

	tmp = b;
	c->next = b->next;
	b = b->next;
	free(tmp->path);
	free(tmp);
	return (b);
}

t_road	*ft_del_waste(t_road *road)
{
	t_road	*a;
	t_road	*b;
	t_road	*c;

	a = road;
	while (a && a->next)
	{
		c = a;
		b = a->next;
		while (b)
		{
			if (!ft_check_unipat(a, b))
				b = ft_del_one_node(c, b);
			else
			{
				c = b;
				b = b->next;
			}
		}
		a = a->next;
	}
	return (road);
}
