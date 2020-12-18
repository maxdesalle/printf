/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:04:09 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/18 10:42:46 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

size_t	ft_intlen(long x)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = x;
	if (x == 0)
		return (++len);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (x < 0)
		len++;
	return (len);
}

void	ft_putnbr(int n, t_list *box)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-', box);
		x *= -1;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10, box);
		ft_putnbr(x % 10, box);
	}
	else
		ft_putchar(x + '0', box);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_uintlen(unsigned int nbr)
{
	int	len;

	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char*)s);
	}
	while (*s)
		if (*s++ == c)
			return ((char*)--s);
	return (NULL);
}
