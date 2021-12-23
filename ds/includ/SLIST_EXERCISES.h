#ifndef __SLIST_EXERCISES_H__
#define __SLIST_EXERCISES_H__

typedef struct node
{
    void *data;
    struct node *next;
}node_ty;

/* Reverses the order of a given slist */
node_ty *Flip(node_ty *head);

/* Tells whether a given slist has loop */
int HasLoop(const node_ty *head);

/*Returns a pointer to a first node mututal to both slists, if any */
node_ty *FindIntersection(node_ty *head1, node_ty *head2);

/************/
/************/
#endif /* __SLIST_EXERCISES_H__ */



