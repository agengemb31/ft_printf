/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:43:37 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/04 16:59:37 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>

int char_recovery(va_list *);
char *ft_utoa(unsigned int);
int hexa_recovery(char, va_list *);
char *hexa_convert(unsigned long);
int int_recovery(char c, va_list *);
int p_recovery(va_list *);
int str_recovery(va_list *);
