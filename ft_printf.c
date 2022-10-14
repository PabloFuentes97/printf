#include "ft_printf.h"

int num_arg(char const *s)
{
    int     cont_s;
    int     cont_arg;

    cont_s = 0;
    cont_arg = 0;
    while (s[cont_s]) 
    {
        if (s[cont_s] == '%')
        {
            if (s[cont_s + 1] == 'c' || s[cont_s + 1] == 's' || s[cont_s + 1] == 'p' || s[cont_s + 1] == 'd'
                || s[cont_s + 1] == 'i' || s[cont_s + 1] == 'u' || s[cont_s + 1] == 'x' || s[cont_s + 1] == 'X'
                || s[cont_s + 1] == '%')
                cont_arg++;
            
        }
        cont_s++;
    }
    return (cont_arg);
}

int count_print(char const *s, int print_len, va_list list, int cont_s)
{
	while (s[cont_s])
    {
        if (s[cont_s] == '%')
        {
            if (s[cont_s + 1] == 'c')
                print_len += ft_putchar(va_arg(list, int)) - 2;
            else if (s[cont_s + 1] == 's')
                print_len += ft_putstr(va_arg(list, char*)) - 2;
            else if (s[cont_s + 1] == 'p')
            	print_len = print_len + put_ptr(va_arg(list, void*)) - 2;
            else if (s[cont_s + 1] == 'd' || s[cont_s + 1] == 'i')
                print_len += ft_putnbr(va_arg(list, int)) - 2;
            else if (s[cont_s + 1] == 'u')
                print_len += ft_put_unsig_nbr(va_arg(list, int)) - 2;
            else if (s[cont_s + 1] == 'x')
                print_len += ft_put_hex(va_arg(list, int), 'm') - 2;
            else if (s[cont_s + 1] == 'X')
               print_len += ft_put_hex(va_arg(list, int), 'M') - 2;
            else if (s[cont_s + 1] == '%')
                print_len += ft_putchar(s[cont_s + 1]) - 2;
			cont_s++;
        }
		else
			ft_putchar(s[cont_s]);
		cont_s++;
    }
	return (print_len);
}

int ft_printf(char const *s, ...)
{
    va_list list;
    va_list list_copy;
    int		cont_s;
	int		print_len;

    cont_s = 0;
    va_start(list, s);
    va_copy(list_copy, list);
	print_len = ft_strlen(s);
	//printf("Longitud original del string es: %d", print_len);
    print_len = count_print(s, print_len, list_copy, cont_s);
    //printf("El número de caracteres a imprimir es: %d\n", print_len);
    va_end(list);
	return (print_len); //aquí devuelve el número de caracteres total que debería imprimir
}


/*int main(void)
{
    void    *ptr;
    int     num;

    num = 100;
	ptr = &num;

    //ft_printf("%d %s %p\n", "kilometros", 9, &ptr, 10, "buenas");
    printf(" ---%d\n",ft_printf("%d", -1));
    printf(" ---%d", (printf("%d", -1)));
	//printf("La longitud de la string es: %zu", 
	//ft_strlen("Iba a una velocidad de -1 kilometros por hora y se estrelló en la esquina 9 de la calle 0x0 al grito de un e alargado.\n"));
	//printf("Iba a una velocidad de %d.\n", NULL);
}
*/

















