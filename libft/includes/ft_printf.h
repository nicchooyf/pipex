/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/28 17:32:03 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef unsigned long long	t_ull;
typedef struct s_pf
{
	va_list	arg;
	int		upper;
	int		width;
	int		pad;
	int		len;
	int		hexlen;
	int		left;
	int		zero;
	int		precision;
	int		dot;
	int		star;
	int		hash;
	int		space;
	int		plus;
}	t_pf;

int		ft_printf(const char *flag, ...);
int		ft_printchar(t_pf *flag);
void	ft_putnbr_base(t_ull point, t_pf *flag, char *base);
void	ft_putnbr(t_pf *flag, size_t nb);
void	ft_printstr(t_pf *flag);
void	ft_printptr(t_pf *flag);
void	ft_printint(t_pf *flag);
void	ft_printuint(t_pf *flag);
void	ft_printhex(t_pf *flag);
int		ft_check_flags(t_pf *flag, const char *str, int i);
int		ft_check_type(t_pf *flag, const char *str, int i);
void	check_left(t_pf *flag, int len);
void	check_right(t_pf *flag, int len);
void	check_zero(t_pf *flag, int len);
void	ft_pad_space(t_pf *flag, int len);
void	ft_pad_zero(t_pf *flag, int len);
int		check_precision_int(t_pf *flag, int len, int nb);
int		check_precision_uint(t_pf *flag, int len, unsigned int nb);
int		check_precision_str(t_pf *flag, int len);

#endif