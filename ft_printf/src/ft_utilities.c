/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:10 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/14 13:57:06 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_putchar(char c, t_list *box)
{
	write(1, &c, 1);
	box->len += 1;
}

void	ft_putstr(char *str, t_list *box)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
		box->len += 1;
	}
}

void	ft_putstr_precision(char *str, t_list *box)
{
	while (*str != '\0' && box->precision-- > 0)
	{
		write(1, str++, 1);
		box->len += 1;
	}
}	

void	ft_super_putchar(int len, char c, t_list *box)
{
	while (len-- > 0)
	{
		write(1, &c, 1);
		box->len += 1;
	}
}

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
