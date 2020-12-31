/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/31 09:02:39 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = printf("%d\n", 123456789);
	y = ft_printf("%d\n", 123456789);
	printf("%d\n", x);
	printf("%d\n", y);
	return (0);
}
