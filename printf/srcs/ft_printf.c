/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:45:00 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/04 16:44:45 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/printf.h"

static int	printf_menu(char c, va_list *it)
{
	if (c == 'c')
		return (char_recovery(it));
	else if (c== 's')
		return (str_recovery(it));
	else if (c == 'p')
		return (p_recovery(it));
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
		if (*(format + i) == '%')
			size += printf_menu(*(format + ++i), &it);
		else
			ft_putchar_fd(*(format + i), 1);
		i++;
	}
	return (size);
}

int main()
{
	int annee = 1450;
	char *pays = "France";
	ft_printf("En l'an %d, la %s avait gagné la guerre de Cent Ans\n", annee, pays);
	printf("En l'an %d, la %s avait gagné la guerre de Cent Ans\n", annee, pays);
	
	int *p = &annee;
	ft_printf("Le pointeur p a pour adresse %p\n", p);
	printf("Le pointeur p a pour adresse %p\n", p);

	
	ft_printf("L'annee %d a pour valeur decimal %x ou %X\n", annee, annee, annee);
	printf("L'annee %d a pour valeur decimal %x ou %X\n", annee, annee, annee);
	
	ft_printf("En %s la population representait 50%% de la population europeene en %d\n", pays, annee);
	printf("En %s la population representait 50%% de la population europeene en %d\n", pays, annee);
	
	ft_printf("Le caractere %c est present a 60%% dans les mots de la langue francaise\n", 'a');
	printf("Le caractere %c est present a 60%% dans les mots de la langue francaise\n", 'a');
	
	annee = 1350;
	ft_printf("La guerre de Cent a commence en l'an %i\n", annee);
	printf("La guerre de Cent a commence en l'an %i\n", annee);
	
	annee = -1350;
	ft_printf("La guerre de Cent a commence en l'an %i\n", annee);
	printf("La guerre de Cent a commence en l'an %i\n", annee);
	
	ft_printf("La guerre de Cent a commence en l'an %u\n", annee);
	printf("La guerre de Cent a commence en l'an %u\n", annee);
	return (0);
}
