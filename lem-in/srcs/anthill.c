/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:59:14 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:29:08 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anthill.h"

void		destroy_anthill(PANTHILL *anthill)
{
	PLIST		node;
	PLIST		temp;

	if (!anthill || !(*anthill))
		return ;
	node = (*anthill)->rooms;
	while (node)
	{
		destroy_room((PROOM*)(&(node->content)));
		temp = node->next;
		free(node);
		node = temp;
	}
	node = (*anthill)->connections;
	while (node)
	{
		destroy_connection((PCONNECTION*)(&(node->content)));
		temp = node->next;
		free(node);
		node = temp;
	}
	free(*anthill);
	*anthill = NULL;
}

PANTHILL	init_anthill(void)
{
	PANTHILL anthill;

	if (!(anthill = (PANTHILL)malloc(sizeof(ANTHILL))))
		return (NULL);
	anthill->rooms = NULL;
	anthill->connections = NULL;
	return (anthill);
}

void		add_room(PANTHILL anthill, PROOM room)
{
	PLIST new_room_node;

	new_room_node = ft_lstnew(NULL, 0);
	new_room_node->content = (void*)room;
	new_room_node->content_size = sizeof(room);
	ft_lstappend(&(anthill->rooms), new_room_node);
}

void		add_connection(PANTHILL anthill, PCONNECTION connection)
{
	PLIST new_connection_node;

	new_connection_node = ft_lstnew(NULL, 0);
	new_connection_node->content = (void*)connection;
	new_connection_node->content_size = sizeof(connection);
	ft_lstappend(&(anthill->connections), new_connection_node);
}
