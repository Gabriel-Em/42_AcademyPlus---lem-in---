/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:48:36 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:47:31 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_OBJECTS_H
# define LEM_IN_OBJECTS_H

# define TRUE				1
# define FALSE				0
# define BOOL				unsigned char

# define GNL_ERROR          (-1)
# define GNL_EMPTY_LINE     0

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

# define POINT				t_point
# define SPACE				' '

#endif
