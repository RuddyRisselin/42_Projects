/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:46:23 by rrisseli          #+#    #+#             */
/*   Updated: 2023/12/18 11:46:37 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int			len_base;
	long int	n;
	int			size;

	n = nbr;
	len_base = ft_strlen(base);
	size = 0;
	if (n >= len_base)
	{
		size += ft_putnbr_base(n / len_base, base);
		size += ft_putchar(base[n % len_base]);
	}
	else
	{
		size += ft_putchar(base[n]);
	}
	return (size);
}
