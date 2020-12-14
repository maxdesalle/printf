/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/14 09:50:24 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	main(void)
{
	ft_printf("%-5c\n", 'a');
	ft_printf("La lettre affichée est: %c\nEt en voici une autre: %c\n", 'a', 'b');
	ft_printf("Ceci est un petit test: %%, et en voici un autre: %c", 'V');
	return (0);
}
