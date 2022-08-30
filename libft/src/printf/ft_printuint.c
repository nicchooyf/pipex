/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:16:36 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:22:00 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Get print length to pass into flag functions
 *
 *	Doesn't consider negative cases
 */
static int	get_length(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

/*
 *	Function to print 'u' type
 */
void	ft_printuint(t_pf *flag)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(flag->arg, unsigned int);
	len = get_length(nb);
	len = check_precision_uint(flag, len, nb);
	check_left(flag, len);
	check_zero(flag, len);
	if (nb)
		ft_putnbr(flag, (size_t)nb);
	else if (!flag->dot || flag->precision > 0)
		flag->len += write(1, "0", 1);
	check_right(flag, len);
}
