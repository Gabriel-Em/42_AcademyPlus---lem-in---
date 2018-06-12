/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:58:46 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:29:51 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connection.h"

static BOOL	is_valid_input(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (line[i] != '-')
		return (FALSE);
	i++;
	if (ft_strlen(line + i) == 0)
		return (FALSE);
	return (TRUE);
}

void		destroy_connection(PCONNECTION *connection)
{
	if (connection && *connection)
	{
		free(*connection);
		*connection = NULL;
	}
}

PCONNECTION	create_connection(char *line, PLIST rooms)
{
	PCONNECTION connection;
	char		*room1;
	char		*room2;

	if (!is_valid_input(line))
		return (NULL);
	if (!(connection = (PCONNECTION)malloc(sizeof(CONNECTION))))
		return (NULL);
	room1 = ft_strdup(line);
	room2 = ft_strcutuntil(&room1, '-');
	connection->id_room1 = get_room_id(rooms, room1);
	if (connection->id_room1 == BAD_ROOM_ID)
	{
		destroy_connection(&connection);
		return (NULL);
	}
	connection->id_room2 = get_room_id(rooms, room2);
	if (connection->id_room2 == BAD_ROOM_ID)
		destroy_connection(&connection);
	return (connection);
}
