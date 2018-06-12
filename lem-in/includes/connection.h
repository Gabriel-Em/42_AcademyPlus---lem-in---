/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:58:51 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:47:11 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECTION_H
# define CONNECTION_H

# include "lem_in_objects.h"
# include "libft.h"
# include "room.h"

typedef struct	s_connection
{
	int			id_room1;
	int			id_room2;
}				t_connection;

# define CONNECTION		t_connection
# define PCONNECTION	CONNECTION*

# define NODE_TO_CONNECTION(X)	(((PCONNECTION)(X)->content))

PCONNECTION		create_connection(char *line, PLIST rooms);
void			destroy_connection(PCONNECTION *connection);

#endif
