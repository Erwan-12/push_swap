/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:27:03 by erwfonta          #+#    #+#             */
/*   Updated: 2024/05/27 12:25:23 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_lstclear(&new_list, del), NULL);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			free(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void *transform(void *ptr)
// {
// 	char *new_ptr;

// 	new_ptr = malloc(sizeof(char) * 2);
// 	new_ptr[0] = ((char *)ptr)[0] + 1;
// 	new_ptr[1] = 0;
// 	return((void*)new_ptr);
// }

// void	del(void *ptr)
// {
// 	if (ptr)
// 		free(ptr);
// }

// int main(void)
// {
// 	t_list *tmp;
// 	t_list *tmp2;
// 	t_list *item;
// 	char *t1, *t2, *t3, *t4;

// 	tmp = NULL;
// 	tmp2 = NULL;

// 	t1 = malloc(sizeof(char) * 2);
// 	t2 = malloc(sizeof(char) * 2);
// 	t3 = malloc(sizeof(char) * 2);
// 	t4 = malloc(sizeof(char) * 2);
// 	t1[0] = '1';
// 	t1[1] = 0;
// 	t2[0] = '2';
// 	t2[1] = 0;
// 	t3[0] = '3';
// 	t3[1] = 0;
// 	t4[0] = '4';
// 	t4[1] = 0;

// 	item = ft_lstnew(t1);
// 	ft_lstadd_back(&tmp, item);
// 	item = ft_lstnew(t2);
// 	ft_lstadd_back(&tmp, item);
// 	item = ft_lstnew(t3);
// 	ft_lstadd_back(&tmp, item);
// 	item = ft_lstnew(t4);
// 	ft_lstadd_back(&tmp, item);

// 	tmp2 = ft_lstmap(tmp, &transform, &del);
// 	if (!tmp2)
// 	{
// 		ft_lstclear(&tmp, &del);
// 		return (0);
// 	}

// 	t_list *temp = tmp;
// 	t_list *temp2 = tmp2;

// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	while (tmp2)
// 	{
// 		printf("%s\n", (char *)tmp2->content);
// 		tmp2 = tmp2->next;
// 	}

// 	ft_lstclear(&tmp2, &del);
// 	ft_lstclear(&tmp, &del);
// }