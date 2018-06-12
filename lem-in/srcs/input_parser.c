/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:47:42 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 16:06:47 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"

int			get_number_of_ants(void)
{
	char	*line;
	int		number_of_ants;

	line = NULL;
	number_of_ants = 0;
	get_next_line(0, &line);
	if (line)
	{
		if (!ft_isnumeric_str(line))
		{
			ft_strdel(&line);
			return (BAD_NUMBER_OF_ANTS_INPUT);
		}
		number_of_ants = ft_atoi(line);
		ft_strdel(&line);
	}
	if (number_of_ants < 1)
		return (BAD_NUMBER_OF_ANTS_INPUT);
	return (number_of_ants);
}

static BOOL	get_type_of_input(char **line)
{
	int ret;
	int len;

	*line = NULL;
	ret = get_next_line(0, line);
	if (ret == GNL_EMPTY_LINE || ret == GNL_ERROR)
		return (TYPE_END);
	len = (int)ft_strlen(*line);
	if (len > 0 && IS_COMMENT(*line))
	{
		if (len > 1 && IS_COMMAND(*line))
		{
			if (IS_START(*line))
				return (TYPE_ORIGIN);
			else if (IS_END(*line))
				return (TYPE_DESTINATION);
		}
		return (TYPE_COMMENT);
	}
	else if (IS_CONNECTION(*line))
		return (TYPE_CONNECTION);
	else
		return (TYPE_NORMAL);
	return (TYPE_END);
}

static BOOL	get_room(PANTHILL anthill, char **line, BOOL type)
{
	PROOM room;

	room = create_room(line, type, ft_lstlen(anthill->rooms), anthill->rooms);
	if (!room)
		return (FALSE);
	add_room(anthill, room);
	return (TRUE);
}

static BOOL	get_connection(PANTHILL anthill, char *line)
{
	PCONNECTION connection;

	connection = create_connection(line, anthill->rooms);
	if (!connection)
		return (FALSE);
	add_connection(anthill, connection);
	return (TRUE);
}

PANTHILL	read_anthill(void)
{
	char		*line;
	BOOL		type;
	BOOL		reading_rooms;
	PANTHILL	anthill;
	BOOL		previous_type;

	anthill = init_anthill();
	reading_rooms = TRUE;
	previous_type = FALSE;
	while ((type = get_type_of_input(&line)) != TYPE_END)
	{
		if (type == TYPE_CONNECTION)
		{
			reading_rooms = FALSE;
			if (!get_connection(anthill, line))
				break ;
		}
		else if (type == TYPE_NORMAL
				&& (!reading_rooms || !get_room(anthill, &line, previous_type)))
			break ;
		ft_strdel(&line);
		previous_type = type;
	}
	ft_strdel(&line);
	return (anthill);
}
