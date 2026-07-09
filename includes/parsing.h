/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:42:38 by julauren          #+#    #+#             */
/*   Updated: 2026/07/04 15:29:29 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3D.h"
# include "../libft/libft.h"
// # include <fcntl.h>
# include <stdlib.h>

typedef enum e_error
{
	MALLOC
}	t_error;


void	free_struct(t_data data, char **tab);

/*====================error====================*/

void	error_parsing(t_error error);

#endif
