/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:43:43 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/17 11:51:21 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_print_uint_one(unsigned int nbr, t_list *box)
{
}

static void	ft_print_uint_two(unsigned int nbr, t_list *box)
{
}

void	ft_u_craft(unsigned int nbr, t_list *box)
{
	int	len;

	if (nbr >= 0)
		len = ft_intlen(nbr);
	else if (nbr < 0)
		len = ft_uintlen((unsigned)nbr);
	if (box->width < len || box->precision < len)
		ft_print_uint_one(nbr, box);
	else
		ft_print_uint_two(nbr, box);
}
