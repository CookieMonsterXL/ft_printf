#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*new;

	if (!lst)
		return (NULL);
	head = NULL;
	new = ft_lstnew(f(lst->content));
	if (!(new))
		return (NULL);
	ft_lstadd_back(&head, new);
	tail = head;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&tail, new);
		lst = lst->next;
	}
	return (head);
}
