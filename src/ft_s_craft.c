/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 08:11:17 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 19:06:59 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** print strings
*/

/*
** prints the string according to a set of given possibilities
*/

static void	ft_print_string_one(char *str, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putstr(str, box);
		ft_super_putchar(box->width - ft_strlen(str), ' ', box);
		return ;
	}
	else if (box->fminus == 0)
		ft_super_putchar(box->width - ft_strlen(str), ' ', box);
	ft_putstr(str, box);
	return ;
}

/*
** prints the string according to a set of given possibilities
*/

static void	ft_print_string_two(char *str, t_list *box)
{
	if (box->width > box->precision
			&& (size_t)box->precision <= ft_strlen(str))
	{
		ft_super_putchar(box->width - box->precision, ' ', box);
		ft_putstr_precision(str, box);
	}
	else if (box->width <= box->precision
			&& (size_t)box->precision <= ft_strlen(str))
		ft_putstr_precision(str, box);
	else if ((size_t)box->precision > ft_strlen(str))
	{
		ft_super_putchar(box->width - ft_strlen(str), ' ', box);
		ft_putstr(str, box);
	}
	return ;
}

/*
** prints the string according to a set of given possibilities
*/

static void	ft_print_string_three(char *str, t_list *box)
{
	if (box->width > box->precision
			&& (size_t)box->precision <= ft_strlen(str))
	{
		ft_putstr_precision(str, box);
		ft_super_putchar(box->width - box->precision, ' ', box);
	}
	else if (box->width < box->precision
			&& (size_t)box->precision <= ft_strlen(str))
		ft_putstr_precision(str, box);
	else if ((size_t)box->precision > ft_strlen(str))
	{
		ft_putstr(str, box);
		ft_super_putchar(box->width - ft_strlen(str), ' ', box);
	}
	else
		ft_putstr_precision(str, box);
	return ;
}

/*
** if the string is null, following the workings of the printf function,
** the string becomes "(null)" and the function moves on. it redirects
** to the right functions according to a set of given possibilities.
** if none of these possibilities is met, it simply prints it with ft_putstr.
*/

void		ft_s_craft(char *str, t_list *box)
{
	if (!str)
		str = "(null)";
	if (box->width >= 1 && box->precision < 1 && box->fdot == 0)
		ft_print_string_one(str, box);
	else if (box->width >= 1 && box->precision < 1 && box->fdot == 1)
		ft_super_putchar(box->width, ' ', box);
	else if (box->width >= 1 && box->precision >= 1 && box->fminus == 0)
		ft_print_string_two(str, box);
	else if (box->width >= 1 && box->precision >= 1 && box->fminus == 1)
		ft_print_string_three(str, box);
	else if (box->width < 1 && box->precision >= 1)
		ft_putstr_precision(str, box);
	else
		ft_putstr(str, box);
}
