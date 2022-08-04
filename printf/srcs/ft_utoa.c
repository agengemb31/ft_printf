/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:18:06 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/04 16:58:19 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/printf.h"

static size_t	count_numbers(unsigned int n)
{
	size_t	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*make_string(unsigned int n, int negatif)
{
	char	*res;
	int		i;
	int		reste;
	size_t	size;

	size = count_numbers(n) + negatif;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = size;
	res[i] = '\0';
	while (--i >= 0 + negatif)
	{
		reste = n % 10;
		if (negatif)
			reste *= -1;
		res[i] = reste + '0';
		n /= 10;
	}
	if (negatif)
		res[i] = '-';
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	int	negatif;

	if (n < 0)
		negatif = 1;
	else
		negatif = 0;
	return (make_string(n, negatif));
}

