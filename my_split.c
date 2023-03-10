/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/10 16:26:03 by wluedara         ###   ########.fr       */
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
		if (is_tokens(s[i]) != -1)
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

// int	count_letter(char *s)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i] != '\0' && s[i] )
// 	{
// 		if (s[i] )
// 			i++;
// 	}
// 	return (i);
// }

// char	*my_split(char *s )
// {
// 	char	*str;
// 	int		letter;
// 	int		i;
// 	int		j;

// 	letter = count_letter(s);
// 	str = (char *)malloc(sizeof(char) * (letter + 1));
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	while (s[j] != 0 && s[j] != )
// 		str[i++] = s[j++];
// 	str[i] = '\0';
// 	return (str);
// }

char	**cut_cmd(char *s)
{
	char	**new;
	int		word;
	// int		i;
	// int		j;

	// i = 0;
	word = check_word(s);
	printf(YEL"word = %d\n", word);
	new = (char **)malloc(sizeof(char *) * (word + 1));
	if (!new)
		return (0);
	// j = 0;
	// while (i < word)
	// {
	// 	while (s[j] != '\0')
	// 		j++;
	// 	new[i++] = my_split(&s[j]);
	// 	j += count_letter(&s[j]);
	// }
	// new[i] = 0;
	// return (new);
	return (0);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**new;
	
	while(1)
	{
		str = readline(RED"mini(s)hell>> "RESET);
		printf(YEL"Readline = %s\n"RESET, str);
		new = cut_cmd(str);
		// for(int i = 0; new[i]; i++)
		// {
		// 	printf(MAG"new[%d] = %s\n"RESET, i, new[i]);
		// }
	}
}
