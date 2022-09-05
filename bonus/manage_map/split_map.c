/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:57:27 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:57:32 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static char	*ft_free(char **liste)
{
	unsigned int	i;

	i = 0;
	while (liste[i])
	{
		free(liste[i]);
		i++;
	}
	free(liste);
	return (NULL);
}

static int	check_sep(char stri)
{
	if (stri == '\n')
		return (1);
	return (0);
}

static char	*get_word(char const *str, t_main *main, int i, char **liste)
{
	char	*dest;
	int		j;

	j = 0;
	while (str[i + j] && !(check_sep(str[i + j])))
		j++;
	dest = (char *)malloc(sizeof(char) * main->c_map->linesizemax + 1);
	if (!dest)
		return (ft_free(liste));
	j = 0;
	while (str[i + j] && !(check_sep(str[i + j])))
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	size_list(char const *str)
{
	int	i;
	int	count;

	if (*str == '\0')
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (check_sep(str[i])))
			i++;
		if (str[i] && !(check_sep(str[i])))
		{
			count++;
			while (str[i] && !(check_sep(str[i])))
				i++;
		}
	}
	return (count);
}

char	**ft_split_map(t_main *main, char const *str)
{
	int		i;
	int		p;
	char	**liste;

	i = 0;
	p = 0;
	liste = (char **)malloc(sizeof(char *) * (size_list(str) + 1));
	if (!liste)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (check_sep(str[i])))
			i++;
		if (str[i] && !(check_sep(str[i])))
		{
			liste[p] = get_word(str, main, i, liste);
			while (str[i] && !(check_sep(str[i])))
				i++;
			p++;
		}
	}
	liste[p] = 0;
	return (liste);
}
