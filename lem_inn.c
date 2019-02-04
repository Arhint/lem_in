/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:14:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 17:56:45 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

int		main(void)
{
	t_lem	*lem;
	t_sec	*sec;
	t_way	*way;
	t_room	*room;
	t_road	*road;

	sec = ft_createsec();
	way = ft_createway();
	room = ft_createroom();
	road = ft_createroad();
	lem = ft_readlem();
	ft_manipulate(lem, sec, way, room);
	ft_check_coord(room);
	ft_ways2(room, way);
	ft_int_tab(sec, way);
	ft_solve(sec, road);
	road = ft_sort_by_len(road);
	road = ft_del_waste(road);
	if (!ft_strcmp(sec->start, sec->end))
		ft_error_manage(9);
	ft_printlist(lem);
	ft_printroads(road, room);
	ft_tab(sec, road, room);
	return (0);
}
