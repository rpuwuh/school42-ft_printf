/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:16:29 by bpoetess          #+#    #+#             */
/*   Updated: 2022/01/05 23:36:57 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choosefunc(char s, va_list ag)
{
	int	i;

	if (s == '%')
		return (ft_printchar('%'));
	else if (s == 'c')
		return (ft_printchar((char) va_arg(ag, int)));
	else if (s == 's')
		return (ft_printstr(va_arg(ag, char *)));
	else if (s == 'p')
	{
		i = ft_printstr("0x");
		i += ft_putunbr_alphab (va_arg(ag, long), FT_HEX_ALPH_L);
		return (i);
	}
	else if (s == 'd' || s == 'i')
		return (ft_putnbr_alphab (va_arg(ag, int), FT_DEC_ALPH));
	else if (s == 'u')
		return (ft_putunbr_alphab (va_arg(ag, unsigned int), FT_DEC_ALPH));
	else if (s == 'x')
		return (ft_putunbr_alphab (va_arg(ag, unsigned int), FT_HEX_ALPH_L));
	else if (s == 'X')
		return (ft_putunbr_alphab (va_arg(ag, unsigned int), FT_HEX_ALPH_U));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		readcount;
	int		i;
	va_list	ag;

	if (!s)
		return (0);
	va_start(ag, s);
	i = 0;
	readcount = 0;
	while (s[i])
	{
		if (s[i] != '%')
			readcount += ft_printchar(s[i++]);
		else
		{
			i++;
			readcount += ft_choosefunc(s[i], ag);
			i++;
		}
	}
	va_end(ag);
	return (readcount);
}
