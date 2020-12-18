/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_craft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:34:39 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/18 14:59:42 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_print_int_one(int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
		ft_putnbr(nbr, box);
		ft_super_putchar(box->width - box->precision, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - box->precision, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - box->precision, ' ', box);
	if (ft_intlen(nbr) < box->precision)
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
	ft_putnbr(nbr, box);
	return ;
}

static void	ft_print_int_two(int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
		ft_putnbr(nbr, box);
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - ft_intlen(nbr), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
	if (ft_intlen(nbr) < box->precision)
		ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
	ft_putnbr(nbr, box);
	return ;
}

static void	ft_print_int_three(int nbr, t_list *box)
{
	ft_super_putchar(box->precision - ft_intlen(nbr), '0', box);
	ft_putnbr(nbr, box);
	return ;
}

static void	ft_print_int_four(int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putnbr(nbr, box);
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - ft_intlen(nbr), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_intlen(nbr), ' ', box);
	ft_putnbr(nbr, box);
	return ;
}

void	ft_di_craft(int nbr, t_list *box)
{
	if (box->width > 1 && box->precision >= 1 && box->precision >= ft_intlen(nbr))
		ft_print_int_one(nbr, box);
	else if (box->width > 1 && box->precision >= 1 && box->precision < ft_intlen(nbr))
		ft_print_int_two(nbr, box);
	else if (box->width < 1 && box->precision >= 1)
		ft_print_int_three(nbr, box);
	else if (box->width > 1 && box->precision < 1)
		ft_print_int_four(nbr, box);
	else
		ft_putnbr(nbr, box);
}
