/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:02:17 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/06 19:07:51 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				precision;
	int				fminus;
	int				fspace;
	int				width;
	int				fzero;
	int				fplus;
	int				fdot;
	int				len;
	char			type;
}				t_list;

/* ft_printf.c */
int				ft_printf(const char *str, ...);

/* ft_parser.c */
void                    ft_parser(va_list *argptr, char *str, t_list *box);

/* ft_analysis.c */
void			ft_analysis(va_list *argptr, char *str, t_list *box);

/* ft_c_craft.c */
void			ft_c_craft(char c, t_list *box);

/* ft_s_craft.c */
void			ft_s_craft(char *str, t_list *box);

/* ft_di_craft.c */
void			ft_di_craft(int nbr, t_list *box);

/* ft_u_craft.c */
void			ft_u_craft(unsigned int nbr, t_list *box);

/* ft_xx_craft_one.c */
void			ft_xx_craft(long x, int type, t_list *box);

/* ft_xx_craft_two.c */
void			ft_print_hexa_one(char *basechar, long x, t_list *box);
void			ft_print_hexa_two(char *basechar, long x, t_list *box);
void			ft_print_hexa_three(char *basechar, long x, t_list *box);

/* ft_p_craft.c */
void			ft_p_craft(unsigned long long x, t_list *box);

/* ft_percent_craft.c */
void			ft_percent_craft(t_list *box);

/* ft_utilities_one.c */
void                    ft_putstr(char *str, t_list *box);
void                    ft_putchar(char c, t_list *box);
void                    ft_super_putchar(int len, char c, t_list *box);
long                    ft_atoi_alpha(const char *nptr);
void                    ft_putstr_precision(char *str, t_list *box);

/* ft_utilities_two.c */
size_t			ft_uintlen(unsigned int nbr);
size_t			ft_intlen(long x);
size_t			ft_strlen(const char *s);
void                    ft_putnbr(int n, t_list *box);
char                    *ft_strchr(const char *s, int c);

/* ft_utilities_three.c */
int                             ft_baselen(unsigned long x);
void                    ft_putnbr_unsigned(unsigned int nbr, t_list *box);
void			ft_putstr_hexa(char *str, long x, t_list *box);

#endif
