/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_recovery.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:34:37 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/04 16:51:44 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int str_recovery(va_list *it)
{
	char	*s;

	s = va_arg(*it, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

