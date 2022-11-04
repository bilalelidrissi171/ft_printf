/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:50 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/04 20:21:10 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str_format, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, str_format);

	while(i < ft_strlen(str_format))
	{
		if (str_format[i] != '%')
			write(1, str_format[i], 1);

		if (str_format[i] == '%')
		{
			i++;
			if (str_format[i] == 'c')
				write(1, va_arg(ap, char), 1);
			else if (str_format[i] == 's')
				write(1, va_arg(ap, char *), ft_strlen(va_arg(ap, char *)));
			else if (str_format[i] == 'p')
			{
				write(1, "0x", 2);
				ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
			}
			else if (str_format[i] == 'd' || str_format[i] == 'i')
				ft_putnbr_base_u(va_arg(ap, int), "0123456789");
			else if (str_format[i] == 'u')
				ft_putnbr_base_u(va_arg(ap, unsigned int), "0123456789");
			else if (str_format[i] == 'x')
				ft_putnbr_base(va_arg(ap, unsigned long long), "0123456789abcdef");
			else if (str_format[i] == 'X')
				ft_putnbr_base(va_arg(ap, unsigned long long), "0123456789ABCDEF");
			else if (str_format[i] == '%')
				write(1, '%', 1);
			else
				write(1, '%', 1);
		}
	}
	va_end(ap);
}



