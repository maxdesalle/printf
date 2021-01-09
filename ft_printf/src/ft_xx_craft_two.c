/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:53:01 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 15:21:06 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** printing of hexadecimal numbers
*/

void	ft_print_hexa_one(char *basechar, long x, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		if (box->precision == 0 && box->fdot == 1 && x == 0)
			ft_putstr(" ", box);
		else
			ft_putstr(basechar, box);
		ft_super_putchar(box->width - box->precision, ' ', box);
		return ;
	}
	else if (box->fzero == 1 && box->fdot == 0)
		ft_super_putchar(box->width - box->precision, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - box->precision, ' ', box);
	ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
	if (box->precision == 0 && box->fdot == 1 && x == 0)
		ft_putstr(" ", box);
	else
		ft_putstr(basechar, box);
	return ;
}

void	ft_print_hexa_two(char *basechar, long x, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		if (box->precision == 0 && box->fdot == 1 && x == 0)
			ft_putstr(" ", box);
		else
			ft_putstr(basechar, box);
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
		return ;
	}
	else if (box->fzero == 1 && box->fdot == 0)
		ft_super_putchar(box->width - ft_strlen(basechar), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
	if (box->precision == 0 && box->fdot == 1 && x == 0)
		ft_putstr(" ", box);
	else
		ft_putstr(basechar, box);
	return ;
}

void	ft_print_hexa_three(char *basechar, long x, t_list *box)
{
	if (box->fminus == 1)
	{
		if (box->precision == 0 && box->fdot == 1 && x == 0)
			ft_putstr(" ", box);
		else
			ft_putstr(basechar, box);
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
		return ;
	}
	else if (box->fzero == 1)
	{
		if (box->precision == 0 && box->fdot == 1)
			ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
		else
			ft_super_putchar(box->width - ft_strlen(basechar), '0', box);
	}
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
	if (box->precision == 0 && box->fdot == 1 && x == 0)
		ft_putstr(" ", box);
	else
		ft_putstr(basechar, box);
	return ;
}
