/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:54:29 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/03 16:08:18 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <stdarg.h>
# include <inttypes.h>
# include "libft.h"

# define RESET	"\x1b[0m"
# define BOLD	"\x1b[1m"
# define BLACK	"\x1b[30m"
# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YEL	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define WHITE	"\x1b[37m"

typedef struct	s_flg
{
	int			minus;
	int			plusik;
	int			space;
	int			zero;
	int			hash;
	int			width;
	int			prec;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			rin;
	int			sign;
}				t_flg;

intmax_t		ft_atoll(const char *str);
/*
** ft_create_flg
*/
t_flg			*ft_create_flg(void);
int				ft_fill_flg(t_flg *lol, char *s, int i);
int				ft_width(t_flg *lol, char *s, int i);
int				ft_precision(t_flg *lol, char *s, int i);
int				ft_length(t_flg *lol, char *s, int i);
/*
** ft_doflagxo
*/
void			ft_print_widthx(t_flg *lol, char *s, int c);
void			ft_notminusx(t_flg *lol, char *s, int len, int c);
/*
** ft_itoa_base
*/
char			*ft_itoa_basell(intmax_t value, int base);
char			*ft_itoa_baseull(unsigned long long value, int base);
/*
** ft_print_c
*/
int				ft_print_cc(t_flg *lol, char c);
int				ft_print_c(va_list ap, t_flg *lol);
int				ft_helpcbig5(t_flg *lol, int c);
int				ft_helpcbig4(t_flg *lol, int c);
int				ft_print_cbig(va_list ap, t_flg *lol);
/*
** ft_print_di
*/
int				ft_print_res(t_flg *lol, char *s, int len);
void			ft_print_width(t_flg *lol, char *s);
void			ft_print_prec(t_flg *lol, int len);
int				ft_print_flagsdi(t_flg *lol, char *s, int len);
int				ft_print_di(va_list ap, t_flg *lol, int c);
/*
** ft_print_flags
*/
void			ft_plus_space(t_flg *lol, char *s);
int				ft_print_zerodi(t_flg *lol, char *s, int len);
void			ft_notminus(t_flg *lol, char *s, int len);
void			ft_zerospace(t_flg *lol);
/*
** ft_print_o
*/
int				ft_print_o(va_list ap, t_flg *lol, int c);
void			ft_print_hasho(t_flg *lol, char *s, int c);
int				ft_rei(t_flg *lol, int i);
/*
** ft_print_p
*/
void			ft_print_piks(t_flg *lol, int c);
int				ft_print_pe(t_flg *lol, char *s, int len, int c);
int				ft_print_p(va_list ap, t_flg *lol);
/*
** ft_print_s
*/
int				ft_print_bigs(va_list ap, t_flg *lol);
int				ft_print_s(va_list ap, t_flg *lol);
int				ft_zeros(t_flg *lol);
int				ft_minuss(t_flg *lol, char *s, int len);
int				ft_print_es(t_flg *lol, char *s);
/*
** ft_printhelp_s
*/
int				ft_lenwchar(wchar_t s);
int				ft_lenswchar(wchar_t *s);
int				ft_minusbigs(t_flg *lol, wchar_t *s, int len);
int				ft_helpprec(wchar_t *s, int len);
int				ft_print_bs(t_flg *lol, wchar_t *s);
/*
** ft_print_u
*/
int				ft_print_u(va_list ap, t_flg *lol, int c);
int				ft_print_b(va_list ap, t_flg *lol);
/*
** ft_print_x
*/
void			ft_print_hashx(t_flg *lol, char *s, int c);
void			ft_minuswidth(t_flg *lol, int c);
int				ft_print_xx(t_flg *lol, char *s, int len, int c);
int				ft_print_x(va_list ap, t_flg *lol, int c);
char			*ft_bigx(char *s);
/*
** ft_printf
*/
t_flg			*ft_reset_flg(t_flg *lol);
int				ft_cook(char *s, va_list ap, int i, t_flg *lol);
int				ft_define(char *s, va_list ap, t_flg *lol);
int				ft_printf(char *format, ...);

#endif
