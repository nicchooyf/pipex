/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:46:13 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:19:59 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Handles '#' flag
 */
static void	check_hash(t_pf *flag, unsigned int lu)
{
	if (flag->hash)
	{
		if (lu != 0)
		{
			if (flag->upper)
				flag->len += write(1, "0X", 2);
			else
				flag->len += write(1, "0x", 2);
		}
		flag->hash = 0;
	}
}

/*
 *	Get print length to pass into width functions
 *	
 *	Updates hexlen member in the struct
 */
static void	get_hex_length(t_ull point, t_pf *p)
{
	if (point >= 16)
	{
		get_hex_length(point / 16, p);
		get_hex_length(point % 16, p);
	}
	if (point < 16)
		p->hexlen++;
}

/*
 *	Function to print 'X' and 'x' types, depending on
 *	value of flag->upper
 *
 *	Passes hexadecimal base to ft_putnbr_base
 */
void	ft_printhex(t_pf *flag)
{
	unsigned int	lu;
	char			*base;

	lu = va_arg(flag->arg, unsigned long);
	if (flag->upper)
		base = ft_strdup("ABCDEF");
	else
		base = ft_strdup("abcdef");
	get_hex_length(lu, flag);
	flag->hexlen = check_precision_uint(flag, flag->hexlen, lu);
	check_left(flag, flag->hexlen);
	check_zero(flag, flag->hexlen);
	check_hash(flag, lu);
	if (lu)
		ft_putnbr_base(lu, flag, base);
	else if (!flag->dot || flag->precision > 0)
		flag->len += write(1, "0", 1);
	check_right(flag, flag->hexlen);
	free(base);
	flag->hexlen = 0;
}
