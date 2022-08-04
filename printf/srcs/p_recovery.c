/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_recovery.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:32:19 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/04 18:27:12 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	p_recovery(va_list *it)
{
	void	*p;
	char	*s;
	
	p = va_arg(*it, void *);
	s = hexa_convert((unsigned long) p);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
