/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:02:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 16:30:36 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_INN_H
# define LEM_INN_H

# include "libft/includes/libft.h"

typedef struct		s_lem
{
	char			*s;
	struct s_lem	*next;
}					t_lem;

typedef struct		s_room
{
	char			*s;
	int				id;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_sec
{
	int				max_id;
	int				stage;
	int				ant;
	int				ant_num;
	int				hstart;
	int				hend;
	char			*start;
	char			*end;
	int				**mas;
	int				*visit;
	int				istart;
	int				iend;
	int				*buffer;
}					t_sec;

typedef struct		s_way
{
	char			*one;
	char			*two;
	int				id1;
	int				id2;
	struct s_way	*next;
}					t_way;

typedef struct		s_road
{
	int				*path;
	int				len;
	struct s_road	*next;
}					t_road;

t_sec				*ft_createsec(void);
t_lem				*ft_readlem(void);
t_lem				*ft_createlem(void);
t_road				*ft_createroad(void);
t_way				*ft_createway(void);
t_room				*ft_createroom(void);
t_lem				*ft_dellast(t_lem *lst);
t_way				*ft_dellastw(t_way *lst);
t_room				*ft_dellastroom(t_room *lst);
void				ft_manipulate(t_lem *lem, t_sec *sec,
								t_way *way, t_room *room);
int					ft_ways(char *s, t_way *way, t_room *room, t_sec *sec);
void				ft_rooms2(char *s, t_room *tmp, t_sec *sec);
void				ft_rooms(char *s, t_sec *sec, t_room *room);
void				ft_ants(char *s, t_sec *sec);
void				ft_search_id_start_end(t_sec *sec, t_room *room);
void				ft_printlist(t_lem *lst);
void				ft_printroads(t_road *road, t_room *room);
void				ft_int_tab(t_sec *sec, t_way *way);
void				ft_cr_inttab(t_sec *sec, t_way *way);
void				ft_solve(t_sec *sec, t_road *road);
void				ft_dfs(int start, t_sec *sec, int len, t_road *road);
void				ft_ways2(t_room *room, t_way *way);
void				ft_saveroads(t_sec *sec, int len, t_road *road);
t_road				*ft_dellastr(t_road *road);
t_road				*ft_sort_by_len(t_road *road);
int					ft_check_unipat(t_road *a, t_road *b);
t_road				*ft_del_one_node(t_road *a, t_road *b);
t_road				*ft_del_waste(t_road *road);
void				ft_tab(t_sec *sec, t_road *road, t_room *room);
void				ft_go(t_sec *sec, t_road *road, int *tab, t_room *room);
int					ft_check_pos(int check, int *tab, t_sec *sec, int fin);
int					ft_find_pos(t_road *road, int cur);
char				*ft_name_room(int id, t_room *room);
void				ft_error_manage(int err);
void				ft_check_coord(t_room *room);
int					ft_check_ways(char *s1, char *s2, t_room *room);
int					ft_compare(char *s, t_room *room);
int					ft_sharp(char *s, t_sec *sec);
int					ft_blaks(char *s);
void				ft_delonelem(t_lem *lem);
int					ft_room_valid(char *s);
int					ft_sharp2(t_sec *sec, char *s);

#endif
