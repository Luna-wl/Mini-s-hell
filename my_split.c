/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/12 00:04:40 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

int	check_word(char *s)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (is_tokens(s[i]) != -1 && is_tokens(s[i + 1]) == -1)
			count++;
		if (is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && s[i]) //no space and tokens
		{
			while (is_space(s[i]) == 0 && is_tokens(s[i]) == -1 && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

int	count_letter2(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_space(s[i]) == 0)
	{
		if (is_space(s[i]) == 0)
			i++;
	}
	return (i);
}

int	count_letter(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_space(s[i]) == 0)
	{
		if (is_space(s[i]) == 0)
			i++;
	}
	return (i);
}

char	*my_split(char *s)
{
	char	*str;
	char	*s2;
	int		letter;
	int		i;
	int		j;

	s2 = ft_strtrim(s, " ");
	letter = count_letter2(s2);
	// printf(CYN"letter = %d\n", letter);
	str = (char *)malloc(sizeof(char) * (letter + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s2[j] != 0 && is_space(s2[i]) == 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	**cut_cmd(char *s)
{
	char	**new;
	int		word;
	int		i;
	int		j;
	int		letter;

	word = check_word(s);
	printf(YEL"word = %d\n", word);
	new = (char **)malloc(sizeof(char *) * (word + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	letter = 0;
	while (i < word)
	{
		while (is_space(s[i]) != 0 && s[j] != '\0')
			j++;
		new[i++] = my_split(&s[j]);
		printf(BLU"letter = %d\n"RESET, letter);
		letter = count_letter(&s[j]);
		j += letter;
	}
	new[i] = NULL;
	return (new);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**new;
	
	while(1)
	{
		str = readline(RED"mini(s)hell>> "RESET);
		new = cut_cmd(str);
		for(int i = 0; new[i]; i++)
		{
			printf(MAG"new[%d] = %s\n"RESET, i, new[i]);
		}
	}
}

// # echo hello world|echo hello| echo ". hello "|ls| echo "'hello'"""
// -> Parser Sent to expander
// # {echo), {hello}, (world), NULL,
// # {echo), {hello}, NULL,
// # {echo), {". hello "}, NULL,
// # {ls), NULL,
// # (echo), ("'hello'"), (""), NULL.
// if '' / "" not complete pair return ERROR in lexer.