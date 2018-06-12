/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:40:03 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:46:58 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "lem_in_objects.h"
# include "connection.h"

typedef	struct	s_matrix
{
	int			**connection_matrix;
	int			*costs;
	int			number_of_rooms;
	int			source_id;
	int			destination_id;
}				t_matrix;

# define MATRIX		t_matrix
# define PMATRIX	MATRIX*
# define INFINITY	9999999

PMATRIX			create_matrix(PLIST rooms, PLIST connections);
void			destroy_matrix(PMATRIX *matrix);
BOOL			check_destination_reachable(PMATRIX matrix);

#endif
