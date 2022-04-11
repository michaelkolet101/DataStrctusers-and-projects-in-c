#include "btset.h"

struct binary_tree_node
{
    void *data;
    bt_node_ty *left;
    bt_node_ty *right;
    bt_node_ty *parent;
};

struct binary_tree_set
{
    bt_node_ty *root;
};