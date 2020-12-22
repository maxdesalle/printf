/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:02:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/22 10:38:11 by mdesalle         ###   ########.fr       */
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
	int				ftag;
	int				len;
	char			type;
}				t_list;

int				ft_baselen(unsigned long x);
int				ft_printf(const char *str, ...);
int				ft_parser(va_list argptr, char *str, t_list *box);
char			*ft_strchr(const char *s, int c);
void			ft_putchar(char c, t_list *box);
void			ft_super_putchar(int len, char c, t_list *box);
void			ft_analysis(char *str, t_list *box);
void			ft_c_craft(char c, t_list *box);
void			ft_putstr(char *str, t_list *box);
void			ft_s_craft(char *str, t_list *box);
void			ft_putstr_precision(char *str, t_list *box);
void			ft_di_craft(int nbr, t_list *box);
long			ft_atoi_alpha(const char *nptr);
void			ft_putnbr(int n, t_list *box);
void			ft_u_craft(unsigned int nbr, t_list *box);
void			ft_putnbr_unsigned(unsigned int nbr, t_list *box);
void			ft_xx_craft(unsigned int x, int type, t_list *box);
size_t			ft_uintlen(unsigned int nbr);
size_t			ft_intlen(long x);
size_t			ft_strlen(const char *s);

#endif
