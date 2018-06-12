/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:39:59 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 15:34:45 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void			destroy_matrix(PMATRIX *matrix)
{
	int i;

	if (matrix && *matrix)
	{
		if ((*matrix)->connection_matrix)
		{
			i = 0;
			while (i < (*matrix)->number_of_rooms)
			{
				if ((*matrix)->connection_matrix[i])
					free((*matrix)->connection_matrix[i]);
				i++;
			}
			free((*matrix)->connection_matrix);
		}
		if ((*matrix)->costs)
			free((*matrix)->costs);
		free(*matrix);
		*matrix = NULL;
	}
}

static void		set_connection(PLIST node, PMATRIX matrix)
{
	if (NODE_TO_CONNECTION(node)->id_room2 != matrix->source_id ||
		(NODE_TO_CONNECTION(node)->id_room1 == matrix->destination_id
		&& NODE_TO_CONNECTION(node)->id_room2 == matrix->source_id))
		matrix->connection_matrix[NODE_TO_CONNECTION(node)->id_room1]
		[NODE_TO_CONNECTION(node)->id_room2] = TRUE;
	if (NODE_TO_CONNECTION(node)->id_room1 != matrix->source_id ||
		(NODE_TO_CONNECTION(node)->id_room2 == matrix->destination_id
		&& NODE_TO_CONNECTION(node)->id_room1 == matrix->source_id))
		matrix->connection_matrix[NODE_TO_CONNECTION(node)->id_room2]
		[NODE_TO_CONNECTION(node)->id_room1] = TRUE;
}

static void		fill_matrix(PLIST connections, PMATRIX matrix)
{
	int		i;
	int		j;
	PLIST	node;

	i = -1;
	while (++i < matrix->number_of_rooms)
	{
		j = -1;
		while (++j < matrix->number_of_rooms)
			matrix->connection_matrix[i][j] = FALSE;
	}
	node = connections;
	while (node)
	{
		set_connection(node, matrix);
		node = node->next;
	}
}

BOOL			check_destination_reachable(PMATRIX matrix)
{
	int i;

	i = 0;
	while (i < matrix->number_of_rooms)
	{
		if (matrix->connection_matrix[matrix->source_id][i] == TRUE)
			if (matrix->costs[i] != INFINITY)
				return (TRUE);
		i++;
	}
	return (FALSE);
}

PMATRIX			create_matrix(PLIST rooms, PLIST connections)
{
	PMATRIX			matrix;
	int				i;

	if (!(matrix = (PMATRIX)malloc(sizeof(MATRIX))))
		return (NULL);
	matrix->number_of_rooms = ft_lstlen(rooms);
	if (!(matrix->connection_matrix = (int**)malloc(sizeof(int*)
					* matrix->number_of_rooms)))
	{
		destroy_matrix(&matrix);
		return (NULL);
	}
	i = 0;
	while (i < matrix->number_of_rooms)
		matrix->connection_matrix[i++] = (int*)malloc(sizeof(int)
				* matrix->number_of_rooms);
	matrix->source_id = get_id_of_source(rooms);
	matrix->destination_id = get_id_of_destination(rooms);
	fill_matrix(connections, matrix);
	matrix->costs = NULL;
	return (matrix);
}
