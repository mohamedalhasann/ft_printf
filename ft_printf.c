/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:02:30 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/02 00:40:59 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int typecheck1(const char *s , va_list ap)
{
    int count;

    count = 0;
    if(*s == '%' && (*(s+1) == 'd' || *(s+1) == 'i'))
       count+=ft_putnbr(va_arg(ap,int));
    else if (*s == '%' && *(s+1) == 'u')
        count += ft_putuns(va_arg(ap,unsigned int));
    else if (*s == '%' && (*(s+1) == 'x' || *(s+1) =='X'))
        count += ft_puthexa((va_arg(ap,unsigned int)),*(s+1));    
    return (count);
}

static int typecheck2(const char *s , va_list ap)
{
    int count;

    count = 0;
    if(*s == '%' && *(s+1) == 's')
        count += ft_putstr(va_arg(ap,char *));
    else if (*s == '%' && (*(s+1) == 'c' || *(s+1) == '%'))
        count += ft_putchar(va_arg(ap,int));
    else if (*s == '%' && *(s+1) == 'p')
        count += ft_putptr(va_arg(ap,unsigned int), *(s+1));
    return (count);
}

static int ft_printf(const char *s, ...)
{
    unsigned int count;
    va_list ap;
    va_start(ap,s);

    count = 0;
    while (*s)
    {
        if (*s == '%' && ft_strchr("dxXiu",*(s+1)))
        {
            count += typecheck1(s,ap);
            s+=2;
        }
        else if (*s == '%' && ft_strchr("%scp",*(s+1)))
        {
            count += typecheck2(s,ap);
            s+=2;
        }
        else 
        {
            count += ft_putchar(*s);
            s++;
        }
    }
    return (count);
}
int main(void) 
{
    int num = 255;
    char *x;

    x = "mohamed";
    ft_printf("Decimal: %d\n", num);
    ft_printf("string : %s",x);
    ft_printf("%%");
   
    return 0;
}
