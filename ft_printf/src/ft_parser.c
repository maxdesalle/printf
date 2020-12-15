/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:24:47 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/15 10:35:16 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_type_check(char c)
{
	return (c == 'c' ||
		c == 's' ||
		c == 'p' ||
		c == 'd' ||
		c == 'i' ||
		c == 'u' ||
		c == 'x' ||
		c == 'X');
}

static void	ft_craft1(va_list argptr, t_list *box)
{
	if (box->type == 'c')
		ft_c_craft(va_arg(argptr, int), box);
	else if (box->type == 's')
		ft_s_craft(va_arg(argptr, char *), box);
	else
		ft_di_craft(va_arg(argptr, int), box);
	return ;
}

/* static void	ft_craft2(va_list argptr, t_list *box)
{
	if (box->type == 'u')
	{
		box->u = va_arg(argptr, unsigned int);
		ft_u_craft(box);
	}
	else if (box->type == 'p')
	{
		box->p = va_arg(argptr, void *);
		ft_p_craft(box);
		faut encore ajouter des paramètres, pour l'addr et l'end
	}
	else
	{
		box->xx = va_arg(argptr, unsigned int);
		ft_xX_craft(box);
	}
}*/

static void	ft_type_selector(va_list argptr, t_list *box)
{
	if (box->type == 'c' || box->type == 's' || box->type == 'd'
			|| box->type == 'i')
		ft_craft1(argptr, box);
/*	else
		ft_craft2(argptr, box);*/
	return ;
}

int			ft_parser(va_list argptr, char *str, t_list *box)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			ft_analysis(&str[++i], box);
			while (ft_type_check(str[i]) == 0)
				i++;
			if (ft_type_check(str[i]) == 1)
				box->type = str[i];
			ft_type_selector(argptr, box);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar(str[++i], box);
		else
			ft_putchar(str[i], box);
		i++;
	}
	return (box->len);
}
