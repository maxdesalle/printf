/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 19:05:59 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** some basic functions to print and a modified atoi
*/

/*
** writes one character, and counts through the 'len' linked list flag
*/

void	ft_putchar(char c, t_list *box)
{
	write(1, &c, 1);
	box->len += 1;
}

/*
** writes a string, and counts throught the 'len' linked list flag
*/

void	ft_putstr(char *str, t_list *box)
{
	if (box->precision == 0 && box->width == 0 && box->fdot == 1)
		return ;
	while (*str != '\0')
	{
		write(1, str++, 1);
		box->len += 1;
	}
}

/*
** writes a string as long as the given precision, and counts through the
** 'len' linked list flag
*/

void	ft_putstr_precision(char *str, t_list *box)
{
	int	i;

	i = box->precision;
	while (*str != '\0' && i-- > 0)
	{
		write(1, str++, 1);
		box->len += 1;
	}
}

/*
** writes as long as the given 'len' (int), and counts through
** the 'len' linked list flag
*/

void	ft_super_putchar(int len, char c, t_list *box)
{
	while (len-- > 0)
	{
		write(1, &c, 1);
		box->len += 1;
	}
}

/*
** modified atoi function which skips '-', '+' and ' '
*/

long	ft_atoi_alpha(const char *nptr)
{
	long	result;

	result = 0;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	return (result);
}
