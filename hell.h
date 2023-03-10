#ifndef HELL_H
# define HELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "libft/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_tokens
{
	char			*token;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	// struct s_lexer	*pre;
}	t_lexer;

t_lexer	g_lexer;

int	is_space(char c);
int	is_tokens(char c);

#endif