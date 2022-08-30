/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:29:55 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:22:16 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Non-recursive function for putnbr
 */
void	ft_putnbr(t_pf *flag, size_t nb)
{
	size_t	tmp;
	size_t	div;

	div = 1;
	tmp = nb;
	while (tmp)
	{
		tmp /= 10;
		div *= 10;
	}
	while (div != 1)
	{
		div /= 10;
		tmp = nb / div + '0';
		flag->len += write(1, &tmp, 1);
		nb %= div;
	}
}

/*
 *	Recursive function for putnbr with given base
 */
void	ft_putnbr_base(t_ull point, t_pf *flag, char *base)
{
	if (point >= 16)
	{
		ft_putnbr_base(point / 16, flag, base);
		ft_putnbr_base(point % 16, flag, base);
	}
	else if (point < 16)
	{
		if (point < 10)
		{
			point += '0';
			write(1, &point, 1);
		}
		else
			write(1, &base[point - 10], 1);
		flag->len++;
	}
}
