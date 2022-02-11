/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:33:21 by scartage          #+#    #+#             */
/*   Updated: 2022/02/10 20:04:57 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counting_words(char const *s, char c)		//funcion para contar la cantidad de palabras delimitadas
{
	size_t i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)						//buscamos los primeros delimitadores y los pasamos
			i++;
		if (s[i] && s[i] != c)					//cuando encontremos un char que no es c empezamos a contar como una palabra hasta el prox delimitador
			count++;
		while (s[i] && s[i] != c)				//recorremos hasta encontrar otro c y se repite el ciclo
			i++;
	}
	return (count);								//al final devolvemos la cantidad de palabras encontradas

}

static char *ft_making_words(char const *s, char c)	//con esta funcion hacemos palabras, la guardamos en una variable, palabra por palabra segun vayamos recorriendo la str
{
	size_t	i;
	char 	*str;

	i = 0;
	while (s[i] && s[i] != c)					//miramos cuantos char hay antes de toparte con un delimitador
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)					
	{
		str[i] = s[i];						//empezamos a copiar en la nueva variable los datos de la palabra que encontramos
		i++;;
	}
	str[i] = '\0';							//al finalizar ponnemos el tope de la string
	return (str);
}

char	**ft_split(char const *s, char c) 	//nos pasan una str con su respectivo delimitador
{
	size_t 	strn;
	size_t 	i;
	char	**string;

	strn = ft_counting_words(s, c);					//pedimos la cantidad de datos que vamos a tener
	string = ft_calloc(sizeof(char **), strn + 1);	//reservamos espacio de memoria para un array de arrays mas la cantidad de palabras que tenemos
	if (string == NULL)
		return (NULL);								//protegemos la reserva
	i = 0;
	while (i < strn)								//mietras el indice sea menor al numero de palabras 
	{
		while (*s == c)
			s++;
		string[i] = ft_making_words(s, c);			//empezamos a rellenar la string general con las palabras
		if (string[i] == NULL)						//en caso de que al pasar los datos algo falle
		{
			while (i > 0)							//miramos cual es el indice de la string general
				free(string[--i]);					//empezamos a liberar espacio desde donde encontramos el fallo hasta atras
			free(string);							//despues liberamos el array general
			return (0);								//como es una falla devolvemos 0
		}
		s += ft_strlen(string[i]);					//sumamos a s el tamano de la palabra creada para recorrer los datos
		i++;
	}
	string[i] = 0;								//ponemos un tope al ultimo espacio de la array general
	return (string);
}
