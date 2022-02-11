/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:23:10 by scartage          #+#    #+#             */
/*   Updated: 2022/02/11 15:50:25 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*f;
	unsigned char	q;

	f = (char *)s;
	q = (unsigned char)c;
	i = 0;
	if (q == 0)
		return (s + ft_strlen(s));
	while (f[i] != '\0')
	{
		if (f[i] == q)
			return (&f[i]);
		i++;
	}
	return (NULL);
}
