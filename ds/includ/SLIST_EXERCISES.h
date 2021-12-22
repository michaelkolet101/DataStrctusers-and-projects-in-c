#ifndef __SLIST_EXERCISES_H__
#define __SLIST_EXERCISES_H__

typedef struct node node_t;


/* Reverses the order of a given slist */
node_t *Flip(node_t *head);

/* Tells whether a given slist has loop */
int HasLoop(const note_t *head);

/*Returns a pointer to a first node mututal to both slists, if any */
node_t *FindIntersection(node_t *head1, node_t *head2);


#endif /* __SLIST_EXERCISES_H__ */



