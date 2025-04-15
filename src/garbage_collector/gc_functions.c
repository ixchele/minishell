/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:42:42 by zbengued          #+#    #+#             */
/*   Updated: 2025/04/13 21:01:03 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbagecollector.h"

void	gc_init(t_GC *gc)
{
	gc->head = NULL;
}

void	*gc_malloc(t_GC *gc, size_t size)
{
	void		*ptr;
	t_gc_node	*node;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gc_node));
	if (!node)
	{
		free(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = gc->head;
	gc->head = node;
	return (ptr);
}

void	gc_free(t_GC *gc, void *ptr)
{
	t_gc_node	*prev;
	t_gc_node	*curr;

	prev = NULL;
	curr = gc->head;
	while (curr)
	{
		if (curr->ptr == ptr)
		{
			if (prev)
				prev->next = curr->next;
			else
				gc->head = curr->next;
			free(curr->ptr);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	write(2, "gc_free: free unkonwn pointer", 29);
}

void	gc_free_all(t_GC *gc)
{
	t_gc_node	*curr;
	t_gc_node	*next;

	curr = gc->head;
	while (curr)
	{
		next = curr->next;
		free(curr->ptr);
		free(curr);
		curr = next;
	}
	gc->head = NULL;
}
