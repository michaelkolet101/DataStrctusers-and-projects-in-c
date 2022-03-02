#ifndef __DHCP_H__
#define __DHCP_H__

typedef unsigned int ip_ty;
typedef struct trie_node trie_node_ty;
typedef struct dhcp dhcp_ty; 



dhcp_ty *DHCPCreate(ip_ty prefix ,unsigned long int num_bits_on);

ip_ty DHCPNewAddress(dhcp_ty *dhcp, ip_ty req_address);

int DHCPReleaseAddress(dhcp_ty *dhcp, ip_ty address_to_rel);

void DHCPDestroy(dhcp_ty *dhcp);

size_t DHCPCountAvailable(dhcp_ty *dhcp);

#endif /*__DHCP_H__*/