/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 08:11:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/14 14:03:35 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_print_string_one(char *str, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putstr(str, box);
		ft_super_putchar(box->width - 1, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - 1, ' ', box);
	ft_putstr(str, box);
	return ;
}

static void	ft_print_string_two(char *str, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putstr_precision(str, box);
		ft_super_putchar(box->width - 1, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - 1, ' ', box);
	ft_putstr_precision(str, box);
	return ;
}

static void	ft_print_string_three(char *str, t_list *box)
{
	if (box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	ft_putstr_precision(str, box);
	return ;
}

void	ft_s_craft(char *str, t_list *box)
{
	if (box->width > 1 && box->precision < 1)
		ft_print_string_one(str, box);
	else if (box->width > 1 && box->precision >= 1)
		ft_print_string_two(str, box);
	else if (box->width < 1 && box->precision >= 1)
		ft_print_string_three(str, box);
	else
		ft_putstr(str, box);
}
