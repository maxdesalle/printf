/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:02:42 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/30 10:06:19 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* printing of hexadecimal numbers */

static void	ft_dispatcher(char *basechar, int x, t_list *box)
{
	if (box->width > 1 && box->precision >= 1 && box->precision >= ft_strlen(basechar))
		ft_print_hexa_one(basechar, x, box);
	else if (box->width > 1 && box->precision >= 1 && box->precision < ft_strlen(basechar))
		ft_print_hexa_two(basechar, x, box);
	else if (box->width < 1 && box->precision >= 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		ft_putstr(basechar, box);
	}
	else if (box->width > 1 && box->precision < 1)
		ft_print_hexa_three(basechar, x, box);
	else
		ft_putstr(basechar, box);
}

static void	ft_positive_hexa(int x, char *base, t_list *box)
{
	int     end;
	char    *basechar;

	end = ft_baselen((unsigned)x);
	if (!(basechar = malloc(sizeof(char) * (end + 1))))
		return ;
	while (end >= 0)
	{
		basechar[end] = (base[(x % 16)]);
		x /= 16;
		end -= 1;
	}
	ft_dispatcher(basechar, x, box);
}

static void	ft_negative_hexa(unsigned int y, char *base, t_list *box)
{
	int     end;
	char    *basechar;

	end = ft_baselen(y);
	if (!(basechar = malloc(sizeof(char) * (end + 1))))
		return ;
	while (end >= 0)
	{
		basechar[end] = (base[(y % 16)]);
		y /= 16;
		end -= 1;
	}
	ft_dispatcher(basechar, y, box);
}

void	ft_xx_craft(int x, int type, t_list *box)
{
	char	*base;
	unsigned int	y;

	y = (unsigned)x;
	if (type == 0)
		base = "0123456789abcdef";
	else if (type == 1)
		base = "0123456789ABCDEF";
	if (x >= 0)
		ft_positive_hexa(x, base, box);
	else if (x < 0)
		ft_negative_hexa(y, base, box);
}
