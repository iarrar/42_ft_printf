/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:43 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:26:17 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		s;

	s = n;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbr_fd(n, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	return (size_base(s, 10));
}
