/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:42:38 by julauren          #+#    #+#             */
/*   Updated: 2026/07/09 18:09:31 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3D.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef enum e_error
{
	MALLOC,
	INPUT
}	t_error;

typedef struct	s_param
{
	t_data	*data;
	char	*file;
}	t_param;

int		check_data(t_param param, t_data *data);

/*====================utils====================*/

void	free_struct(t_data *data, char **map);
int		empty_line(char *str, int start, int end);
int		next_line(char *str, int start);

/*====================error====================*/

void	error_parsing(t_error error);
void	free_error(char *str, t_param param, char **map, t_error error);

#endif
