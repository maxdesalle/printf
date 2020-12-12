/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/12 06:49:37 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	main()
{
	ft_printf("%-5c\n", 'a');
	ft_printf("La lettre affichée est: %2c\nEt en voici une autre: %c", 'a', 'b');
	return (0);
}
