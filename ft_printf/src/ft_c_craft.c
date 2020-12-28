/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:20:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/28 07:44:19 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* prints chars */

static void	ft_print_char(char c, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putchar(c, box);
		ft_super_putchar(box->width - 1, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - 1, ' ', box);
	ft_putchar(c, box);
	return ;
}

void	ft_c_craft(char c, t_list *box)
{
	if (box->width > 1)
		ft_print_char(c, box);
	else
		ft_putchar(c, box);
}
