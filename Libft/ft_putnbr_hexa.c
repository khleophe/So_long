/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:06:49 by sdabbas           #+#    #+#             */
/*   Updated: 2025/11/24 15:39:08 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_hexa(int n)
{
	char		*base;
	long int	nb;
	int			i;

	base = "0123456789abcdef";
	nb = (long int)n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 16)
		ft_putnbr(nb / 16);
	i = (nb % 16);
	ft_putchar(base[i]);
}
