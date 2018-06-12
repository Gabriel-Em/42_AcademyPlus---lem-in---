/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:47:56 by gpop              #+#    #+#             */
/*   Updated: 2018/06/12 14:45:16 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSER_H
# define INPUT_PARSER_H

# include "libft.h"
# include "lem_in_objects.h"
# include "anthill.h"

# define TYPE_CONNECTION	2
# define TYPE_COMMENT		3
# define TYPE_END			5

# define IS_COMMENT(X)		((X)[0] == '#')
# define IS_COMMAND(X)		((X)[0] == '#' && (X)[1] == '#')
# define IS_CONNECTION(X)	(ft_strstr((X), "-") != NULL)
# define IS_START(X)		(ft_strstr((X), "start") != NULL)
# define IS_END(X)			(ft_strstr((X), "end") != NULL)

# define BAD_NUMBER_OF_ANTS_INPUT (-1)

int			get_number_of_ants();
PANTHILL	read_anthill();

#endif
