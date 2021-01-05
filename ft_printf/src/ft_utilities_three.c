/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:34:12 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/05 16:53:21 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* a ft_strlen for base numbers and putnbr for unsigned numbers */

void	ft_putnbr_unsigned(unsigned int nbr, t_list *box)
{
	unsigned long	x;

	x = nbr;
	if (x == 0 && box->fdot == 1 && box->precision == 0) 
		return ;
	if (x > 9)
	{
		ft_putnbr(x / 10, box);
		ft_putnbr(x % 10, box);
	}
	else
		ft_putchar(x + '0', box);
}

int	ft_baselen(unsigned long x)
{
	int y;

	y = 0;
	while ((x /= 16) > 0)
		y++;
	return (y);
}

void    ft_putstr_hexa(char *str, long x, t_list *box)
{
	if (box->width == 0 && box->fdot == 1 && box->precision == 0 && x == 0)
		return ;
        while (*str != '\0')
        {
                write(1, str++, 1);
                box->len += 1;
        }
}
