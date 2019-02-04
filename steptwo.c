/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steptwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:41:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 17:56:02 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

t_sec	*ft_createsec(void)
{
	t_sec	*sec;

	if (!(sec = (t_sec *)malloc(sizeof(t_sec))))
		return (NULL);
	sec->ant = 0;
	sec->ant_num = 0;
	sec->start = NULL;
	sec->end = NULL;
	sec->hstart = 0;
	sec->hend = 0;
	sec->stage = 0;
	sec->max_id = 0;
	sec->istart = -1;
	sec->iend = -1;
	sec->buffer = NULL;
	return (sec);
}

t_way	*ft_createway(void)
{
	t_way	*way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (NULL);
	way->one = NULL;
	way->two = NULL;
	way->id1 = -1;
	way->id2 = -1;
	way->next = NULL;
	return (way);
}

t_road	*ft_createroad(void)
{
	t_road	*road;

	if (!(road = (t_road *)malloc(sizeof(t_road))))
		return (NULL);
	road->path = NULL;
	road->len = 0;
	road->next = NULL;
	return (road);
}

t_room	*ft_createroom(void)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->s = NULL;
	room->next = NULL;
	room->id = 0;
	return (room);
}

void	ft_manipulate(t_lem *lem, t_sec *sec, t_way *way, t_room *room)
{
	t_lem		*tmpl;

	tmpl = lem;
	if (!tmpl || !tmpl->next || !tmpl->next->next)
		ft_error_manage(7);
	while (tmpl)
	{
		if (sec->stage == 1)
			ft_rooms(tmpl->s, sec, room);
		if (sec->stage == 2)
			if (!ft_ways(tmpl->s, way, room, sec))
			{
				ft_strdel(&tmpl->s);
				ft_delonelem(lem);
				break ;
			}
		if (sec->stage == 0 || sec->ant == 0)
			ft_ants(tmpl->s, sec);
		tmpl = tmpl->next;
	}
	if (sec->stage < 2)
		ft_error_manage(7);
	ft_dellastroom(room);
	ft_dellastw(way);
	ft_search_id_start_end(sec, room);
}
