/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:52:50 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:17:06 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Checks left or right allignment
 *	Left	- Whether to print on the left i.e. Right Justify
 *	Right	- Whether to print on the right i.e. Left Justify
 *
 * 	If DOT flag is active, LEN takes PRECISION value
 * 	If 0 flag is active
 * 		If DOT flag with no PRECISION, prints space
 */
void	check_left(t_pf *flag, int len)
{
	if (flag->dot)
	{
		if (!flag->precision && flag->width)
			flag->zero = 0;
	}
	if (!flag->left && !flag->zero && flag->width)
		ft_pad_space(flag, len);
	if (flag->pad && !flag->left)
	{
		while (flag->pad)
		{
			flag->len += write(1, " ", 1);
			flag->pad--;
		}
	}
}

/*
 *	Resets flags
 *	Flag->pad when WIDTH > PRECISION
 */
void	check_right(t_pf *flag, int len)
{
	flag->dot = 0;
	flag->zero = 0;
	flag->precision = 0;
	while (flag->pad)
	{
		flag->len += write(1, " ", 1);
		flag->pad--;
	}
	if (flag->left && flag->width)
		ft_pad_space(flag, len);
}

/*
 *	Basic case:	- inactive, 0 active
 *	Else case:	- active with . value > LEN
 */
void	check_zero(t_pf *flag, int len)
{
	if (flag->zero && flag->dot && flag->precision == 0)
		return ;
	if (!flag->left && flag->zero && flag->width)
		ft_pad_zero(flag, len);
	if (flag->precision > len && flag->left)
		ft_pad_zero(flag, len);
}

/*
 *	Pads with spaces up to specified width
 *  Len - Length of printed type
 * 
 *	If len > width, no padding
 */
void	ft_pad_space(t_pf *flag, int len)
{
	if (flag->width >= len)
	{
		flag->width -= len;
		while (flag->width > 0)
		{
			flag->len += write(1, " ", 1);
			flag->width--;
		}
	}
	flag->width = 0;
}

/*
 *	Pads with 0 up to the specified width
 *	Len - Length of printed type
 *
 * 	If len > width, no padding
 */
void	ft_pad_zero(t_pf *flag, int len)
{
	if (flag->width > len)
	{
		flag->width -= len;
		while (flag->width > 0)
		{
			flag->len += write(1, "0", 1);
			flag->width--;
		}
	}
	flag->width = 0;
}
