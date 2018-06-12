/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:59:20 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:43:06 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_parser.h"

static void	init_room_and_ant_status(STATUS *status,
		PLIST rooms, int number_of_ants)
{
	int i;
	int number_of_rooms;
	int	id_of_source;

	status->room_status = NULL;
	status->ant_status = NULL;
	number_of_rooms = ft_lstlen(rooms);
	if (!(status->room_status = (int*)malloc(sizeof(int) * number_of_rooms)))
		return ;
	if (!(status->ant_status = (int*)malloc(sizeof(int) * number_of_ants)))
		return ;
	i = 0;
	while (i < number_of_rooms)
		(status->room_status)[i++] = 0;
	id_of_source = get_id_of_source(rooms);
	(status->room_status)[id_of_source] = number_of_ants;
	i = 0;
	while (i < number_of_ants)
		(status->ant_status)[i++] = id_of_source;
}

static void	update(STATUS *status, int ant_id, int new_room_id)
{
	status->room_status[status->ant_status[ant_id]]--;
	status->ant_status[ant_id] = new_room_id;
	status->room_status[new_room_id]++;
}

static void	print_update(int ant_id, int new_room_id, PLIST rooms,
		int number_of_ants_displayed)
{
	if (number_of_ants_displayed != 0)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(ant_id + 1);
	ft_putchar('-');
	ft_putstr(get_room_name(new_room_id, rooms));
}

static BOOL	process_ants(STATUS *status, PMATRIX matrix, int number_of_ants,
		PLIST rooms)
{
	int		ant;
	int		number_of_ants_displayed;
	int		new_room_id;
	BOOL	finished;

	finished = TRUE;
	ant = 0;
	number_of_ants_displayed = 0;
	while (ant < number_of_ants)
	{
		if (status->ant_status[ant] != matrix->destination_id)
		{
			new_room_id = move_ant(status->ant_status, status->room_status,
					ant, matrix);
			if (new_room_id != BAD_ROOM_ID)
			{
				update(status, ant, new_room_id);
				print_update(ant, new_room_id, rooms, number_of_ants_displayed);
				number_of_ants_displayed++;
				finished = FALSE;
			}
		}
		ant++;
	}
	return (finished);
}

void		generate_output(PANTHILL anthill, PMATRIX matrix,
		int number_of_ants)
{
	STATUS	status;
	BOOL	finished;

	init_room_and_ant_status(&status, anthill->rooms, number_of_ants);
	if (status.room_status == NULL || status.ant_status == NULL)
		return ;
	finished = FALSE;
	while (!finished)
	{
		finished = process_ants(&status, matrix, number_of_ants,
				anthill->rooms);
		if (!finished)
			ft_putchar('\n');
	}
}
