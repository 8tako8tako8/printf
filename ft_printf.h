/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:39:44 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/04 14:22:14 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_fmt
{
	int				flag;
	int				width;
	int				precision;
	int				d;
	unsigned int	u;
	unsigned char	c;
	char			*s;
	void			*p;
	unsigned int	x;
	int				digit;
}					t_fmt;

void				ft_get_precision(const char **str, va_list *ap, t_fmt *fmt);
void				ft_get_width(const char **str, va_list *ap, t_fmt *fmt);
void				ft_get_flag(const char **str, t_fmt *fmt);
void				ft_get_flag_pctpct(const char **str, t_fmt *fmt);
void				ft_get_type_and_output_d(const char **str, va_list *ap, \
	int *count, t_fmt *fmt);
void				ft_get_type_and_output_u(const char **str, va_list *ap, \
	int *count, t_fmt *fmt);
void				ft_get_type_and_output_c(const char **str, va_list *ap, \
	int *count, t_fmt *fmt);
void				ft_get_type_and_output_s(const char **str, va_list *ap, \
	int *count, t_fmt *fmt);
void				ft_get_type_and_output_p(const char **str, va_list *ap, \
	int *count, t_fmt *fmt);
void				ft_get_type_and_output_x(const char **str, va_list *ap, \
	int *count, t_fmt *fmt);
void				ft_output_null_p(t_fmt *fmt, int *count);
void				ft_putnull_not_by_precision_p(t_fmt *fmt, int *count);
void				ft_putnull_p(int len, int *count);
void				ft_putspace_null_p(t_fmt *fmt, int *count);
void				ft_putzero_null_p(t_fmt *fmt, int *count);
void				ft_putnull_by_precision_p(t_fmt *fmt, int *count);
void				ft_putspace_null_2p(t_fmt *fmt, int *count);
void				ft_putnull_2p(int len, t_fmt *fmt, int *count);
void				ft_output_null_s(t_fmt *fmt, int *count);
void				ft_putnull_not_by_precision_s(t_fmt *fmt, int *count);
void				ft_putnull_s(int len, int *count);
void				ft_putspace_null_s(t_fmt *fmt, int *count);
void				ft_putzero_null_s(t_fmt *fmt, int *count);
void				ft_putnull_by_precision_s(t_fmt *fmt, int *count);
void				ft_putspace_2null_s(t_fmt *fmt, int *count);
void				ft_putnull_2_s(t_fmt *fmt, int *count);
void				ft_putzero_2null_s(t_fmt *fmt, int *count);
int					ft_printf(const char *str, ...);
void				ft_printf_str(const char **start, const char **str, \
	int *count);
void				ft_input(const char **str, va_list *ap, int *count, \
	t_fmt *fmt);
void				ft_init_fmt(t_fmt *fmt);
void				ft_output_pct(const char **str, t_fmt *fmt, int *count);
void				ft_count_putchar(char c, int *count);
int					ft_atoi_ex(const char **str);
void				ft_get_type_c(const char **str, va_list *ap, t_fmt *fmt);
void				ft_output_c(t_fmt *fmt, int *count);
void				ft_putspace_c(t_fmt *fmt, int *count);
void				ft_get_type_d(const char **str, va_list *ap, t_fmt *fmt);
void				ft_output_d(t_fmt *fmt, int *count);
void				ft_putnbr_d_sub(t_fmt *fmt, int *count);
void				ft_putnbr_d(int n, int *count);
void				ft_putnbr_2d(t_fmt *fmt, int *count);
void				ft_putspace_nbr_d(t_fmt *fmt, int *count);
void				ft_putspace_d(t_fmt *fmt, int *count);
int					ft_width_max_d(t_fmt *fmt);
void				ft_putnbr_space_d(t_fmt *fmt, int *count);
void				ft_putnbr_3d(t_fmt *fmt, int *count);
void				ft_putnbr_4d(t_fmt *fmt, int *count);
void				ft_get_type_x(const char **str, va_list *ap, t_fmt *fmt);
void				ft_output_largex(t_fmt *fmt, int *count);
void				ft_hex_convert_largex(t_fmt *fmt, char *hex_cvt);
void				ft_get_type_p(const char **str, va_list *ap, t_fmt *fmt);
void				ft_output_p(t_fmt *fmt, int *count);
void				ft_hex_convert_p(t_fmt *fmt, char *address);
void				ft_putp_not_by_precision(char *addr, t_fmt *fmt, \
	int *count);
void				ft_putaddr_p(char *address, t_fmt *fmt, int *count);
void				ft_putspace_p(t_fmt *fmt, int *count);
void				ft_putp_by_precision(char *addr, t_fmt *fmt, int *count);
void				ft_putspace_2p(t_fmt *fmt, int *count);
void				ft_putaddr_2p(char *address, t_fmt *fmt, int *count);
void				ft_get_type_s(const char **str, va_list *ap, t_fmt *fmt);
void				ft_output_s(t_fmt *fmt, int *count);
void				ft_puts_not_by_precision(t_fmt *fmt, int len, int *count);
void				ft_putstr_s(t_fmt *fmt, int len, int *count);
void				ft_putspace_s(t_fmt *fmt, int len, int *count);
void				ft_putzero_s(t_fmt *fmt, int len, int *count);
void				ft_puts_by_precision(t_fmt *fmt, int len, int *count);
void				ft_putspace_2s(t_fmt *fmt, int len, int *count);
void				ft_putstr_2s(t_fmt *fmt, int len, int *count);
void				ft_putzero_2s(t_fmt *fmt, int len, int *count);
void				ft_get_type_u(const char **str, va_list *ap, t_fmt *fmt);
void				ft_output_u(t_fmt *fmt, int *count);
void				ft_putspace_u(t_fmt *fmt, int *count);
void				ft_putnbr_u_sub(t_fmt *fmt, int *count);
void				ft_putnbr_u(unsigned int n, int *count);
void				ft_putnbr_2u(t_fmt *fmt, int *count);
void				ft_putspace_nbr_u(t_fmt *fmt, int *count);
int					ft_width_max_u(t_fmt *fmt);
void				ft_putnbr_space_u(t_fmt *fmt, int *count);
void				ft_putnbr_3u(t_fmt *fmt, int *count);
void				ft_putnbr_4u(t_fmt *fmt, int *count);
void				ft_output_x(t_fmt *fmt, int *count);
void				ft_hex_convert_x(t_fmt *fmt, char *hex_cvt);
void				ft_putnbr_x(char *hex_cvt, t_fmt *fmt, int *count);
void				ft_putnbr_2x(char *hex_cvt, t_fmt *fmt, int *count);
void				ft_putspace_nbr_x(t_fmt *fmt, char *hex_cvt, int *count);
void				ft_putspace_x(t_fmt *fmt, int *count);
int					ft_width_max_x(t_fmt *fmt);
void				ft_putspace_2x(t_fmt *fmt, int *count);
void				ft_putnbr_space_x(t_fmt *fmt, char *hex_cvt, int *count);
void				ft_putnbr_3x(char *hex_cvt, t_fmt *fmt, int *count);

#endif
