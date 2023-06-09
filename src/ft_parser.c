/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:24:47 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/11 14:17:00 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** parses the string given as parameter and redirects to the right type
*/

/*
** redirects to the right functions
*/

static void	ft_craft1(va_list *argptr, t_list *box)
{
	int	nbr;

	nbr = 0;
	if (box->type == 'c')
		ft_c_craft(va_arg(*argptr, int), box);
	else if (box->type == 's')
		ft_s_craft(va_arg(*argptr, char*), box);
	else if (box->type == 'd' || box->type == 'i')
	{
		nbr = va_arg(*argptr, int);
		if (box->fspace == 1 && nbr >= 0)
		{
			box->width -= 1;
			ft_putchar(' ', box);
		}
		ft_di_craft(nbr, box);
	}
}

/*
** redirects to the right functions
*/

static void	ft_craft2(va_list *argptr, t_list *box)
{
	if (box->type == 'u')
		ft_u_craft(va_arg(*argptr, unsigned int), box);
	else if (box->type == 'x')
		ft_xx_craft(va_arg(*argptr, long), 0, box);
	else if (box->type == 'X')
		ft_xx_craft(va_arg(*argptr, long), 1, box);
	else if (box->type == 'p')
		ft_p_craft(va_arg(*argptr, unsigned long long), box);
	else if (box->type == '%')
		ft_percent_craft(box);
}

/*
** redirects to the right redirectors
*/

static void	ft_type_selector(va_list *argptr, t_list *box)
{
	if (box->type == 'c' || box->type == 's' || box->type == 'd'
			|| box->type == 'i')
		ft_craft1(argptr, box);
	else
		ft_craft2(argptr, box);
}

/*
** finds the type whether it's valid or not
*/

static int	ft_type_finder(int i, char *str, t_list *box)
{
	while (ft_strchr("cspdiuxXnfge%", str[i]) == NULL)
		i++;
	if (ft_strchr("cspdiuxX%", str[i]))
	{
		box->type = str[i];
		return (i);
	}
	else if (ft_strchr("nfge", str[i]))
		return (i);
	else
		return (0);
}

/*
** parses the whole format string in order to find the '%' instructions.
** if "**" is found, it prints it directly and moves on. this was added
** due to a bug which was pretty annoying. it's not really elegant as solution,
** but it works.
** if a % is found, it's analyzed through ft_analysis, then,
** the type is found through ft_type_founder. if a type isn't found,
** the function simply returns to stop. otherwise, the redirector of redirectors
** function ft_type_selector is called. everything else is pretty straight-
** forward.
*/

void		ft_parser(va_list *argptr, char *str, t_list *box)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '*' && str[i + 1] == '*')
		{
			ft_putstr("**", box);
			i += 1;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
		{
			ft_analysis(argptr, &str[++i], box);
			if ((i = ft_type_finder(i, str, box)) > 0)
				ft_type_selector(argptr, box);
			else
				return ;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar(str[++i], box);
		else
			ft_putchar(str[i], box);
		i++;
	}
}
