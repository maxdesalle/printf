/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 08:11:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/14 11:23:32 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_print_string_one(char *str, t_list *box)
{
	if (box->fminus == 1)
	{
		ft_putstr(str, box);
		ft_super_putchar(box->width - 1, ' ', box);
		return ;
	}
	else if (box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	else if (box->fminus == 0)
		ft_super_putchar(box->width - 1, ' ', box);
	ft_putstr(str, box);
	return ;
}

void	ft_s_craft(char *str, t_list *box)
{
	if (box->width > 1)
		ft_print_string_one(str, box);
	else
		ft_putstr(str, box);
}
