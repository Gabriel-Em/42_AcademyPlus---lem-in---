/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:31:33 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:33:55 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dijkstra.h"

static int		**get_matrix(int lines, int columns)
{
	int **mat;
	int	i;

	if (!(mat = (int**)malloc(sizeof(int*) * lines)))
		return (NULL);
	i = 0;
	while (i < lines)
	{
		mat[i] = (int*)malloc(sizeof(int) * columns);
		i++;
	}
	return (mat);
}

static void		destroy_classic_matrix(int ***mat, int lines)
{
	int i;

	if (mat && *mat)
	{
		i = 0;
		while (i < lines)
		{
			if ((*mat)[i])
				free((*mat)[i]);
			i++;
		}
		free(*mat);
		*mat = NULL;
	}
}

static void		init_dobj(DOBJ *dobj, PMATRIX matrix)
{
	int i;
	int j;

	dobj->nextnode = 0;
	dobj->cost = get_matrix(matrix->number_of_rooms, matrix->number_of_rooms);
	dobj->distance = (int*)malloc(sizeof(int) * matrix->number_of_rooms);
	dobj->visited = (int*)malloc(sizeof(int) * matrix->number_of_rooms);
	i = -1;
	while (++i < matrix->number_of_rooms)
	{
		j = -1;
		while (++j < matrix->number_of_rooms)
			if (matrix->connection_matrix[i][j] == TRUE)
				dobj->cost[i][j] = matrix->connection_matrix[i][j];
			else
				dobj->cost[i][j] = INFINITY;
	}
	i = -1;
	while (++i < matrix->number_of_rooms)
	{
		dobj->distance[i] = dobj->cost[matrix->destination_id][i];
		dobj->visited[i] = FALSE;
	}
}

static void		process_distance_array(DOBJ *dobj, PMATRIX matrix)
{
	int i;

	dobj->count = 1;
	dobj->distance[matrix->destination_id] = FALSE;
	dobj->visited[matrix->destination_id] = TRUE;
	while (dobj->count < matrix->number_of_rooms - 1)
	{
		dobj->mindistance = INFINITY;
		i = -1;
		while (++i < matrix->number_of_rooms)
			if (dobj->distance[i] < dobj->mindistance && !dobj->visited[i])
			{
				dobj->mindistance = dobj->distance[i];
				dobj->nextnode = i;
			}
		dobj->visited[dobj->nextnode] = TRUE;
		i = -1;
		while (++i < matrix->number_of_rooms)
			if (!dobj->visited[i])
				if (dobj->mindistance + dobj->cost[dobj->nextnode][i]
						< dobj->distance[i])
					dobj->distance[i] = dobj->mindistance
						+ dobj->cost[dobj->nextnode][i];
		dobj->count++;
	}
}

int				*get_cost_array(PMATRIX matrix)
{
	DOBJ	dobj;

	init_dobj(&dobj, matrix);
	process_distance_array(&dobj, matrix);
	destroy_classic_matrix(&(dobj.cost), matrix->number_of_rooms);
	free(dobj.visited);
	return (dobj.distance);
}
