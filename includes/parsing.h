/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:42:38 by julauren          #+#    #+#             */
/*   Updated: 2026/07/04 13:34:12 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_error
{
	FD,
	MALLOC
}	t_error;

typedef struct s_path
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}	t_path;

typedef struct s_color
{
	int	*F;
	int	*C;
}	t_color;


void	init_struct(t_path *path, t_color *color);
void	free_struct(t_path path, t_color color);

/*====================error====================*/

void	error_parsing(t_error error);

#endif
