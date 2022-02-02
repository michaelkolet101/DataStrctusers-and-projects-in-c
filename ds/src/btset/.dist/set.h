
#ifndef __SET_H__
#define __SET_H__


typedef struct set set_ty;
typedef struct node node_ty;
typedef struct iterator iterator_ty;

struct iterator
{
	node_ty *set_node;
};
/***************************************************************/

iterator_ty SetInsert(set_ty *set ,int(*cmp_func)(const void *data1, const void *data2));

/*return the next*/
iterator_ty RmoveFromSet(set_ty *set, iterator_ty to_delete);

iterator_ty Next(iterator_ty itr);

iterator_ty Prev(iterator_ty itr);

iterator_ty Begin(set_ty *set);

iterator_ty End(set_ty *set);

#endif /*__SET_H__*/
