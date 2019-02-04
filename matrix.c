/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:04:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 17:56:23 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

void	ft_cr_inttab(t_sec *sec, t_way *way)
{
	t_way	*tmp;

	tmp = way;
	while (tmp)
	{
		sec->mas[tmp->id1][tmp->id2] = 1;
		sec->mas[tmp->id2][tmp->id1] = 1;
		tmp = tmp->next;
	}
}

void	ft_int_tab(t_sec *sec, t_way *way)
{
	int		i;
	int		j;

	i = 0;
	sec->mas = (int **)malloc(sizeof(int *) * sec->max_id);
	while (i < sec->max_id)
	{
		sec->mas[i] = (int *)malloc(sizeof(int) * sec->max_id);
		j = 0;
		while (j < sec->max_id)
		{
			sec->mas[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_cr_inttab(sec, way);
}

void	ft_search_id_start_end(t_sec *sec, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (!ft_strcmp(tmp->s, sec->start))
			sec->istart = tmp->id;
		if (!ft_strcmp(tmp->s, sec->end))
			sec->iend = tmp->id;
		tmp = tmp->next;
	}
}

void	ft_error_manage(int err)
{
	if (err == 1)
		ft_printf("\x1b[31m\x1b[1mWrong name of room\x1b[0m""\n");
	if (err == 2)
		ft_printf("\x1b[31m\x1b[1mWrong coordinates\x1b[0m""\n");
	if (err == 3)
		ft_printf("\x1b[31m\x1b[1mNo coordinates\x1b[0m""\n");
	if (err == 4)
		ft_printf("\x1b[31m\x1b[1mWrong links\x1b[0m""\n");
	if (err == 5)
		ft_printf("\x1b[31m\x1b[1mNon-existent room in links\x1b[0m""\n");
	if (err == 6)
		ft_printf("\x1b[31m\x1b[1mMulti end or start\x1b[0m""\n");
	if (err == 7)
		ft_printf("\x1b[31m\x1b[1mWrong map\x1b[0m""\n");
	if (err == 8)
		ft_printf("\x1b[31m\x1b[1mERROR of ANTS!\x1b[0m""\n");
	if (err == 9)
		ft_printf("\x1b[31m\x1b[1mNo end or start\x1b[0m""\n");
	if (err == 10)
		ft_printf("\x1b[31m\x1b[1mNo path\x1b[0m""\n");
	if (err == 11)
		ft_printf("\x1b[31m\x1b[1mWrong file\x1b[0m""\n");
	exit(0);
}
