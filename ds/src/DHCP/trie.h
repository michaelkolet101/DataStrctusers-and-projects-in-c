#ifndef __TRIE_H__
#define __TRIE_H__

typedef struct trie trie_ty;


trie_ty *TrieCreate(unsigned int num_bit_address);

unsigned long int TrieNewAdders(trie_ty *trie, unsigned long int req_address);

unsigned long int DHCPNewAddress(trie_ty *dhcp, ip_ty req_address);

int DHCPReleaseAddress(trie_ty *dhcp, ip_ty address_to_rel);

void DHCPDestroy(trie_ty *dhcp);

size_t DHCPCountAvailable(trie_ty *dhcp);


#endif /*__TRIE_H__*/