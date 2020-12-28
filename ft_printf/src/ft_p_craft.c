/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:01:30 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/28 07:44:07 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* prints pointers */

static void	ft_print_pointer(char *basechar, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putstr("0x", box);
		ft_putstr(basechar, box);
		ft_super_putchar(box->width - ft_strlen(basechar) - 2, ' ', box);
		return ;
	}
	else if (box->fminus == 0)
	{
		ft_super_putchar(box->width - ft_strlen(basechar) - 2, ' ', box);
		ft_putstr("0x", box);
		ft_putstr(basechar, box);
		return ;
	}
	free(basechar);
}

void	ft_p_craft(unsigned long long x, t_list *box)
{
	int	end;
	char	*base;
	char	*basechar;

	end = ft_baselen(x);
	base = "0123456789abcdef";
	if (box->precision == 0 && box->width > 2 && !x)
		ft_putchar(' ', box);
	if (box->precision == 0 && !x)
		return ;
	if (!(basechar = malloc(sizeof(char) * (end))))
		return ;
	while (end >= 0)
	{
		basechar[end] = (base[(x % 16)]);
		x /= 16;
		end -= 1;
	}
	ft_print_pointer(basechar, box);
}
