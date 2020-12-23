/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:34:12 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/23 08:52:38 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_putnbr_unsigned(unsigned int nbr, t_list *box)
{
	unsigned long	x;

	x = nbr;
	if (x == 0 && box->precision == 0)
		return ;
	if (x < 0)
		x *= -1;
	if (x > 9)
	{
		ft_putnbr(x / 10, box);
		ft_putnbr(x % 10, box);
	}
	else
		ft_putchar(x + '0', box);
}

int      ft_baselen(unsigned long x)
{
        int y;

        y = 0;
        while ((x /= 16) > 0)
                y += 1;
        return (y);
}
