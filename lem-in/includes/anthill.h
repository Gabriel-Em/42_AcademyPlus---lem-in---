/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:59:17 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:26:17 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTHILL_H
# define ANTHILL_H

# include "libft.h"
# include "lem_in_objects.h"
# include "room.h"
# include "connection.h"

typedef struct	s_anthill
{
	PLIST		rooms;
	PLIST		connections;
}				t_anthill;

# define ANTHILL		t_anthill
# define PANTHILL		t_anthill*

PANTHILL		init_anthill(void);
void			add_room(PANTHILL anthill, PROOM room);
void			add_connection(PANTHILL anthill, PCONNECTION connection);
void			destroy_anthill(PANTHILL *anthill);

#endif
