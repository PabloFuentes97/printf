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
	unsigned int n;
	
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

int	unsigned_len(unsigned long int n)
{
	unsigned long int nb;
	int		cont;

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
	int 				len_num;
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

	nb= n;
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
   int   cont;

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

int put_ptr(void *ptr)
{
	int cont;

	cont = 0;
	cont = ft_putstr("0x");
	cont += print_ptr((unsigned long long int)ptr);
	//printf("La dirección del puntero es: %llu\n", (unsigned long long int)ptr);
	//printf("La longitud del puntero en hex es: %d\n", cont);
	return (cont);
}

