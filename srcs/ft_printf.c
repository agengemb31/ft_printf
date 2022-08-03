/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:45:00 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/02 14:04:06 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

char	*hexa_convert(void const *p)
{
	size_t	size;
	unsigned long n_bis, n;
	char	*hexa_base = "0123456789abcdef";

	size = 0;
	n = (unsigned long) p;
	n_bis = n;
	while (n_bis)
	{
		n_bis /= 16;
		size++;
	}
	char *hexa_nb;
	hexa_nb = malloc(sizeof(char) * (size + 1));
	if (!hexa_nb)
		return (NULL);
	*(hexa_nb + size) = '\0';
	while (n)
	{
		*(hexa_nb + --size) = hexa_base[n % 16]; 
		n /= 16;	
	}
	return (hexa_nb);
}

int char_recovery(va_list *it)
{
	char	c;

	c = va_arg(it, char);
	ft_putchar_fd(c, 1);
	return (1)
}
int str_recovery(va_list *it)
{
	char	*s;

	s = va_arg(it, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int pointeur_recovery(va_list *it)
{
	void	*p;
	char	*s;
	
	p = va_arg(it, void *);
	s = hexa_convert(p);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int int_recovery(char c, va_list *it)
{
	char	*s;

	if (c == 'u')
		s = ft_itoa(va_arg(it, unsigned int));
	else
		s = ft_itoa(va_arg(it, int));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int hexa_recovery(char c, va_list it)
{
	int	integer;
	char	*s;

	integer = va_arg(it, int);
	s = hexa_convert(integer);
	if (c == 'X')
		s = ft_strmapi(s, &ft_toupper);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	printf_menu(char c, va_list *it)
{
	if (c == 'c'))
		return (char_recovery(it));
	else if (c== 's'))
		return (str_recovery(it));
	else if (c == 'p'))
		return (pointeur_recovery(it));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (int_recovery(c, it));
	else if (c == 'x' || c == 'X')
		return (hexa_recovery(c, it));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list it;
	size_t	i;
	int	size;
	
	va_start(it, format);
	i = 0;
	size = 0;
	while (*(format + i))
	{
		if (*(format + i++) == '%')
			size += printf_menu(*(format + i++), &it)
	}
	return (size);
}

int main()
{
	int annee = 1450;
	char *pays = "France";
	ft_printf("En l'an %d, la %s avait gagné la guerre de Cent Ans", annee, pays);
	return (0);
}
