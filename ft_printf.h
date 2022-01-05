/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:17:01 by bpoetess          #+#    #+#             */
/*   Updated: 2022/01/05 21:34:22 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef FT_HEX_ALPH_U
#  define FT_HEX_ALPH_U "0123456789ABCDEF"
# endif

# ifndef FT_HEX_ALPH_L
#  define FT_HEX_ALPH_L "0123456789abcdef"
# endif

# ifndef FT_DEC_ALPH
#  define FT_DEC_ALPH "0123456789"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_putnbr_alphab(ssize_t n, char *alphabet);
int		ft_putunbr_alphab(size_t n, char *alphabet);

int		ft_printf(const char *s, ...);
int		ft_choosefunc(char s, va_list ag);

#endif