/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 14:45:31 by mdesalle         ###   ########.fr       */
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
	printf("%%%dbada%s%%**%s**\n", h, "bada", r);
	return (0);
}
