/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:48:23 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 15:26:41 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"
#include "output_parser.h"
#include "dijkstra.h"

static int	cleanup_and_exit(PANTHILL anthill, PMATRIX matrix, int status)
{
	if (status == EXIT_FAILURE)
		ft_putendl(ERR_MESSAGE);
	destroy_anthill(&anthill);
	destroy_matrix(&matrix);
	return (status);
}

int			main(void)
{
	int			number_of_ants;
	PANTHILL	anthill;
	PMATRIX		matrix;

	anthill = NULL;
	matrix = NULL;
	number_of_ants = get_number_of_ants();
	if (number_of_ants == BAD_NUMBER_OF_ANTS_INPUT)
		return (cleanup_and_exit(anthill, matrix, EXIT_FAILURE));
	anthill = read_anthill();
	matrix = create_matrix(anthill->rooms, anthill->connections);
	if (!matrix || matrix->source_id == BAD_ROOM_ID
		|| matrix->destination_id == BAD_ROOM_ID)
		return (cleanup_and_exit(anthill, matrix, EXIT_FAILURE));
	matrix->costs = get_cost_array(matrix);
	if (!check_destination_reachable(matrix))
		return (cleanup_and_exit(anthill, matrix, EXIT_FAILURE));
	generate_output(anthill, matrix, number_of_ants);
	return (cleanup_and_exit(anthill, matrix, EXIT_SUCCESS));
}
