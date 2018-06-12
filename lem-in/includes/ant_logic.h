/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_logic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:59:12 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:44:53 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANT_LOGIC_H
# define ANT_LOGIC_H

# include "matrix.h"
# include "lem_in_objects.h"

# define INFINITY		9999999
# define EMPTY_ROOM		0

int		move_ant(const int *ant_status, const int *room_status, int ant_id,
		PMATRIX matrix);
#endif
