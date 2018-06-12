/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:58:39 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:44:08 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"

int		get_room_id(PLIST rooms, char *name)
{
	PLIST node;

	node = rooms;
	while (node)
	{
		if (ft_strcmp(NODE_TO_ROOM(node)->name, name) == 0)
			return (NODE_TO_ROOM(node)->id);
		node = node->next;
	}
	return (BAD_ROOM_ID);
}

int		get_id_of_source(PLIST rooms)
{
	PLIST node;

	node = rooms;
	while (node)
	{
		if (NODE_TO_ROOM(node)->type == TYPE_ORIGIN)
			return (NODE_TO_ROOM(node)->id);
		node = node->next;
	}
	return (BAD_ROOM_ID);
}

int		get_id_of_destination(PLIST rooms)
{
	PLIST node;

	node = rooms;
	while (node)
	{
		if (NODE_TO_ROOM(node)->type == TYPE_DESTINATION)
			return (NODE_TO_ROOM(node)->id);
		node = node->next;
	}
	return (BAD_ROOM_ID);
}

char	*get_room_name(int id, PLIST rooms)
{
	PLIST node;

	node = rooms;
	while (node)
	{
		if (NODE_TO_ROOM(node)->id == id)
			return (NODE_TO_ROOM(node)->name);
		node = node->next;
	}
	return (UNKNOWN_NAME);
}
