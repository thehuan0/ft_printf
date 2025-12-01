/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:40:30 by jperez-s          #+#    #+#             */
/*   Updated: 2025/10/29 09:09:23 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
}	t_flags;

int		ft_printf(const char *format, ...);
t_flags	init_flags(void);
void	parse_flags(const char *format, int *i, t_flags *flags);
int		is_flag(char c);
int		is_digit(char c);
void	parse_flags_chars(const char *format, int *i, t_flags *flags);
void	parse_width(const char *format, int *i, t_flags *flags);
void	parse_precision(const char *format, int *i, t_flags *flags);
int		print_dispatch(t_flags flags, va_list *args);
int		print_char(t_flags flags, va_list *args);
int		print_string(t_flags flags, va_list *args);
int		print_pointer(t_flags flags, va_list *args);
int		print_number(t_flags flags, va_list *args);
int		print_unsigned(t_flags flags, va_list *args);
int		print_hex(t_flags flags, va_list *args, int uppercase);
int		print_percent(t_flags flags);
int		apply_width(int width, int len, int zero);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(unsigned long n, char *base);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);

#endif
