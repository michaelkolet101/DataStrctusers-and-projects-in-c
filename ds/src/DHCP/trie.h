#ifndef __TRIE_H__
#define __TRIE_H__

typedef struct trie trie_ty;


trie_ty *TrieCreate(unsigned int num_bit_address);

unsigned long int TrieNewAdders(trie_ty *trie, unsigned long int req_address);


void UpdateFullness(unsigned long int req_address_, unsigned int num_bits_, node_ty *node_);


#endif /*__TRIE_H__*/