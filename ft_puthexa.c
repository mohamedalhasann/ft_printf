/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:35:15 by malhassa          #+#    #+#             */
/*   Updated: 2025/08/31 19:04:48 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include <stdio.h>
#include <unistd.h> 

int ft_puthexa(unsigned int num, char format)
{
    char    *hex_digits; 
    char    *HEX_digits;
    char    temp[100];
    int i;
    int count;

    hex_digits = "0123456789abcdef";
    HEX_digits = "0123456789ABCDEF";
    count = 0;
    i = 0;
    if (num == 0)
        return (write(1, "0", 1));
    while (num > 0) 
    {
        int remainder = num % 16;
        if (format == 'x')
            temp[i++] = hex_digits[remainder]; 
        else
            temp[i++] = HEX_digits[remainder]; 
        num /= 16;
    }
    while (i > 0) 
        count+= ft_putchar(temp[--i]);
    return count; 
}
