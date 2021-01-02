/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:02:42 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/02 17:45:49 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* printing of hexadecimal numbers */

static void	ft_dispatcher(char *basechar, int x, t_list *box)
{
	if (box->width > 1 && box->precision >= 1 && (size_t)box->precision >= ft_strlen(basechar))
		ft_print_hexa_one(basechar, x, box);
	else if (box->width > 1 && box->precision >= 1 && (size_t)box->precision < ft_strlen(basechar))
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

static void	ft_positive_hexa(int len, int x, char *base, t_list *box)
{
	char    basechar[len + 1];

	basechar[len + 1] = '\0';
	while (len >= 0)
	{
		basechar[len] = (base[(x % 16)]);
		x /= 16;
		len -= 1;
	}
	ft_dispatcher(basechar, x, box);
}

static void	ft_negative_hexa(int len, unsigned int y, char *base, t_list *box)
{
	char    basechar[len + 1];

	basechar[len + 1] = '\0';
	while (len >= 0)
	{
		basechar[len] = (base[(y % 16)]);
		y /= 16;
		len -= 1;
	}
	ft_dispatcher(basechar, y, box);
}

void	ft_xx_craft(int x, int type, t_list *box)
{
	int	len;
	char	*base;
	unsigned int	y;

	len = ft_baselen((unsigned long)x);
	y = (unsigned)x;
	if (type == 0)
		base = "0123456789abcdef";
	else if (type == 1)
		base = "0123456789ABCDEF";
	if (x >= 0)
		ft_positive_hexa(len, x, base, box);
	else if (x < 0)
		ft_negative_hexa(len, y, base, box);
}
