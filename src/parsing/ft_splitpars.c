/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitpars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:42:05 by phkevin           #+#    #+#             */
/*   Updated: 2024/08/27 15:54:03 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	static int	countsection(char const *s, char c)
 * </summary>
 *
 * <description>
 *	ft_countword count all section in a string. eatch section are separated by
 *	the char c.
 * </description>
 *
 * <param type="char cont *" name="s">string to evaluate</param>
 * <param type="char" name="c">char of separation of section</param>
 *
 * <return>
 *	number of section in the string.
 * </return>
 *
 */

static int	countsection(char const *s, char const c)
{
	int	section;
	int	i;

	section = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] == c && s[i + 1] == c)
				i +=2;
		}
		if (s[i] && s[i] != c)
		{
			section++;
			while (s[i] && (s[i] != c || (s[i] == c && s[i + 1] == c)))
			{
				i++;
				if (s[i] == c && s[i + 1] == c)
					i +=2;
			}
		}
	}
	return (section);
}

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	static char	*ft_malloc_row(char const s, char c)
 * </summary>
 *
 * <description>
 * 	ft_malloc_row allocate memory for a section of string ans copy the section
 * 	to this pointer.
 * </description>
 *
 * <param type="char const *" name="s">string to cut in section</param>
 * <param type="char" name="c">char separator of section</param>
 *
 * <return>
 *	a pointer allocated with the section copyed in area memory.
 * </return>
 *
 */

static char	*ft_malloc_row(int refrow, char const *s, char c)
{
	char	*row;
	int		index;
	int		i;

	index = 0;
	while (s[index] && (s[index] != c || (s[index] == c && s[index + 1] == c)))
	{
		index++;
		if (s[index] == c && s[index + 1] == c)
			index +=2;
	}
	row = (char *)malloc((index + 1) * sizeof(char));
	if (!row)
		return (NULL);
	index = 0;
	i = 0;
	if (refrow > 0 && s[index] == ' ')
		index++;
	while (s[index] && (s[index] != c || (s[index] == c && s[index + 1] == c)))
	{
		if (s[index] == c && s[index + 1] == c)
			row[i++] = s[index++];
		row[i++] = s[index++];
	}
	row[i] = 0;
	return (row);
}

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	**ft_split(char const *s, char c)
 * </summary>
 *
 * <description>
 * 	ft_split cut a string at eatch char c and save eatch little sting in an
 * 	array.
 * </description>
 *
 * <param type="char const *" name="s">string to split</param>
 * <param type="char" name="c">char of split</param>
 *
 * <return>
 * 	creat and allocate an array of strings and terminate by NULL.
 * </return>
 *
 */

char	**ft_splitpars(char const *s, char c)
{
	char	**array;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((countsection(s, c) + 1) * sizeof (char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
		{
			s++;
			if (*s == c && *(s + 1) == c)
				s += 2;	
		}
		if (*s && *s != c )
		{
			array[index] = ft_malloc_row(index, s, c);
			if (!array)
				return (ft_free_array(array));
			index++;
			while (*s && *s != c)
			{
				s++;
				if (*s == c && *(s + 1) == c)
					s += 2;
			}
		}
	}
	array[index] = NULL;
	return (array);
}
