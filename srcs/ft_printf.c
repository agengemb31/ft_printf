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

int main()
{
	char *p = "coucou";

	printf("%p\n", p);
	printf("%s\n", hexa_convert((void const *)p));
	return (0);
}
