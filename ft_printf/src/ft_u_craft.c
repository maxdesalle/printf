/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:43:43 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/31 10:41:10 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* prints unsigned ints */

static void	ft_print_uint_one(unsigned int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_uintlen(nbr), '0', box);
		ft_putnbr_unsigned(nbr, box);
		ft_super_putchar(box->width - box->precision, ' ', box);
		return ;
	}
	else if (box->fzero == 1 && box->fdot == 0)
		ft_super_putchar(box->width - box->precision, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - box->precision, ' ', box);
	ft_super_putchar(box->precision - ft_uintlen(nbr), '0', box);
	ft_putnbr_unsigned(nbr, box);
	return ;
}

static void	ft_print_uint_two(unsigned int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_uintlen(nbr), '0', box);
		ft_putnbr_unsigned(nbr, box);
		ft_super_putchar(box->width - ft_uintlen(nbr), ' ', box);
		return ;
	}
	else if (box->fzero == 1 && box->fdot == 0)
		ft_super_putchar(box->width - ft_uintlen(nbr), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_uintlen(nbr), ' ', box);
	ft_putnbr_unsigned(nbr, box);
	return ;
}

static void	ft_print_uint_three(unsigned int nbr, t_list *box)
{
	ft_super_putchar(box->precision - ft_uintlen(nbr), '0', box);
	ft_putnbr_unsigned(nbr, box);
	return ;
}

static void	ft_print_uint_four(unsigned int nbr, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putnbr_unsigned(nbr, box);
		if (box->fdot == 0)
			ft_super_putchar(box->width - ft_uintlen(nbr), ' ', box);
		else if (box->fdot == 1)
			ft_super_putchar(box->width, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - ft_uintlen(nbr), '0', box);
	else if (box->fminus == 0 && box->fdot == 0)
		ft_super_putchar(box->width - ft_uintlen(nbr), ' ', box);
	else if (box->fminus == 0 && box->fdot == 1)
		ft_super_putchar(box->width, ' ', box);
	ft_putnbr_unsigned(nbr, box);
	return ;
}

void	ft_u_craft(unsigned int nbr, t_list *box)
{
	if (box->width > 1 && box->precision >= 1 && (size_t)box->precision >= ft_uintlen(nbr))
		ft_print_uint_one(nbr, box);
	else if (box->width > 1 && box->precision >= 1 && (size_t)box->precision < ft_uintlen(nbr))
		ft_print_uint_two(nbr, box);
	else if (box->width < 1 && box->precision >= 1)
		ft_print_uint_three(nbr, box);
	else if (box->width > 1 && box->precision < 1)
		ft_print_uint_four(nbr, box);
	else
		ft_putnbr_unsigned(nbr, box);
}
