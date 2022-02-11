/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:24:03 by scartage          #+#    #+#             */
/*   Updated: 2022/02/08 19:30:55 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)		//los fd que nos dan son un non zero integer, tambien son non negative integer
		return	;		//0 es para standar input, 1 es para standar output y 2 es standar error
	write(fd, &c, 1);
}
