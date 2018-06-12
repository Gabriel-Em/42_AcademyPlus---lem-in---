/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:59:25 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:47:52 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_PARSER_H
# define OUTPUT_PARSER_H

# include "anthill.h"
# include "matrix.h"
# include "libft.h"
# include "ant_logic.h"

typedef struct	s_status
{
	int			*ant_status;
	int			*room_status;
}				t_status;

# define ERR_MESSAGE	"ERROR"
# define STATUS			t_status

void			generate_output(PANTHILL anthill, PMATRIX matrix,
		int number_of_ants);

#endif
