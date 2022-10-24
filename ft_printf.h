/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2022/10/20 12:00:43 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		num_len(int n);
int		check_spec(int n, int spec);
char	*fill_arr(char *array, unsigned int first_block, int n, int len_num);
int		ft_putnbr(int nb);
int		ft_put_unsig_nbr(int n);
int		num_len_hex(unsigned int n);
int		ft_put_hex(int n, char c);
int		print_ptr(unsigned long long int num);
int		put_ptr(void *ptr);
int		count_print(char const *s, int print_len, va_list list, int *cont_s);
int		ft_printf(char const *s, ...);

#endif
