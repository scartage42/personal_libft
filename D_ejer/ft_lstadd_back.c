/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:11:11 by scartage          #+#    #+#             */
/*   Updated: 2022/02/11 16:01:33 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == NULL)    //si lst es nulo es el ultimo nodo, no esta next apundo
		*lst = new;		//a ese ultimo nodo le guardamos el contenido de new
	else
	{
		aux = *lst;
		while (aux->next != NULL)
			aux = aux->next;			//lo llevamos hasta el nodo que tenga en next null
		aux->next = new;				//ese seria el ultimo nodo, donde guardaremos la informacion
	}
}
