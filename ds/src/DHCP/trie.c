#include "trie.h"

typedef enum {FREE = 0, 
			  FULL = 1} bool_ty;

typedef enum {ZERO = 0,
			  ONE  = 1} bit_ty;

typedef struct
{
	node_ty *m_children[2];
	bool_ty m_is_full;
} node_ty;


typedef struct
{
	node_ty m_root;
	unsigned int m_num_bits;
} trie_ty;


trie_ty *TrieCreate(unsigned int num_bits_address_)
{
	/* assert (64 >= num_bits_address) */
	
	/* allocate space for the trie */
	/* check allocation, if bad - return NULL */
	
	/* trie.m_num_bits = num_bits_address_; */
	
	/* TrieNewAddress(0) */
	/* check if suceeded */
	
	/* return the trie */
}

static int CreateZeroesIMP(trie_ty *trie_)
{
	 /* assert(trie_) */
	 
	 /* unsigned int height_tree = trie_->m_num_bits */
	 
	 
	 /* while height_tree > 0 */
	 	/* create node */
	 	/* check allocation */
	 	/* create path of num_bits_address of zeros */
	/* mark the last leaf as full, the nodes above are free */
	/* check allocations */
}

unsigned long int TrieNewAddressIMP(trie_ty *trie_, unsigned long int req_address_)
{
	/* unsigned int num_bits = trie_->m_num_bits */
	/* int is_free = TrieIsAddressFreeIMP(req_address_, num_bits, &trie_->m_root) */
	/* int status = FAIL; */
	
	/* if (is_free) */
		/* status = AllocAddIMP(req_address_, num_bits, &&trie_->m_root); */
		/* if (FAIL == status)*/
		/* {*/
			 /*return FAIL;*/
		/* }*/
	/* else */
		/* req_address = NextFreeAddIMP(); */
		/* AllocAddIMP(req_address_, num_bits, &&trie_->m_root); */
		
	/* UpdateFullness(req_address_, num_bits, trie_->m_root) */
	/* return the req_address */
}


void UpdateFullness(unsigned long int req_address_, unsigned int num_bits_, node_ty *node_)
{
	bit_ty bit = GetBitIMP(req_address_, num_bits_);
	
	if (0 == num_bits_)
	{
		node_->m_is_full = FULL;
		return;
	}
	
	if(NULL != node_->m_children[!bit] && FULL == node_->m_children[!bit]->m_is_full)
	{
		node_->m_is_full = FULL;
	}
	else
	{
		node_->m_is_full = FREE;
	}
	
	UpdateFullness(req_address_, num_bits_ - 1, node_->m_children[bit]);
}


int TrieIsAddressFreeIMP(unsigned long int req_address_, unsigned int num_bits_, node_ty *node_)
{
	bit_ty bit = GetBitIMP(req_address_, num_bits_);	
	
	if (NULL == node_)
	{
		return 1;
	}
	
	if (0 == num_bits_)
	{
		return node_->m_is_full;
	}
		
	TrieIsAddressFree(req_address_, num_bits_ - 1, node_->m_children[bit]);
}
	

int AllocAddIMP(unsigned long int req_address_, unsigned int num_bits_, node_ty **node_)
{
	bit_ty bit = GetBitIMP(req_address_, num_bits_);
	int status = FAIL;
	
	if(NULL == *node_)
	{
		status = CreateNode(node_);
		
		if(FAIL == status)
		{
			return FAIL;
		}
	}
	
	if(0 == num_bits_)
	{
		return SUCCESS;
	}
	
	return AllocAddIMP(req_address_, num_bits_ - 1, &(*node_)->m_children[bit]);
}


int CreateNode(node_ty **node_)
{
	*node_ = (node_ty *)malloc(sizeof(node_ty));
		
	if(NULL == *node_)
	{
		return FAIL;
	}
	
	(*node_)->m_children[0] = NULL;
	(*node_)->m_children[1] = NULL;
	(*node_)->m_is_full = FREE;
	
	return SUCCESS;
}


bit_ty GetBitIMP(unsigned long int req_address_, unsigned int bit_idx_)
{
	return (req_address_ & (1 << (bit_idx_ - 1)) != ZERO;
}


TrieRelease()


TrieCountAvailable()
{
	/* count all the leafs that are occupied */
}

PostOrderIMP()
