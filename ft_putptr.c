/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:33:56 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/02 00:29:13 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(void *ptr , char format)
{
    unsigned int *address;

    address = (unsigned int *)(ptr);
    printf("%u\n",*address);
    return (ft_puthexa(*address,format));
}

// int main(void)
// {
//     void    *ptr;

//     ft_putptr(ptr,'X');
// }