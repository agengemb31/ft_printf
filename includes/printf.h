/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:43:37 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/05 20:56:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		char_recovery(va_list *it);
char	*ft_utoa(unsigned int n);
size_t		hexa_recovery(char c, va_list *it);
char	*hexa_convert(unsigned long n);
int		int_recovery(char c, va_list *it);
size_t		p_recovery(va_list *it);
int		str_recovery(va_list *it);
int		ft_printf(const char *format, ...);
#endif
