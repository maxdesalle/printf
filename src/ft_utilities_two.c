/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:04:09 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/10 17:54:27 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** ft_strlen and its alternatives for ints and unsigned ints, as well as
** ft_putnbr and ft_strchr
*/

/*
** counts the length of ints
*/

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

/*
**  prints numbers. doesn't count them as this is done on the ft_putchar side
*/

void	ft_putnbr(int n, int m, t_list *box)
{
	long	x;

	x = n;
	if (box->fdot == 1 && m == 0 && box->precision == 0 && box->fzero == 1)
	{
		if (box->width >= 1)
			ft_putchar(' ', box);
		return ;
	}
	if (box->fdot == 1 && m == 0 && box->precision == 0 && box->fzero == 0)
		return ;
	if (x < 0)
	{
		ft_putchar('-', box);
		x *= -1;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10, m, box);
		ft_putnbr(x % 10, m, box);
	}
	else
		ft_putchar(x + '0', box);
}

/*
**  counts the length of the given string
*/

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
** counts the length of unsigned ints
*/

size_t	ft_uintlen(unsigned int nbr)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = nbr;
	if (tmp == 0)
		return (++len);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

/*
** returns a pointer if the given character is found in the string
*/

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
