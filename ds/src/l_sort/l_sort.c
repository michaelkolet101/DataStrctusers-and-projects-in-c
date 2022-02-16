#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "l_sort.h"

static void PrintArrIMP(int *arr, size_t len);
static int CreateMaskIMP(int num_,
                        int digit_lsb_idx_,
                        int num_bits_in_digit_);


void CountSort( int src_[],
                int dest_[],
                size_t size_, 
                int digit_lsb_idx_, 
                int num_bits_in_digit_, 
                int histogram_[] )
{
    /*variable declarations*/
    size_t histo_size = 1LU << num_bits_in_digit_;
    
    int *src_curr = src_;
    int *src_end = src_ + (size_ + sizeof(int));
    
    int *histo_curr = histogram_;
    int *histo_end =  histogram_ + ( 1 << num_bits_in_digit_);


    /*asserts*/
    assert(dest_);
    assert(histogram_);
    assert(0 <= digit_lsb_idx_);
    assert(0 < num_bits_in_digit_);
    
    

    /*for each number in src*/
    while (src_curr < src_end)
    { 
        /*map the appearance of the mask output to histogram*/
        int idx = CreateMaskIMP(*src_curr, digit_lsb_idx_, num_bits_in_digit_ );
        *(histogram_ + idx) += 1;
        ++src_curr;
    }


    /*for each number in histogram*/
    while ( histo_curr < histo_end )
    {
        /* accomulate curr value with his prev value */
        *histo_curr += *(histo_curr - 1);

        ++histo_curr;
    }

   
    /*for each number in src in reverse */
    while (src_curr < src_end)
    {
        int idx = CreateMaskIMP(*src_end,
                         digit_lsb_idx_, 
                         num_bits_in_digit_);

        /* copy num to dest at position histogram[masck num] */
        *(dest_ + *(histogram_ + idx)) = *src_end;
        
        /*decrement histogram[idx]*/
        *(histogram_ + idx) -= 1;
    
        --src_end;
    }

    

}


void RadixSort( int src_[],
                int dest_[],
                size_t size_,
                int num_bits_in_digit_,
                int lsb_idx_,
                int num_significant_bits_,
                int histogram_[])
{
    /* variable declarations */
    int *curr = src_;
    int last_digit = lsb_idx_ + num_significant_bits_;

    /* asserts */
    assert(src_);
    assert(dest_);
    assert(histogram_);

    /*for each digit in numbers */
    while ( lsb_idx_ < last_digit )
    {
        /* counting sort for current digit */
        CountSort(src_,
                    dest_,
                    size_,
                    lsb_idx_,
                    num_bits_in_digit_,
                    histogram_);
        
        /* copy the resukt back from dest to src */
        memcpy(src_, dest_, size_ * (sizeof(int)));

        /* increment to next digit*/
        lsb_idx_ += num_bits_in_digit_;
    }
}



static int CreateMaskIMP(int num_,
                        int digit_lsb_idx_,
                        int num_bits_in_digit_)
{
    int mask = ~(~0 << num_bits_in_digit_);

    return ((num_ >> digit_lsb_idx_) & mask);
}

static void PrintArrIMP(int *arr, size_t len)
{
    size_t i = 0;

    for (i = 0; i < len; ++i)
    {
        printf("%d, ", arr[i]);
    }
    puts("\n");
}