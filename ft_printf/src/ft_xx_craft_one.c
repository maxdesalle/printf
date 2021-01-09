/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:02:42 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 18:40:19 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** printing of hexadecimal numbers
*/

/*
** redirects towards the right functions according to the given possibilities
*/

static void	ft_dispatcher(char *basechar, long x, t_list *box)
{
	if (box->width >= 1 && box->precision >= 1
			&& (size_t)box->precision >= ft_strlen(basechar))
		ft_print_hexa_one(basechar, x, box);
	else if (box->width >= 1 && box->precision >= 1
			&& (size_t)box->precision < ft_strlen(basechar))
		ft_print_hexa_two(basechar, x, box);
	else if (box->width < 1 && box->precision >= 1)
	{
		ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
		ft_putstr(basechar, box);
	}
	else if (box->width >= 1 && box->precision < 1)
		ft_print_hexa_three(basechar, x, box);
	else
		ft_putstr_hexa(basechar, x, box);
}

/*
** converts the number in a base-16 string
*/

static void	ft_hexa_calculator(int len, long x, char *base, t_list *box)
{
	unsigned int	y;
	char			basechar[len + 1];

	y = (unsigned)x;
	basechar[len + 1] = '\0';
	if (x >= 0)
	{
		while (len >= 0)
		{
			basechar[len] = (base[(x % 16)]);
			x /= 16;
			len -= 1;
		}
		ft_dispatcher(basechar, y, box);
	}
	else
	{
		while (len >= 0)
		{
			basechar[len] = (base[(y % 16)]);
			y /= 16;
			len -= 1;
		}
		ft_dispatcher(basechar, y, box);
	}
}

/*
** creates the base according to the given type (x or X), counts the lenght with
** ft_baselen and calls the base-16 converter function
*/

void		ft_xx_craft(long x, int type, t_list *box)
{
	int		len;
	char	*base;

	if (type == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = ft_baselen((unsigned)x);
	ft_hexa_calculator(len, x, base, box);
}
