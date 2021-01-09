/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 14:52:39 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* catches the flags given in the string as parameter and stores them inside a linked list (box) */


/* 
** As long as we aren't at the end of the string, if a dot (".") is found,
** we convert the following character(s) in an int which is stored inside
** the precision int inside the box linked list. If a star ("*") is found,
** we store instead the argument given in the precision int.
*/

static void	ft_precision(va_list *argptr, char *str, t_list *box)
{
	while (*str != '\0' && *str != '%')
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


/*
** As long as the string hasn't reached its end, or a dot (".") (signaling
** the precicision), starting from the character after the "%", we
** convert the character(s) into an int, assuming it's made of a digits.
** If it isn't, we look if it's a star ("*"), which would mean that we would
** use the argument as the width. If the width is negative, we make it positive
** and increase the fminus counter so we know that it will need to be handled
** as a negative width by the system.
*/

static void	ft_width(va_list *argptr, char *str, t_list *box)
{
	while (*str != '\0' && *str != '.' && *str != '%' &&
			ft_strchr("cspdiuxXnfge%", *str) == NULL)
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


/*
** As long as the string hasn't reached its end, and one of the types
** hasn't been found, every time a flag is found its counter increases.
** If fminus is equal to 2 as a negative width was given as an argument
** instead of being in the parameter string like usually, we make it equal
** to 1 so its behaviour remains normal. If precision is below 0, we make it
** equal to 0 and remove the dot if one was found so the behaviour of our system
** follows the behaviour of the printf function.
*/

static void	ft_flag(char *str, t_list *box)
{
	while (*str != '\0' && ft_strchr("cspdiuxXnfge%", *str) == NULL)
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
	if (box->fminus > 1)
		box->fminus = 1;
	if (box->precision < 0)
	{
		box->precision = 0;
		box->fdot = 0;
	}
	return ;
}


/*
** As long as the string hasn't reached its end, nor the width, if a 0
** is found, the counter increases.
*/

static void	ft_fzero(char *str, t_list *box)
{
	while (*str != '\0' && *str != '*' && *str != '%'
			&& *str != '.' && (!(*str >= '1' && *str <= '9'))
			&& ft_strchr("cspdiuxXnfge%", *str) == NULL)
		if (*str++ == '0')
			box->fzero += 1;
	return ;
}


/*
** Initializes all the flags and calls the functions.
*/

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
