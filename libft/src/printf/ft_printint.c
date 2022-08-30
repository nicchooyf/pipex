/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:01:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:16:55 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Handles " +" flags
 */
static void	check_space(t_pf *flag, int neg)
{
	if (flag->space)
	{
		if (!neg)
			flag->len += write(1, " ", 1);
		flag->space = 0;
	}
}

static void	check_neg(t_pf *flag, int neg)
{
	if (neg)
		flag->len += write(1, "-", 1);
	if (flag->plus)
	{
		if (!neg)
			flag->len += write(1, "+", 1);
	}
}

/*
 *	Get print length to pass into flag functions
 */
static int	get_length(long long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

/*
 *	Function to print 'i' and 'd' types
 */
void	ft_printint(t_pf *flag)
{
	long long int	nb;
	int				len;
	int				neg;

	neg = 0;
	nb = va_arg(flag->arg, int);
	if (nb < 0 && ++neg)
	{
		nb = -nb;
		flag->width -= 1;
	}
	len = get_length(nb);
	len = check_precision_int(flag, len, nb);
	check_space(flag, neg);
	check_left(flag, len);
	check_neg(flag, neg);
	check_zero(flag, len);
	if (nb)
		ft_putnbr(flag, (size_t) nb);
	else if (!flag->dot || flag->precision > 0)
		flag->len += write(1, "0", 1);
	check_right(flag, len);
}
