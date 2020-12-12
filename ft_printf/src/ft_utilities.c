/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:10 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/12 06:47:46 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_putchar(char c, t_list *box)
{
	write(1, &c, 1);
	box->len += 1;
	return ;
}

void	ft_super_putchar(int len, char c, t_list *box)
{
	while (len-- > 0)
	{
		write(1, &c, 1);
		box->len += 1;
	}
	return ;
}

long	ft_atoi(const char *nptr)
{
	int	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	result *= sign;
	if (result > 0 && sign < 0)
		return (0);
	if (result < 0 && sign > 0)
		return (-1);
	return (result);
}
