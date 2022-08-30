/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:04:13 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:16:42 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Simple write function to print 'c' type
 */
int	ft_printchar(t_pf *flag)
{
	int	c;

	c = va_arg(flag->arg, int);
	check_left(flag, 1);
	write(1, &c, 1);
	check_right(flag, 1);
	return (1);
}
