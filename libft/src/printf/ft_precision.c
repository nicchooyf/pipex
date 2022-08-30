/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:10:35 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:16:45 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Handles precision for 'i' and 'd' types
 *
 *	.n	-	Specifies that at least n digits are printed.
 *
 *			If input argument has less than n digits, the output value is left-padded 
 *			with zeros.
 *
 *			If input argument has more than n digits, the output value is not truncated.
 */
int	check_precision_int(t_pf *flag, int len, int nb)
{
	if (flag->dot)
	{
		if (flag->precision)
		{
			if (flag->precision > len)
				flag->zero = 1;
			else
				flag->zero = 0;
			if (flag->width > flag->precision && flag->precision >= len)
				flag->pad = flag->width - flag->precision;
			if (flag->precision >= len)
				flag->width = flag->precision;
		}
		else
			if (nb == 0)
				len = 0;
	}
	return (len);
}

/*
 *	Handles precision for 'u', 'x' and 'X' types
 *
 *	Similar to above, with a different parameter type
 */
int	check_precision_uint(t_pf *flag, int len, unsigned int nb)
{
	if (flag->dot)
	{
		if (flag->precision)
		{
			if (flag->precision > len)
				flag->zero = 1;
			else
				flag->zero = 0;
			if (flag->width > flag->precision && flag->precision >= len)
				flag->pad = flag->width - flag->precision;
			if (flag->precision >= len)
				flag->width = flag->precision;
		}
		else
			if (nb == 0)
				len = 0;
	}
	return (len);
}

/*
 *	Handles precision for 's' type
 *
 *	Modifies print length instead of 'width'
 */
int	check_precision_str(t_pf *flag, int len)
{
	if (flag->dot)
	{
		if (!flag->precision)
			len = 0;
		else if (len > flag->precision)
			len = flag->precision;
	}
	return (len);
}
