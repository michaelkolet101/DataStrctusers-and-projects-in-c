#include <stdlib.h>

#ifndef __L_SORT_H__
#define __L_SORT_H__




void CountSort( int src_[],
                int dest_[],
                size_t size_, 
                int digit_lsb_idx_, 
                int num_bits_in_digit_, 
                size_t histogram_[]);




void RadixSort( int src[],
                int dest[],
                size_t size,
                int num_bits_in_digit,
                int lsb_idx,
                int num_significant_bits, 
                size_t histogram[]);



#endif /*__L_SORT_H__*/