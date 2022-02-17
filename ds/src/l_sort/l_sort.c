#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "l_sort.h"

static void HistSetZeroIMP(size_t *histogram_, int num_bits_in_digit_);
static void PrintArrIMP(size_t *arr, size_t len);
static int CreateMaskIMP(int num_,
                        int digit_lsb_idx_,
                        int num_bits_in_digit_);


void CountSort( int src_[],
                int dest_[],
                size_t size_, 
                int digit_lsb_idx_, 
                int num_bits_in_digit_, 
                size_t histogram_[] )
{
    /*variable declarations*/
    
    
    int *src_curr = src_;
    int *src_last = src_ + size_  - 1;
    
    size_t *histo_curr = histogram_ + 1;
    size_t his_len = 1 << num_bits_in_digit_;
    size_t *histo_end =  histogram_ + his_len;

    /*asserts*/
    assert(dest_);
    assert(histogram_);
    assert(0 <= digit_lsb_idx_);
    assert(0 < num_bits_in_digit_);
    
    memset(histogram_, 0, histo_end - histogram_);



    /*for each number in src*/
    while (src_curr <= src_last)
    { 
        /*map the appearance of the mask output to histogram*/
        histogram_[CreateMaskIMP(*src_curr, digit_lsb_idx_, num_bits_in_digit_ )] += 1;
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
    while (src_ <= src_last)
    {
        int idx = CreateMaskIMP(*src_last,
                         digit_lsb_idx_, 
                         num_bits_in_digit_);

        /* copy num to dest at position histogram[masck num] */
        dest_[histogram_[idx] - 1] = *src_last;
            
        /*decrement histogram[idx]*/
        --histogram_[idx];
        --src_last;
    }
}

void RadixSort( int src_[],
                int dest_[],
                size_t size_,
                int num_bits_in_digit_,
                int lsb_idx_,
                int num_significant_bits_,
                size_t histogram_[])
{
    
    /* variable declarations */
    int *curr = src_;
    int last_digit = lsb_idx_ + num_significant_bits_;

    HistSetZeroIMP(histogram_, num_bits_in_digit_);

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
        memcpy(src_ , dest_,  size_ * (sizeof(int)));

        /* increment to next digit*/
        lsb_idx_ += num_bits_in_digit_;
    }
}



static int CreateMaskIMP(int num_,
                        int digit_lsb_idx_,
                        int num_bits_in_digit_)
{
    /* making relevant mask, in the size bits ini digit */
    int ret = num_ >> digit_lsb_idx_;

    assert(num_bits_in_digit_ > 0);
    assert(digit_lsb_idx_ >= 0);
    /* converting to the relevant value */
    ret = ret & ((1 << num_bits_in_digit_) - 1);
    
    return ret;
}

static void PrintArrIMP(size_t *arr, size_t len)
{
    size_t i = 0;

    for (i = 0; i < len; ++i)
    {
        printf("%lu, ", arr[i]);
    }
    puts("\n");
}


static void HistSetZeroIMP(size_t *histogram_, int num_bits_in_digit_)
{
    size_t *curr = histogram_;
    
    assert(histogram_);

    while (curr < histogram_ + (1 << num_bits_in_digit_))
    {
        *curr = 0;
        ++curr;
    }
}

