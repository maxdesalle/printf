/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:02:42 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/22 10:54:06 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_print_hexa_one(char *basechar, int x, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		ft_putstr(basechar, box);
		ft_super_putchar(box->width - box->precision, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - box->precision, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - box->precision, ' ', box);
	ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
	ft_putstr(basechar, box);
	return ;
}

static void	ft_print_hexa_two(char *basechar, int x, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		ft_putstr(basechar, box);
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - ft_strlen(basechar), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
	ft_putstr(basechar, box);
	return ;
}

static void	ft_print_hexa_three(char *basechar, int x, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putstr(basechar, box);
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - ft_strlen(basechar), '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
	ft_putstr(basechar, box);
	return ;
}

void	ft_xx_craft(int x, int type, t_list *box)
{
	char	*basechar;

	if (x >= 0)
		basechar = ft_positive_hexa(x, type, box);
	else if (x < 0)
		basechar = ft_negative_hexa(x, type, box);
	if (box->width > 1 && box->precision >= 1 && box->precision >= ft_strlen(basechar))
		ft_print_hexa_one(basechar, x, box);
	else if (box->width > 1 && box->precision >= 1 && box->precision < ft_strlen(basechar))
		ft_print_hexa_two(basechar, x, box);
	else if (box->width < 1 && box->precision >= 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		ft_putstr(basechar, box);
	}
	else if (box->width > 1 && box->precision < 1)
		ft_print_hexa_three(basechar, x, box);
	else
		ft_putstr(basechar, box);
}
