/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:47 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/04 20:06:13 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str_format, ...);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(int nbr, char *base);

#endif
