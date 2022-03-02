#include <stdlib.h>
#include "DHCP.h"
#include "trie.h"



struct trie_node
{
    trie_node_ty *m_children[2]; /*left 0 right 1*/
    unsigned int num_bits_on;
    int is_occupide;
    
} ;

struct dhcp
{
    trie_ty *m_root;
    ip_ty m_subnet_id;
};

static trie_node_ty CreateChildNode();
static ip_ty DHCPNewAddressIMP(dhcp_ty *dhcp, int mask);
static int IsBadIPIMP(ip_ty ip_);

dhcp_ty *DHCPCreate(ip_ty prefix, unsigned int num_bits_address)
{
	/* assert num_bits_address <= 64 */
	
	/* assert that in prefix the bits to the left are zeroed */
	
	/* create dhcp, check allocation */
	
	/* create trie, check allocation */
	
	/* initialize fields of dhcp */
	
	/* return dhcp */
}


void DHCPDestroy(dhcp_ty *dhcp)
{
	/* if NULL - return */
	
	/* destroy trie */
	
	/* Deadmeam */
	
	/* destroy dhcp */
}


ip_ty DHCPAllocateIP(dhcp_ty *dhcp, ip_ty req_address)
{
	/* assert(dhcp) */
	
    /* assert((m_subnet_id & req_address) == m_subnet_id) */
	
	/* right_add = TrieNewAddress(req_address ^ m_subnet_id) */
	
	/* if right_add is bad - return X.0.0.0.0 */
	
	/* return decp->m_subnet_id | right_add */
}


void DHCPReleaseAddress(dhcp_ty *dhcp, ip_ty address_to_rel)
{
	/* assert(dhcp) */
	/* assert TrieIsAddressExists(address_to_rel) */
	/* assert (0 == IsBadIPIMP(address_to_rel)) */
	
	/* TrieRelease */
}


size_t DHCPCountAvailable(dhcp_ty *dhcp_)
{
	/* assert dhcp */
	
	/* return TrieCountAvailable(dhcp_->m_trie); */
}


static int IsBadIPIMP(ip_ty ip_)
{
	/* return ip_ == X.0.0.0.0 */
}
