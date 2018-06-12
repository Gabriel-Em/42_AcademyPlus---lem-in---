/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:58:30 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:43:35 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"

static BOOL	is_valid_input(char *line)
{
	int i;
	int	oldi;

	i = 0;
	if (ft_strlen(line) > 0 && line[0] == 'L')
		return (FALSE);
	while (line[i] && line[i] != SPACE)
		i++;
	if (line[i] != SPACE || i == 0)
		return (FALSE);
	i++;
	oldi = i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != SPACE || i == oldi)
		return (FALSE);
	i++;
	oldi = i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (i == oldi || line[i])
		return (FALSE);
	return (TRUE);
}

static BOOL	room_exists(PLIST rooms, char *name)
{
	PLIST node;

	node = rooms;
	while (node)
	{
		if (ft_strcmp(NODE_TO_ROOM(node)->name, name) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

static BOOL	source_or_destination_exists(PLIST rooms, int type)
{
	PLIST node;

	node = rooms;
	while (node)
	{
		if (NODE_TO_ROOM(node)->type == type)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void		destroy_room(PROOM *room)
{
	if (!(*room))
		return ;
	if ((*room)->name)
		ft_strdel(&((*room)->name));
	free(*room);
	*room = NULL;
}

PROOM		create_room(char **line, int type, int id, PLIST rooms)
{
	PROOM room;

	if (!is_valid_input(*line) || !(room = (PROOM)malloc(sizeof(ROOM))))
		return (NULL);
	room->name = ft_strcutuntil(line, SPACE);
	if (room_exists(rooms, room->name)
			|| ((type == TYPE_ORIGIN || type == TYPE_DESTINATION)
			&& source_or_destination_exists(rooms, type)))
	{
		destroy_room(&room);
		return (NULL);
	}
	if (type == TYPE_ORIGIN || type == TYPE_DESTINATION)
		room->type = type;
	else
		room->type = TYPE_NORMAL;
	room->coord.x = ft_atoi(*line);
	room->coord.y = ft_atoi(*line + ft_intlen(room->coord.x) + 1);
	room->id = id;
	return (room);
}
