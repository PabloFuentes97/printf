/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2022/10/20 12:01:20 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	cont;

	cont = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[cont] != '\0')
	{
		ft_putchar(str[cont]);
		cont++;
	}
	return (cont);
}

int	num_len(int n)
{
	unsigned int	first_block;
	int				cont;

	first_block = n;
	cont = 1;
	if (n < 0)
	{
		cont++;
		first_block = first_block * -1;
	}
	while (first_block >= 10)
	{
		first_block = first_block / 10;
		cont++;
	}
	return (cont);
}

int	ft_putnbr(int nb)
{	
	unsigned int	n;

	n = (unsigned int)nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (num_len(nb));
}
