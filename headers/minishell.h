/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:02:28 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/14 23:14:19 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// includes
# include "libft.h"
# include "readline/history.h"
# include "readline/readline.h"

typedef enum e_token_type
{
	T_WORD, // A Word
	T_PIPE, // |
	T_OR, // ||
	T_AND, // &&
	T_REDIR_IN, // <
	T_REDIR_OUT, // >
	T_REDIR_APPEND, // >>
	T_HERDOC, // <<
	T_PAREN_OPEN, // (
	T_PAREN_CLOSE, // )
	T_WILDCART, // *
	T_END, // END of line
}	t_token_type;

typedef struct s_token
{
	char			*val;
	t_token_type	type;
	struct	s_token	*next;
}	t_token;

void	lexer(char *line, t_token **tokens);

#endif // !MINISHELL_H
