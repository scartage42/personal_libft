/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:22:30 by scartage          #+#    #+#             */
/*   Updated: 2022/02/11 18:20:59 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_absolute_value(int n)   //comprobamos si el int es positivo o negativo
{
	if (n < 0)
		return (-n);
	return (n);
}

size_t	ft_get_len(int n)	//miramos cuantos datos hay en int
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		len--;
		str[len] = ft_absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

//preguntar y mejorar las matematicas de este ejercicio
