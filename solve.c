/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:13:23 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 16:39:19 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

void	ft_saveroads(t_sec *sec, int len, t_road *road)
{
	t_road	*tmp;
	int		i;

	i = 0;
	tmp = road;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->path = (int *)malloc(sizeof(int) * len)))
		return ;
	tmp->len = len;
	while (i < len)
	{
		tmp->path[i] = sec->buffer[i];
		i++;
	}
	tmp->next = ft_createroad();
}

void	ft_dfs(int start, t_sec *sec, int len, t_road *road)
{
	int		v;

	v = 0;
	sec->visit[start] = 1;
	sec->buffer[len] = start;
	len++;
	if (start == sec->iend)
		ft_saveroads(sec, len, road);
	else
	{
		while (v < sec->max_id)
		{
			if (sec->mas[start][v] && !sec->visit[v])
				ft_dfs(v, sec, len, road);
			v++;
		}
	}
	sec->visit[start] = 0;
	len--;
}

void	ft_solve(t_sec *sec, t_road *road)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	sec->visit = (int *)malloc(sizeof(int) * sec->max_id);
	sec->buffer = (int *)malloc(sizeof(int) * sec->max_id);
	while (i < sec->max_id)
	{
		sec->visit[i] = 0;
		i++;
	}
	ft_dfs(sec->istart, sec, len, road);
	if (road->path == NULL)
		ft_error_manage(10);
	ft_dellastr(road);
}

int		ft_sharp(char *s, t_sec *sec)
{
	if (!ft_strcmp(s, "##start"))
		sec->hstart++;
	if (!ft_strcmp(s, "##end"))
		sec->hend++;
	if (!ft_strcmp(s, "##start") && sec->hstart >= 2)
		ft_error_manage(6);
	if (!ft_strcmp(s, "##end") && sec->hend >= 2)
		ft_error_manage(6);
	return (0);
}

int		ft_room_valid(char *s)
{
	int		i;

	i = 0;
	if (s[0] == 'L')
		ft_error_manage(1);
	while (s[i] != ' ' && s[i])
		i++;
	if (s[i] == '\0')
		ft_error_manage(3);
	if (!ft_isdigit(s[++i]))
		ft_error_manage(2);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] != ' ')
		ft_error_manage(2);
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			ft_error_manage(2);
	}
	return (1);
}
