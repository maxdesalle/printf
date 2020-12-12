/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/12 07:24:05 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_precision(char *str)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			precision = precision * 10 + (str[i++] - '0');
		return (precision);
	}
	return (-1);
}

static int	ft_width(char *str, t_list *box)
{
	while (*str != '\0')
	{

		if (*str >= '0' && *str <= '9')
		{
			box->width = ft_atoi_alpha(str);
			return (0);
		}
		str++;
	}
	return (-1);
}

static void	ft_flag(char *str, t_list *box)
{
	box->ftag = 0;
	box->fzero = 0;
	box->fplus = 0;
	box->fminus = 0;
	box->fspace = 0;
	while (*str != '\0')
	{
		if (*str == '#')
			box->ftag += 1;
		else if (*str == '0')
			box->fzero += 1;
		else if (*str == '+')
			box->fplus += 1;
		else if (*str == '-')
			box->fminus += 1;
		else if (*str == ' ')
			box->fspace += 1;
		str++;
	}
	return ;
}

void		ft_analysis(char *str, t_list *box)
{
	box->precision = ft_precision(str);
	ft_width(str, box);
	ft_flag(str, box);
}
