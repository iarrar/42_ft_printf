/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:13:49 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:26:56 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;

	res = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res = res + ft_which_sign(&args, str[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (ft_strlen(str) + res - (2 * ft_countchar(str, '%')));
}
