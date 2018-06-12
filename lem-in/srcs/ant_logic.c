/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:59:09 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:25:08 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_logic.h"

static int	decide_move(int new_room_id, int lowest_cost,
		int absolute_lowest_cost, int ants_in_source)
{
	if (new_room_id != BAD_ROOM_ID)
	{
		if (lowest_cost == absolute_lowest_cost)
			return (new_room_id);
		if (lowest_cost > ants_in_source)
			new_room_id = BAD_ROOM_ID;
	}
	return (new_room_id);
}

int			move_ant(const int *ant_status, const int *room_status,
				int ant_id, PMATRIX matrix)
{
	int new_room_id;
	int lowest_cost;
	int i;
	int absolute_lowest_cost;

	absolute_lowest_cost = INFINITY;
	lowest_cost = INFINITY;
	new_room_id = BAD_ROOM_ID;
	i = -1;
	while (++i < matrix->number_of_rooms)
		if (i != matrix->source_id
			&& matrix->connection_matrix[ant_status[ant_id]][i])
		{
			if (matrix->costs[i] < absolute_lowest_cost)
				absolute_lowest_cost = matrix->costs[i];
			if (i == matrix->destination_id || room_status[i] == EMPTY_ROOM)
				if (matrix->costs[i] < lowest_cost)
				{
					lowest_cost = matrix->costs[i];
					new_room_id = i;
				}
		}
	return (decide_move(new_room_id, lowest_cost, absolute_lowest_cost,
						room_status[matrix->source_id]));
}
