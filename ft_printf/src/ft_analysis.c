/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/30 10:24:18 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* catches the flags given in the string as parameter and stores them inside a linked list (box) */

static void	ft_precision(va_list *argptr, char *str, t_list *box)
{
	while (*str != '\0')
	{
		if (*str == '.')
		{
			str++;
			if (*str >= '0' && *str <= '9')
				box->precision = ft_atoi_alpha(str);
			else if (*str == '*')
				box->precision = va_arg(*argptr, int);
			return ;
		}
		str++;
	}
	return ;
}

static void	ft_width(va_list *argptr, char *str, t_list *box)
{
	while (*str != '\0' && *str != '.')
	{
		if (*str >= '1' && *str <= '9')
		{
			box->width = ft_atoi_alpha(str);
			return ;
		}
		else if (*str == '*')
		{
			box->width = va_arg(*argptr, int);
			if (box->width < 0)
			{
				box->width *= -1;
				box->fminus += 1;
			}
			return ;
		}
		str++;
	}
	return ;
}

static void	ft_flag(char *str, t_list *box)
{
	while (*str != '\0' && *str != 'c' && *str != 's' && *str != 'p'
			&& *str != 'd' && *str != 'i' && *str != 'u'
			&& *str != 'x' && *str != 'X' && *str != '%')
	{
		if (*str == '-')
			box->fminus += 1;
		else if (*str == '+')
			box->fplus += 1;
		else if (*str == ' ')
			box->fspace += 1;
		else if (*str == '.')
			box->fdot += 1;
		str++;
	}
	if (box->fminus == 2)
		box->fminus -= 1;
	if (box->precision < 0)
	{
		box->precision = 0;
		box->fdot = 0;
	}
	return ;
}

static void	ft_fzero(char *str, t_list *box)
{
	while (*str != '\0' && (!(*str >= '1' && *str <= '9')))
		if (*str++ == '0')
			box->fzero += 1;
	return ;
}

void		ft_analysis(va_list *argptr, char *str, t_list *box)
{
	box->width = 0;
	box->precision = 0;
	box->fminus = 0;
	box->fplus = 0;
	box->fspace = 0;
	box->fdot = 0;
	box->fzero = 0;
	ft_width(argptr, str, box);
	ft_precision(argptr, str, box);
	ft_flag(str, box);
	ft_fzero(str, box);
}
