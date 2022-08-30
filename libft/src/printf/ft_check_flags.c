/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 04:17:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:16:47 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Parses through the string and updates the corresponding flag's value 
 *	in the struct if they are found
 *
 * Proceeds to check for type after
 */
int	ft_check_flags(t_pf *flag, const char *str, int i)
{
	while (!ft_strchr("cspdiuxX%", str[i]))
	{
		if (str[i] == '-' && ++i)
			flag->left = 1;
		if (str[i] == '0' && ++i)
			flag->zero = 1;
		if (ft_isdigit(str[i]))
			while (ft_isdigit(str[i]))
				flag->width = flag->width * 10 + (str[i++] - '0');
		if (str[i] == '.' && ++i)
		{
			flag->dot = 1;
			while (ft_isdigit(str[i]))
				flag->precision = flag->precision * 10 + (str[i++] - '0');
		}
		if (str[i] == '#' && ++i)
			flag->hash = 1;
		if (str[i] == ' ' && ++i)
			flag->space = 1;
		if (str[i] == '+' && ++i)
			flag->plus = 1;
	}
	return (ft_check_type(flag, str, i));
}

/*
 *	Checks for type after the flags
 */
int	ft_check_type(t_pf *flag, const char *str, int i)
{
	if (str[i] == 'c')
		flag->len += ft_printchar(flag);
	else if (str[i] == 's')
		ft_printstr(flag);
	else if (str[i] == 'p')
		ft_printptr(flag);
	else if (str[i] == 'i' || str[i] == 'd')
		ft_printint(flag);
	else if (str[i] == 'u')
		ft_printuint(flag);
	else if (str[i] == 'x' || str[i] == 'X')
	{
		if (str[i] == 'X')
			flag->upper = 1;
		ft_printhex(flag);
	}
	else if (str[i] == '%')
		flag->len += write(1, "%", 1);
	return (i);
}
