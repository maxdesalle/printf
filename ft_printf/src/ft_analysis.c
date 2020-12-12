/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/12 06:45:55 by mdesalle         ###   ########.fr       */
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
	if (*str >= '0' && *str <= '9')
	{
		box->width = ft_atoi(str);
		return (0);
	}
	return (-1);
}

static void	ft_flag(char *str, t_list *box)
{
	int	i;

	i = 0;
	box->ftag = 0;
	box->fzero = 0;
	box->fplus = 0;
	box->fminus = 0;
	box->fspace = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			box->ftag += 1;
		else if (str[i] == '0')
			box->fzero += 1;
		else if (str[i] == '+')
			box->fplus += 1;
		else if (str[i] == '-')
			box->fminus += 1;
		else if (str[i] == ' ')
			box->fspace += 1;
		i++;
	}
	return ;
}

void		ft_analysis(char *str, t_list *box)
{
	box->precision = ft_precision(str);
	ft_width(str, box);
	ft_flag(str, box);
}
