/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2022/10/20 12:01:08 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_len(unsigned long int n)
{
	unsigned long int	nb;
	int					cont;

	nb = n;
	cont = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		cont++;
	}
	return (cont);
}

int	ft_put_unsig_nbr(int n)
{	
	int					len_num;
	unsigned long int	nb;

	if (n < 0)
		nb = 4294967295 + n + 1;
	else
		nb = n;
	len_num = unsigned_len(nb);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len_num);
}

int	num_len_hex(unsigned int n)
{
	unsigned int	nb;
	int				cont;

	nb = n;
	cont = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		cont++;
	}
	return (cont);
}

int	ft_put_hex(int n, char c)
{
	unsigned int	nb;
	char			*hex_base;

	nb = (unsigned int)n;
	if (c == 'm')
		hex_base = "0123456789abcdef";
	else if (c == 'M')
		hex_base = "0123456789ABCDEF";
	else
		return (-1);
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, c);
		ft_put_hex(nb % 16, c);
	}
	else
		ft_putchar(hex_base[nb]);
	return (num_len_hex(n));
}

int	print_ptr(unsigned long long int num)
{
	int	cont;

	cont = 0;
	if (num < 16)
		cont += ft_putchar("0123456789abcdef"[num % 16]);
	else if (num >= 16)
	{
		cont = print_ptr(num / 16);
		cont += ft_putchar("0123456789abcdef"[num % 16]);
	}
	return (cont);
}
