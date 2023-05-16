/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_craft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:34:39 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/11 14:07:27 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** prints ints
*/

/*
** prints a decimal number in base-10 according
** to a set of given possibilities
*/

static void	ft_print_int_one(int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-', box);
			nbr *= -1;
			box->width -= 1;
		}
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
		ft_putnbr(nbr, nbr, box);
		ft_super_putchar(box->width - box->precision, ' ', box);
		return ;
	}
	else if (box->fzero == 1 && box->fdot == 0)
		ft_super_putchar(box->width - box->precision, '0', box);
	else if (box->fminus == 0 && nbr >= 0)
		ft_super_putchar(box->width - box->precision, ' ', box);
	if (box->fminus == 0 && nbr < 0)
	{
		ft_super_putchar(box->width - box->precision - 1, ' ', box);
		ft_putchar('-', box);
		nbr *= -1;
	}
	ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
	ft_putnbr(nbr, nbr, box);
}

/*
** prints a decimal number in base-10 according
** to a set of given possibilities
*/

static void	ft_print_int_two(int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
		ft_putnbr(nbr, nbr, box);
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
		return ;
	}
	else if (box->fzero == 1 && box->fdot == 0)
		ft_super_putchar(box->width - ft_intlen(nbr), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
	ft_putnbr(nbr, nbr, box);
	return ;
}

/*
** prints a decimal number in base-10 according
** to a set of given possibilities
*/

static void	ft_print_int_three(int nbr, t_list *box)
{
	if (!(box->fzero == 1 && box->precision == 0
				&& box->fdot == 1 && nbr == 0))
		ft_putnbr(nbr, nbr, box);
	if (box->fdot == 1 && nbr == 0)
		ft_super_putchar(box->width, ' ', box);
	else
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
	return ;
}

/*
** prints a decimal number in base-10 according
** to a set of given possibilities
*/

static void	ft_print_int_four(int nbr, t_list *box)
{
	if (box->fzero == 1)
	{
		if (box->precision == 0 && box->fdot == 1)
			ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
		else
		{
			if (nbr < 0 && nbr > -2147483648)
			{
				ft_putchar('-', box);
				nbr *= -1;
				box->width -= 1;
			}
			ft_super_putchar(box->width - ft_intlen(nbr), '0', box);
		}
	}
	else if (box->fminus == 0 && box->fdot == 1 && nbr == 0)
		ft_super_putchar(box->width, ' ', box);
	else
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
	ft_putnbr(nbr, nbr, box);
	return ;
}

/*
** if the fspace flag is equal to one, ' ' is printed. everything else simply
** redirects to the right functions according to a set of given possibilities
*/

void		ft_di_craft(int nbr, t_list *box)
{
	if (box->width >= 1 && box->precision >= 1
			&& (size_t)box->precision >= ft_intlen(nbr))
		ft_print_int_one(nbr, box);
	else if (box->width >= 1 && box->precision >= 1
			&& (size_t)box->precision < ft_intlen(nbr))
		ft_print_int_two(nbr, box);
	else if (box->width < 1 && box->precision >= 1)
	{
		if (nbr < 0 && nbr > -2147483648)
		{
			ft_putchar('-', box);
			nbr *= -1;
		}
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
		ft_putnbr(nbr, nbr, box);
	}
	else if (box->width >= 1 && box->precision < 1 && box->fminus == 1)
		ft_print_int_three(nbr, box);
	else if (box->width >= 1 && box->precision < 1 && box->fminus == 0)
		ft_print_int_four(nbr, box);
	else
		ft_putnbr(nbr, nbr, box);
}
