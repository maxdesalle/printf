/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:34:12 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/11 11:09:27 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** some additional utilities specific to certain use-cases
*/

/*
** a ft_strlen for base numbers and putnbr for unsigned numbers
*/

void	ft_putnbr_unsigned(unsigned int nbr, unsigned int m, t_list *box)
{
	unsigned long	x;

	x = nbr;
	if (box->fdot == 1 && m == 0 && box->precision == 0 && box->fzero == 1)
	{
		if (box->width >= 1)
			ft_putchar(' ', box);
		return ;
	}
	if (box->fdot == 1 && m == 0 && box->precision == 0 && box->fzero == 0)
		return ;
	if (x > 9)
	{
		ft_putnbr_unsigned(x / 10, m, box);
		ft_putnbr_unsigned(x % 10, m, box);
	}
	else
		ft_putchar(x + '0', box);
}

/*
** a ft_strlen for soon-to-be-converted-into-base-16-numbers numbers
*/

int		ft_baselen(unsigned long x)
{
	int y;

	y = 0;
	while ((x /= 16) > 0)
		y++;
	return (y);
}

/*
** a putstr function specifically made for base-16 strings. the difference is
** the addition of the long x argument, which allows an error check before
** printing the string
*/

void	ft_putstr_hexa(char *str, unsigned long long x, t_list *box)
{
	if (box->fdot == 1 && box->precision == 0 && x == 0)
		return ;
	while (*str != '\0')
	{
		write(1, str++, 1);
		box->len += 1;
	}
}
