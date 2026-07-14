/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:01:09 by julauren          #+#    #+#             */
/*   Updated: 2026/07/14 10:06:10 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	error_parsing(t_error error)
{
	if (error == MALLOC)
		ft_putstr_fd("Error: Memory allocation failure.\n", 2);
	else if (error == FILES)
		ft_putstr_fd("Error: Memory allocation or file descriptor \
failure.\n", 2);
	else if (error == EMPTY)
		ft_putstr_fd("Error: Empty file.\n", 2);
	else if (error == INPUT)
		ft_putstr_fd("Error: Wrong Input.\n", 2);
	else if (error == MISSING)
		ft_putstr_fd("Error: Missing argument(s).\n", 2);
	else if (error == EMPTY_LINE)
		ft_putstr_fd("Error: Empty line is forbidden in the map.\n", 2);
	else if (error == MAP)
		ft_putstr_fd("Error: Invalid map.\n", 2);
	else if (error == PLAYER)
		ft_putstr_fd("Error: Invalid number of player.\n", 2);
	exit(EXIT_FAILURE);
}
