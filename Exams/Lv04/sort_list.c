#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *curr;
	int	tmp;

	curr = lst
	while (curr->next)
	{
		if ((*cmp)(curr->data, curr->next->data) == 0)
		{
			tmp = curr->data;
			curr->data = curr->next->data;
			curr->next->data = tmp;
			curr = lst;
		}
		else
			curr = curr->next;
	}
	return (lst);
}
		
