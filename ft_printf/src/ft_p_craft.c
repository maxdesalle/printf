/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:01:30 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/05 10:05:37 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* prints pointers */

static void	ft_print_pointer(unsigned long long x, char *basechar, t_list *box)
{
	if (box->fdot == 1 && box->width < 0 && x == 0)
	{
		ft_putstr("0x0", box);
		return ;
	}
	if (box->fminus == 1)
	{
		ft_putstr_hexa("0x", 1, box);
		ft_putstr(basechar, box);
		ft_super_putchar(box->width - ft_strlen(basechar) - 2, ' ', box);
		return ;
	}
	else if (box->fminus == 0)
	{
		ft_super_putchar(box->width - ft_strlen(basechar) - 2, ' ', box);
		ft_putstr_hexa("0x", 1, box);
		if (!(box->fdot == 1 && x == 0))
			ft_putstr(basechar, box);
		return ;
	}
}

static void	ft_dispatcher(int len, char *base, unsigned long long x, t_list *box)
{
	char	basechar[len + 1];

	basechar[len + 1] = '\0';
	while (len >= 0)
	{
		basechar[len] = (base[(x % 16)]);
		x /= 16;
		len -= 1;
	}
	ft_print_pointer(x, basechar, box);
}

void	ft_p_craft(unsigned long long x, t_list *box)
{
	int	len;
	char	*base;

	if (!x)
		x = 0;
	len = ft_baselen(x);
	base = "0123456789abcdef";
	if (box->fdot == 1 && box->width > 2 && !x)
		ft_putchar(' ', box);
	ft_dispatcher(len, base, x, box);
}
