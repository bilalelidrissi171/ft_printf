/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:50 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/05 02:26:21 by bel-idri         ###   ########.fr       */
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
			write(1, &str_format[i], 1);
		else
		{
			i++;
			if (str_format[i] == 'c')
				ft_putchr(va_arg(ap, int));
			else if (str_format[i] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (str_format[i] == 'p')
			{
				write(1, &"0x", 2);
				ft_putnbr_base_p(va_arg(ap, unsigned long), "0123456789abcdef");
			}
			else if (str_format[i] == 'd' || str_format[i] == 'i')
				ft_putnbr_base_i_d(va_arg(ap, int), "0123456789");
			else if (str_format[i] == 'u')
				ft_putnbr_base_u_x_X(va_arg(ap, unsigned int), "0123456789");
			else if (str_format[i] == 'x')
				ft_putnbr_base_u_x_X(va_arg(ap, unsigned long), "0123456789abcdef");
			else if (str_format[i] == 'X')
				ft_putnbr_base_u_x_X(va_arg(ap, unsigned long), "0123456789ABCDEF");
			else if (str_format[i] == '%')
				ft_putchr('%');
			else
				ft_putchr('%');
		}
		i++;
	}
	va_end(ap);
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	ft_printf("c = %c , s = %s , p = %p , d = %d , i = %i , u = %u , x = %x , X = %X , %%\n",'c',"salam",&"test",15,15,15,15,15);
// 	printf("c = %c , s = %s , p = %p , d = %d , i = %i , u = %u , x = %x , X = %X , %%\n",'c',NULL,&"test",15,15,15,15,15);
// 	//printf("c = %c , s = %s , p = %p , d = %d , i = %i , u = %u , x = %x , X = %X , %%\n",NULL,NULL,&"test",18446744073709551610ull,18446744073709551610ull,4294967295,4294967296,15);
// 	//ft_printf("c = %c , s = %s , d = %d , i = %i , u = %u , x = %x , X = %X , %%\n",NULL,NULL,18446744073709551610ull,18446744073709551610ull,4294967295,4294967296,15);
// }

