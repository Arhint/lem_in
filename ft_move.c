/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:20:42 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 16:34:33 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

char	*ft_name_room(int id, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->id == id)
			return (tmp->s);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_find_pos(t_road *road, int cur)
{
	int		i;
	t_road	*tmp;

	tmp = road;
	while (tmp)
	{
		i = 0;
		while (i < tmp->len)
		{
			if (tmp->path[i] == cur)
				return (tmp->path[++i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (-1);
}

int		ft_check_pos(int check, int *tab, t_sec *sec, int fin)
{
	int		i;

	i = 0;
	if (check == fin)
		return (1);
	while (i < sec->ant)
	{
		if (tab[i] == check)
			return (0);
		i++;
	}
	return (1);
}

void	ft_go(t_sec *sec, t_road *road, int *tab, t_room *room)
{
	int		pos;
	t_road	*tmp;
	int		num;
	int		num2;

	num2 = 0;
	tmp = road;
	while (tmp)
	{
		num = sec->ant_num + num2;
		while (num < sec->ant)
		{
			if (tab[num] != tmp->path[tmp->len - 1])
				pos = ft_find_pos(tmp, tab[num]);
			if (ft_check_pos(pos, tab, sec, tmp->path[tmp->len - 1]))
			{
				tab[num] = pos;
				ft_printf(BOLD"L%d-%s "RESET,
						num + 1, ft_name_room(tab[num], room));
				num2++;
			}
			num++;
		}
		tmp = tmp->next;
	}
}

void	ft_tab(t_sec *sec, t_road *road, t_room *room)
{
	int		i;
	int		*tab;
	int		fin;

	i = 0;
	fin = road->path[road->len - 1];
	if (!(tab = (int *)malloc(sizeof(int) * sec->ant)))
		return ;
	while (i < sec->ant)
		tab[i++] = road->path[0];
	while (sec->ant_num < sec->ant)
	{
		if (tab[sec->ant_num] == fin)
			sec->ant_num++;
		else
		{
			ft_go(sec, road, tab, room);
			sec->ant_num = 0;
			ft_printf("\n");
		}
	}
	ft_printf("\n");
	free(tab);
}
