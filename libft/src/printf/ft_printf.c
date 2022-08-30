/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/07 06:56:02 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_pf	*ft_struct_init(t_pf *flag);

/*
 *	Flag	-	Passes information from function to function using a structure
 *	Res		-	Result, number of characters printed
 *
 *	When '%' modifier is encountered, runs the subsequent character through
 *	ft_check_flags to determine the flags and type.
 *
 *  ******BONUS******
 * 
 *	Print functions run through the same sequence generally:
 *
 *	-	gets print length
 *	-	handles precision
 *		-	adjusts print length, 'width', 'zero' and 'pad' flags as necessary
 *	-	handles left side
 *	-	handles 'zero' flag
 *	-	handles right side
 */
int	ft_printf(const char *str, ...)
{
	t_pf	*flag;
	int		i;
	int		res;

	flag = malloc(sizeof(t_pf));
	if (!flag)
		return (-1);
	ft_struct_init(flag);
	va_start(flag->arg, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			i = ft_check_flags(flag, str, i + 1);
		else
			flag->len += write(1, &str[i], 1);
		flag->left = 0;
	}
	res = flag->len;
	va_end(flag->arg);
	free(flag);
	return (res);
}

/*
 *	Initialise struct members to '0'
 */
static t_pf	*ft_struct_init(t_pf *flag)
{
	flag->upper = 0;
	flag->width = 0;
	flag->pad = 0;
	flag->left = 0;
	flag->precision = 0;
	flag->dot = 0;
	flag->hash = 0;
	flag->len = 0;
	flag->hexlen = 0;
	flag->star = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->plus = 0;
	return (flag);
}
