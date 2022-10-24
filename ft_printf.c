/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2022/10/20 11:53:40 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(void *ptr)
{
	int	cont;

	cont = 0;
	cont = ft_putstr("0x");
	cont += print_ptr((unsigned long long int)ptr);
	return (cont);
}

int	count_print(char const *s, int print_len, va_list list, int *cont_s)
{
	if (s[*cont_s + 1] == 'c')
		print_len += ft_putchar(va_arg(list, int)) - 2;
	else if (s[*cont_s + 1] == 's')
		print_len += ft_putstr(va_arg(list, char *)) - 2;
	else if (s[*cont_s + 1] == 'p')
		print_len = print_len + put_ptr(va_arg(list, void *)) - 2;
	else if (s[*cont_s + 1] == 'd' || s[*cont_s + 1] == 'i')
		print_len += ft_putnbr(va_arg(list, int)) - 2;
	else if (s[*cont_s + 1] == 'u')
		print_len += ft_put_unsig_nbr(va_arg(list, int)) - 2;
	else if (s[*cont_s + 1] == 'x')
		print_len += ft_put_hex(va_arg(list, int), 'm') - 2;
	else if (s[*cont_s + 1] == 'X')
		print_len += ft_put_hex(va_arg(list, int), 'M') - 2;
	else if (s[*cont_s + 1] == '%')
		print_len += ft_putchar(s[*cont_s + 1]) - 2;
	return (print_len);
}

int	ft_printf(char const *s, ...)
{
	va_list	list;
	va_list	list_copy;
	int		cont_s;
	int		print_len;

	cont_s = 0;
	va_start(list, s);
	va_copy(list_copy, list);
	print_len = ft_strlen(s);
	while (s[cont_s])
	{
		if (s[cont_s] == '%')
		{
			print_len = count_print(s, print_len, list_copy, &cont_s);
			cont_s++;
		}
		else
			ft_putchar(s[cont_s]);
		cont_s++;
	}
	va_end(list);
	return (print_len);
}
