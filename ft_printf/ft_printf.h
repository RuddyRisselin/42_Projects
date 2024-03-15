/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:50 by rrisseli          #+#    #+#             */
/*   Updated: 2023/12/18 16:31:50 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_triprintf(const char format, va_list info);
int	ft_printf(const char *format, ...);
int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printd(int nb);
int	ft_printuns(unsigned int nb);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	printptr(void *addr);
#endif