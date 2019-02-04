/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepthree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:15:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 18:40:45 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

void	ft_ants(char *s, t_sec *sec)
{
	int		i;

	i = 0;
	if (s[0] == '#')
		return ;
	sec->stage = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ft_error_manage(8);
		i++;
	}
	sec->ant = ft_atoi(s);
	if (sec->ant <= 0)
		ft_error_manage(8);
}

void	ft_rooms2(char *s, t_room *tmp, t_sec *sec)
{
	size_t		i;

	while (tmp->next)
		tmp = tmp->next;
	if (s[0] != '#')
	{
		tmp->s = ft_strsub(s, 0, (ft_strchr(s, ' ') - s));
		tmp->id = sec->max_id++;
		i = ft_strlen(tmp->s) + 1;
		tmp->x = ft_atoi(&(s)[i]);
		i = ft_strlen(s) - 1;
		while (ft_isdigit(s[i]))
			i--;
		tmp->y = ft_atoi(&(s)[i + 1]);
		tmp->next = ft_createroom();
	}
}

void	ft_rooms(char *s, t_sec *sec, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	if (ft_strchr(s, '-') && s[0] != '#' && ft_blaks(s))
	{
		sec->stage = 2;
		return ;
	}
	if (s[0] != '#')
		ft_room_valid(s);
	if (sec->hstart == 1 && s[0] != '#')
	{
		sec->start = ft_strsub(s, 0, (ft_strchr(s, ' ') - s));
		sec->hstart = 2;
	}
	if (sec->hend == 1 && s[0] != '#')
	{
		sec->end = ft_strsub(s, 0, (ft_strchr(s, ' ') - s));
		sec->hend = 2;
	}
	if (s[0] == '#')
		if (ft_sharp(s, sec))
			return ;
	ft_rooms2(s, tmp, sec);
}

int		ft_ways(char *s, t_way *way, t_room *room, t_sec *sec)
{
	t_way	*tmp;

	tmp = way;
	if (sec->hend != 2 || sec->hstart != 2)
		ft_error_manage(9);
	if (s[0] == '#')
		return (ft_sharp2(sec, s));
	if (ft_strchr(s, '-') && ft_blaks(s))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->one = ft_strsub(s, 0, (ft_strchr(s, '-') - s));
		tmp->two = ft_strdup(ft_strchr(s, '-') + 1);
		if (!ft_check_ways(tmp->one, tmp->two, room))
		{
			ft_strdel(&tmp->one);
			ft_strdel(&tmp->two);
			return (0);
		}
		tmp->next = ft_createway();
	}
	else
		return (0);
	return (1);
}

void	ft_ways2(t_room *room, t_way *way)
{
	t_way	*w;
	t_room	*r;

	w = way;
	if (!w->one || !w->two)
		ft_error_manage(10);
	while (w)
	{
		r = room;
		while (r)
		{
			if (!ft_strcmp(w->one, r->s))
				w->id1 = r->id;
			if (!ft_strcmp(w->two, r->s))
				w->id2 = r->id;
			r = r->next;
		}
		w = w->next;
	}
}
