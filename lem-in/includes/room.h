/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:58:33 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:46:12 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include "lem_in_objects.h"
# include "libft.h"

typedef struct	s_room
{
	int			id;
	char		*name;
	POINT		coord;
	int			type;

}				t_room;

# define ROOM			t_room
# define PROOM			ROOM*

# define TYPE_ORIGIN		24
# define TYPE_DESTINATION	9
# define TYPE_NORMAL		98

# define BAD_ROOM_ID		(-1)
# define NODE_TO_ROOM(X)	((PROOM)((X)->content))
# define UNKNOWN_NAME		"UNKNOWN NAME"

PROOM			create_room(char **line, int type, int id, PLIST rooms);
void			destroy_room(PROOM *room);
int				get_room_id(PLIST rooms, char *name);
int				get_id_of_source(PLIST rooms);
int				get_id_of_destination(PLIST rooms);
char			*get_room_name(int id, PLIST rooms);

#endif
