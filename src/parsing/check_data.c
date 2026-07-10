/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:46:38 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 09:27:20 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	add_str(char **dest, char *src, int i, t_param param)
{
	int	end;

	i += 2;
	if (!ft_isspace(src[i]))
		free_error(src, param, NULL, INPUT);
	while (src[i] && ft_isspace(src[i]))
		i++;
	end = i;
	while (src[i] && !ft_isspace(src[end]))
		end++;
	*dest = ft_substr(src, i, end - i);
	free(src);
	if (!dest)
		free_error(NULL, param, NULL, MALLOC);
}

static int	next_number(char *src, int *i, t_param param)
{
	int		nb;
	int		j;
	char	*str;

	j = *i;
	while (src[*i] && !(ft_isspace(src[*i]) || src[*i] == ','))
		(*i)++;
	str = ft_substr(src, j, *i - j);
	if (!str)
		free_error(src, param, NULL, MALLOC);
	j = 0;
	while (str[j] && ft_isdigit(str[j]))
		j++;
	if (str[j] != '\0' || ft_atoi(str, &nb))
	{
		free(str);
		free_error(src, param, NULL, INPUT);
	}
	free(str);
	while (src[*i] && (ft_isspace(src[*i]) || src[*i] == ','))
		(*i)++;
	return (nb);
}

static void	add_int(int **dest, char *src, int i, t_param param)
{
	int	n;

	if (!ft_isspace(src[i + 1]))
		free_error(src, param, NULL, INPUT);
	*dest = malloc(sizeof(**dest) * 3);
	if (!(*dest))
		free_error(src, param, NULL, MALLOC);
	i++;
	while (src[i] && ft_isspace(src[i]))
		i++;
	n = 0;
	while (n < 3)
		(*dest)[n++] = next_number(src, &i, param);
	free(src);
}

static int	add_data(char *str, t_data *data, t_param param)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!data->no && !ft_memcmp(&str[i], "NO", 2))
		add_str(&data->no, str, i, param);
	else if (!data->so && !ft_memcmp(&str[i], "SO", 2))
		add_str(&data->so, str, i, param);
	else if (!data->we && !ft_memcmp(&str[i], "WE", 2))
		add_str(&data->we, str, i, param);
	else if (!data->ea && !ft_memcmp(&str[i], "EA", 2))
		add_str(&data->ea, str, i, param);
	else if (!data->f && !ft_memcmp(&str[i], "F", 1))
		add_int(&data->f, str, i, param);
	else if (!data->c && !ft_memcmp(&str[i], "C", 1))
		add_int(&data->c, str, i, param);
	else
	{
		free(str);
		return (1);
	}
	return (0);
}

int	check_data(t_param *param, t_data *data)
{
	int		start;
	int		end;
	char	*str;

	param->data = data;
	start = 0;
	while (1)
	{
		end = next_line(param->file, start);
		if (end == -1)
			break ;
		if (!empty_line(param->file, start, end))
		{
			str = ft_substr(param->file, start, end - start + 1);
			if (!str)
				free_error(NULL, *param, NULL, MALLOC);
			if (add_data(str, data, *param))
				break ;
		}
		start = end + 1;
	}
	return (start);
}
