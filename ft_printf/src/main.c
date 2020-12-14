/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/14 14:04:28 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include <stdio.h>

void	ft_c_test(void)
{
	ft_printf("%s", "char\n");
	ft_printf("%s", "------------------------------------------------------------------------------------------\n");
	ft_printf("%-5c\n", 'a');
	ft_printf("%5c\n", 'a');
	ft_printf("La lettre affichée est: %c\nEt en voici une autre: %c\n", 'a', 'b');
	ft_printf("Ceci est un petit test: %%, et en voici un autre: %c\n", 'A');
	ft_printf("\n");
}

int	main(void)
{
	ft_c_test();

	ft_printf("%s", "string\n");
	ft_printf("%s", "------------------------------------------------------------------------------------------\n");
	ft_printf("Ceci est un test: %s\n", "et ceci en est un autre");
	ft_printf("Maintenant, nous allons introduire la largeur du côté gauche: %5s\n", "width");
	ft_printf("Puis nous allons introduire la largeur du côté droit: %-5s\n", "width");
	ft_printf("Et maintenant la %.6s\n", "précision");
	return (0);
}
