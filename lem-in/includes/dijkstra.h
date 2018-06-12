/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:46:40 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:46:41 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIJKSTRA_H
# define DIJKSTRA_H

# include "matrix.h"
# include "libft.h"

typedef	struct	s_dijkstra_objects
{
	int			**cost;
	int			*distance;
	int			*visited;
	int			count;
	int			mindistance;
	int			nextnode;
}				t_dijkstra_objects;

int				*get_cost_array(PMATRIX matrix);

# define DOBJ	t_dijkstra_objects

#endif
