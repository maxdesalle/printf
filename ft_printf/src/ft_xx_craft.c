/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:02:42 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/21 11:57:51 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_baselen(unsigned long x)
{
	int y;

	y = 0;
	while ((x /= 16) > 0)
		y += 1;
	return (y);
}

static void	ft_print_hexa_one(char *basechar, int x, t_list *box)
{
}

static void	ft_print_hexa_two(char *basechar, int x, t_list *box)
{
}

static void	ft_dispatcher(int x, int end, char *base, t_list *box)
{
	char	basechar[end];

	basechar[end] = '\0';
	end -= 1;
	while (end >= 0)
	{
		basechar[end] = (base[(x % 16)]);
		x /= 16;
		end -= 1;
	}
	if (box->width < ft_strlen(basechar) || box->precision < ft_strlen(basechar))
		ft_print_hexa_one(basechar, x, box);
	else
		ft_print_hexa_two(basechar, x, box);
}

void	ft_xx_craft(unsigned int x, int type, t_list *box)
{
	int	end;
	char	*base;

	if (type == 0)
		base = "0123456789abcdef";
	else if (type == 1)
		base = "0123456789ABCDEF";
	end = ft_baselen(x) + 1;
	ft_dispatcher(x, end, base, box);
}
