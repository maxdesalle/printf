/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_craft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:23:55 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 15:28:14 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** prints %
*/

void	ft_percent_craft(t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putchar('%', box);
		ft_super_putchar(box->width - 1, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - 1, ' ', box);
	ft_putchar('%', box);
	return ;
}
