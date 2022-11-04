/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:50 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/04 19:06:47 by bel-idri         ###   ########.fr       */
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
				// DO
			if (str_format[i + 1] == 's')
				// DO
			if (str_format[i + 1] == 'p')
				// DO
			if (str_format[i + 1] == 'd' || str_format[i + 1] == 'i')
				// DO
			if (str_format[i + 1] == 'u')
				// DO
			if (str_format[i + 1] == 'x' || str_format[i + 1] == 'X')
				// DO
			if (str_format[i + 1] == '%')
				// DO

		}
	}



	va_end(ap);
}
