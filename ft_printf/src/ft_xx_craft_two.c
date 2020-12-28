/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_craft_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:53:01 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/28 07:49:28 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/* printing of hexadecimal numbers */

void     ft_print_hexa_one(char *basechar, int x, t_list *box)
{
        if (box->fminus == 1)
        {
                ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
                ft_putstr(basechar, box);
                ft_super_putchar(box->width - box->precision, ' ', box);
                return ;
        }
        else if (box->fzero == 1)
                ft_super_putchar(box->width - box->precision, '0', box);
        else if (box->fminus == 0)
                ft_super_putchar(box->width - box->precision, ' ', box);
        ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
        ft_putstr(basechar, box);
	free(basechar);
        return ;
}

void     ft_print_hexa_two(char *basechar, int x, t_list *box)
{
        if (box->fminus == 1)
        {
                ft_super_putchar(box->precision - ft_strlen(basechar), '0', box);
                ft_putstr(basechar, box);
                ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
                return ;
        }
        else if (box->fzero == 1)
                ft_super_putchar(box->width - ft_strlen(basechar), '0', box);
        else if (box->fminus == 0)
                ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
        ft_putstr(basechar, box);
	free(basechar);
        return ;
}

void     ft_print_hexa_three(char *basechar, int x, t_list *box)
{
        if (box->fminus == 1)
        {
                ft_putstr(basechar, box);
                ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
                return ;
        }
        else if (box->fzero == 1)
                ft_super_putchar(box->width - ft_strlen(basechar), '0', box);
        else if (box->fminus == 0)
                ft_super_putchar(box->width - ft_strlen(basechar), ' ', box);
        ft_putstr(basechar, box);
	free(basechar);
        return ;
}
