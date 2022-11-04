/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:50 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/04 20:09:15 by bel-idri         ###   ########.fr       */
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
			if (str_format[i + 1] == 'c')
				write(1, va_arg(ap, char), 1);
			if (str_format[i + 1] == 's')
				write(1, va_arg(ap, char *), ft_strlen(va_arg(ap, char *)));
				va_arg(ap, char *);
			if (str_format[i + 1] == 'p')
				// DO
			if (str_format[i + 1] == 'd' || str_format[i + 1] == 'i')
				ft_putnbr_base(va_arg(ap, char), "0123456789");
			if (str_format[i + 1] == 'u')
				// DO
			if (str_format[i + 1] == 'x')
				ft_putnbr_base(va_arg(ap, char), "0123456789ABCDEF");
			if (str_format[i + 1] == 'X')
				ft_putnbr_base(va_arg(ap, char), "0123456789");
			if (str_format[i + 1] == '%')
				// DO

		}
	}



	va_end(ap);
}
