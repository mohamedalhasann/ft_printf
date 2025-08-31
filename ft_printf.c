/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:02:30 by malhassa          #+#    #+#             */
/*   Updated: 2025/08/31 19:12:30 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int i;
    unsigned int count;
    va_list ap;
    va_start(ap,s);

    i = 0;
    count = 0;
    while (*s)
    {
        if(*s == '%' && *(s+1) == 'd')
        {
            count+=ft_putnbr(va_arg(ap,int));
            s+=2;
        }
        else if(*s == '%' && *(s+1) == 's')
        {
            count += ft_putstr(va_arg(ap,char *));
            s+=2;
        }
        else if (*s == '%' && *(s+1) == 'c')
        {
            count += ft_putchar(va_arg(ap,int));
            s+=2;
        }
        else if (*s == '%' && (*(s+1) == 'x' || *(s+1) =='X'))
        {
            count += ft_puthexa((va_arg(ap,unsigned int)),*(s+1));
            s+=2;        
        }
        else
        {
         count += ft_putchar(*s);
         s++;   va_arg(ap
        }
    }
    return (count);
}

int main(void ) 
{
    int num = 255;

    ft_printf("Decimal: %d\n", num);
    ft_printf("Hexadecimal (uppercase): %X\n", num);  // FF
    ft_printf("Hexadecimal (lowercase): %x\n", num);  // ff

    return 0;
}
