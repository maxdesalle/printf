/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:34:12 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/22 11:17:46 by mdesalle         ###   ########.fr       */
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

char	*ft_positive_hexa(int x, int type, t_list *box)
{
        int     end;
        char    *base;
        char    basechar[end];

        y = 0;
        end = ft_baselen((unsigned)x) + 1;
        basechar[end] = '\0';
        end -= 1;
        if (type == 0)
                base = "0123456789abcdef";
        else if (type == 1)
                base = "0123456789ABCDEF";
        while (end >= 0)
        {
                basechar[end] = (base[(x % 16)]);
                x /= 16;
                end -= 1;
        }
	return (basechar);
}

char	*ft_negative_hexa(int x, int type, t_list *box)
{
        int     end;
        char    *base;
        char    basechar[end];

        end = ft_baselen((unsigned)x) + 1;
        basechar[end] = '\0';
        end -= 1;
        if (type == 0)
                base = "0123456789abcdef";
        else if (type == 1)
                base = "0123456789ABCDEF";
        while (end >= 0)
        {
                basechar[end] = (base[((unsigned)x % 16)]);
                (unsigned)x /= 16;
                end -= 1;
        }
	return (basechar);
}
