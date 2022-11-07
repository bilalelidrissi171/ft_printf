/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:50 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/05 18:32:57 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_len_i_d(int s)
{
	int	i;

	ft_putnbr_base_i_d(s, "0123456789");
	i = 0;
	if (s == 0)
		return (1);
	if (s < 0)
		i++;
	while (s)
	{
		s /= 10;
		i++;
	}
	return (i);
}

static int	count_len_u_x(unsigned int s, char *base)
{
	int	i;

	ft_putnbr_base_u_x(s, base);
	i = 0;
	if (s == 0)
		return (1);
	while (s)
	{
		s /= 10;
		i++;
	}
	return (i);
}

static int	count_len_p(unsigned long s)
{
	int	i;

	ft_putstr("0x");
	ft_putnbr_base_p(s, "0123456789abcdef");
	i = 0;
	if (s == 0)
		return (3);
	while (s)
	{
		s /= 10;
		i++;
	}
	return (i);
}

int	ft_printf(const char *str_format, ...)
{
	va_list	ap;
	size_t	i;
	int		res;

	res = 0;
	va_start(ap, str_format);
	while (i < ft_strlen(str_format))
	{
		if (str_format[i] != '%')
			res += ft_putchr(str_format[i]);
		else
		{
			i++;
			if (str_format[i] == 'c')
				res += ft_putchr(va_arg(ap, int));
			else if (str_format[i] == 's')
				res += ft_putstr(va_arg(ap, char *));
			else if (str_format[i] == 'p')
				res += count_len_p(va_arg(ap, unsigned long));
			else if (str_format[i] == 'd' || str_format[i] == 'i')
				res += count_len_i_d(va_arg(ap, int));
			else if (str_format[i] == 'u')
				res += count_len_u_x(va_arg(ap, unsigned int), "0123456789");
			else if (str_format[i] == 'x')
				res += count_len_u_x \
				(va_arg(ap, unsigned long), "0123456789abcdef");
			else if (str_format[i] == 'X')
				res += count_len_u_x \
				(va_arg(ap, unsigned long), "0123456789ABCDEF");
			else if (str_format[i] == '%')
				res += ft_putchr('%');
		}
		i++;
	}
	va_end(ap);
	return (res);
}

int main()
{
	void *d = "s";
	int i = ft_printf("%x\n",d);
	printf("%i",i);
}
