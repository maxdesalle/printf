/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/07 15:21:45 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include <stdio.h>

int	main(void)
{
	int		h = 4200;
	int		i = 8;
	char	*p = "-12";
	char	*r = "%%";

	ft_printf("%%%dbada%s%%**%s**\n", h, "bada", r);
/*	printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i);*/
	return (0);
}
