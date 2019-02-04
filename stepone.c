/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:44:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 17:07:03 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inn.h"

void	ft_printlist(t_lem *lst)
{
	t_lem	*tmp;

	ft_printf("\n "YEL BOLD"INPUT DATA "RESET"\n\n");
	tmp = lst;
	while (tmp)
	{
		ft_printf(BOLD"%s\n"RESET, tmp->s);
		tmp = tmp->next;
	}
	ft_printf("\n "BOLD GREEN"BEST WAYS "RESET"\n\n");
}

void	ft_printroads(t_road *road, t_room *room)
{
	t_road	*tmp;
	int		i;

	tmp = road;
	while (tmp)
	{
		i = 0;
		while (i < tmp->len)
		{
			ft_printf(BOLD"%s"RESET, ft_name_room(tmp->path[i], room));
			if (i + 1 < tmp->len)
				ft_printf(BOLD"-"RESET);
			i++;
		}
		ft_printf("\n");
		if (tmp->len == 2)
			break ;
		tmp = tmp->next;
	}
	ft_printf("\n "BOLD BLUE"ANTS MOVE"RESET"\n\n");
}

t_lem	*ft_createlem(void)
{
	t_lem	*lem;

	if (!(lem = (t_lem *)malloc(sizeof(t_lem))))
		return (NULL);
	lem->s = NULL;
	lem->next = NULL;
	return (lem);
}

t_lem	*ft_readlem(void)
{
	char	*li;
	t_lem	*lem;
	t_lem	*tmp;
	int		vr;

	lem = ft_createlem();
	tmp = lem;
	while ((vr = get_next_line(0, &li)) > 0)
	{
		if (li[0] == '\0')
		{
			free(li);
			break ;
		}
		tmp->s = ft_strdup(li);
		tmp->next = ft_createlem();
		tmp = tmp->next;
		free(li);
	}
	if (vr < 0)
		ft_error_manage(11);
	ft_dellast(lem);
	return (lem);
}
