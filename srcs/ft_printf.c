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

/*int	ft_printf(const char *format, ...)
{
	
}*/

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
		{
			if (*(format + i) == 'c'))
				char c = va_arg(it, char);
				ft_putchar_fd(c, 1);
			else if (*(format + i) == 's'))
				char s = va_arg(it, char *);
				ft_putstr_fd(s, 1);
			else if (*(format + i) == 'p'))
				char s = va_arg(it, char *);
				ft_putstr_fd(s, 1);
			else if (*(format + i) == 'd' || *(format + i) == 'i'))
				int entier = va_arg(it, int);
				ft_putnbr_fd(entier, 1);
			else if (*(format + i) == 'u'))
				unsigned int entier = va_arg(it, unsigned int);
				ft_putnbr_fd(entier, 1);
			else if (*(format + i) == 'x'))
				int s = va_arg(it, long);
				ft_putstr_fd(hexa_convert(s), 1);
			else if (*(format + i) == 'X'))
				int s = va_arg(it, long);
				ft_putstr_fd(ft_toupper(hexa_convert(s)), 1);
			else if (*(format + i) == '%'))
				ft_putchar_fd('%', 1);
			i++;
		}
	}
}

int main()
{
	char *p = "coucou";

	printf("%p\n", p);
	printf("%s\n", hexa_convert((void const *)p));
	return (0);
}
