/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:42:56 by bpoetess          #+#    #+#             */
/*   Updated: 2022/01/05 23:54:34 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_printchar(s[i++]);
	return (i);
}

int	ft_putnbr_alphab(ssize_t n, char *alphabet)
{
	int	base;
	int	i;

	i = 0;
	base = (int) ft_strlen(alphabet);
	if (n >= 0 && n <= base - 1)
		return (ft_printchar(alphabet[n]));
	else if (n >= -base + 1 && n <= -1)
		return (ft_printchar('-') + ft_printchar(alphabet[-n]));
	else
	{
		if (n > 0)
		{
			i += ft_putnbr_alphab(n / base, alphabet);
			return (i + ft_putnbr_alphab(n % base, alphabet));
		}
		else
		{
			i += ft_printchar('-');
			i += ft_putnbr_alphab(-(n / base), alphabet);
			return (i + ft_putnbr_alphab(-(n % base), alphabet));
		}
	}
	return (0);
}

int	ft_putunbr_alphab(size_t n, char *alphabet)
{
	int	base;
	int	i;

	base = (int) ft_strlen(alphabet);
	if (n >= (unsigned long) 0 && n <= (unsigned long)(base - 1))
		return (ft_printchar(alphabet[n]));
	else
	{
		i = ft_putnbr_alphab(n / base, alphabet);
		return (i + ft_putnbr_alphab(n % base, alphabet));
	}
	return (0);
}
