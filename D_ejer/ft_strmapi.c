/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:27:29 by scartage          #+#    #+#             */
/*   Updated: 2022/02/07 18:29:39 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;		//creamos variable donde vamos a guardar los valores
	size_t 	len;
	size_t	i;

	len = ft_strlen(s);	 //pedimos el tamano de la s que nos pasan
	str = malloc(sizeof(char) * (len + 1));		//reservamos memoria del tamano que mide la str que nos paasan
	if (str == NULL)
		return (NULL);			//comprobamos que hicimos bien la reserva
	i = 0;		
	while (i < len)
	{
		str[i] = f(i, s[i]);	//guardamos caracter por caracter, pasado por F, en la nueva str
		i++;
	}
	str[i] = '\0';		//ponemos en la ultima posicion el tope
	return (str);
}
