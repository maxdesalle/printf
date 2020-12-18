/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/18 10:51:11 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_precision(char *str, t_list *box)
{
	box->precision = 0;
	while (*str != '\0')
	{
		if (*str == '.')
		{
			box->precision = ft_atoi_alpha(++str);
			return ;
		}
		str++;
	}
	return ;
}

static void	ft_width(char *str, t_list *box)
{
	box->width = 0;
	while (*str != '\0' && *str != '.')
	{
		if (*str >= '0' && *str <= '9')
		{
			box->width = ft_atoi_alpha(str);
			return ;
		}
		str++;
	}
	return ;
}

static void	ft_flag(char *str, t_list *box)
{
	box->ftag = 0;
	box->fzero = 0;
	box->fplus = 0;
	box->fminus = 0;
	box->fspace = 0;
	if (ft_strchr(str, '#'))
		box->ftag += 1;
	else if (ft_strchr(str, '0'))
		box->fzero += 1;
	else if (ft_strchr(str, '+'))
		box->fplus += 1;
	else if (ft_strchr(str, '-'))
		box->fminus += 1;
	else if (ft_strchr(str, ' '))
		box->fspace += 1;
	return ;
}

void		ft_analysis(char *str, t_list *box)
{
	ft_precision(str, box);
	ft_width(str, box);
	ft_flag(str, box);
}
