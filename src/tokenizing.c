/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:32:41 by zbengued          #+#    #+#             */
/*   Updated: 2025/04/14 23:17:06 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void print_tokens(t_token *tokens)
{
    while (tokens)
    {
        printf("Type: %d", tokens->type);
        if (tokens->val)
            printf(" | Value: %s", tokens->val);
        printf("\n");
        tokens = tokens->next;
    }
}

bool	is_whitespace(char str)
{
	return (str == ' ' || str == '\t');
}

bool	char_in_arr(char c, char *arr)
{
	int (i) = 0;
	while (i)
	{
		if (c == arr[i])
			return (true);
		i++;
	}
	return (false);
}

void	add_token(t_token **head, t_token_type type, char *val)
{
	t_token	*new;
	t_token	*tmp;

	new = malloc(sizeof(t_token));
	// printf("%p\n", new);
	new->type = type;
	new->val = ft_strdup(val);
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
 * adslkfjasldkj
 * ;alkdsjf;lakdsjf
 * a;ldskfja;lskdjf
 *
*/

void	lexer(char *line, t_token **tokens)
{
	char	*word;

	int (start) = 0;
	int (i) = 0;
	while (line[i]) // echo 'njinbjnjn'"jkjnm'jnjklala a;skdjfh adskjfhalskj"''asdfkjasd;fklj | main.txt && ls -l 
	{
		if (line[i] && (line[i] == ' ' || line[i] == '\t'))
		{
			i++;
			continue;
		}
		else if (line[i] == '|' && line[i + 1] == '|')
		{
			add_token(tokens, T_OR, "||");
			i++;
		}
		else if (line[i] == '&' && line[i + 1] == '&')
		{
			add_token(tokens, T_AND, "&&");
			i++;
		}
		else if (line[i] == '|')
		{
			add_token(tokens, T_PIPE, "|");
			i++;
		}
		else if (line[i] == '>' && line[i + 1] == '>')
		{
			add_token(tokens, T_REDIR_APPEND, ">>");
			i++;
		}
		else if (line[i] == '<' && line[i + 1] == '<')
		{
			add_token(tokens, T_HERDOC, "<<");
			i++;
		}
		else if (line[i] == '<')
		{
			add_token(tokens, T_REDIR_IN, "<");
			i++;
		}
		else if (line[i] == '>')
		{
			add_token(tokens, T_REDIR_IN, ">");
			i++;
		}
		else if (line[i] == '(')
		{
			add_token(tokens, T_PAREN_OPEN, "(");
			i++;
		}
		else if (line[i] == ')')
		{
			add_token(tokens, T_PAREN_CLOSE, ")");
			i++;
		}
		else if (line[i] == '*')
		{
			add_token(tokens, T_WILDCART, "*");
			i++;
		}
		else
		{
			start = i;
			while (line[i] && !is_whitespace(line[i])
				&& !char_in_arr(line[i], "|&><()*"))
				i++;
			word = ft_strndup(&line[start], i - start);

			add_token(tokens, T_WORD, word);
			free(word);
		}
	}
	add_token(tokens, T_END, NULL);
}
