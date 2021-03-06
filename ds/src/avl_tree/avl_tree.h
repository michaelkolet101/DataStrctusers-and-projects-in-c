#include <stdlib.h>

#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

typedef enum 
{
	PREORDER,
	INORDER,
	POSTORDER
}tree_travel_ty;

typedef struct avl_tree avl_tree_ty;
typedef struct avl_node avl_node_ty;

typedef void(*op_func_ty)(void *param);

typedef int(*is_mach_ty)(void *elem1 , void *elem2);

typedef int(*avl_cmp_fnc_ty)(const void *elem1,
                             const void *elem2,
                             const void *param);
                             
                             
avl_tree_ty *AVLCreate(avl_cmp_fnc_ty cmp_fnc, const void *cmp_param);	

void AVLDestroy(avl_tree_ty *avl_tree);

int AVLRemove(avl_tree_ty *tree, const void *key_to_remove);


int AVLInsert(avl_tree_ty *tree_,  void *element_to_insert_);

size_t AVLHeight(const avl_tree_ty *tree);

size_t AVLSize(const avl_tree_ty *tree);

int AVLIsEmpty(const avl_tree_ty *tree);

void *AVLFind(const avl_tree_ty *tree, const void *key);

int AVLForEach(avl_tree_ty *tree,
					   op_func_ty op_func,
					   void *op_param,
					   tree_travel_ty travel_type);

size_t AVLRemoveMultiple(avl_tree_ty *tree,
                        is_mach_ty,
                        const void *param);

#endif /* __AVL_TREE_H__ */
