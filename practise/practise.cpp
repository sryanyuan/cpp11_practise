// practise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "src/weekcallback/weakcallback.h"
#include "src/variadic_template/variadic_template.h"
#include "src/copy_on_write/copy_on_write.h"
#include "src/blocking_queue/blocking_queue_test.h"
#include "src/leetcode/roman_to_integer.h"
#include "src/leetcode/longest_common_prefix.h"
#include "src/leetcode/valid_parentheses.h"
#include "src/leetcode/count_and_say.h"
#include "src/leetcode/maximum_subarray.h"
#include "src/leetcode/length_of_last_word.h"
#include "src/leetcode/plus_one.h"
#include "src/leetcode/add_binary.h"
#include "src/leetcode/sqrt(x).h"
#include "src/leetcode/climbing_stairs.h"
#include "src/leetcode/merge_sorted_array.h"

int main(int argc, char* argv[])
{
    //CopyOnWrite::main(argc, argv);
    //WeakFactory::main(argc, argv);
    //VariadicTemplate::main(argc, argv);
    //blocking_queue_test_overview();
    vector<int> nums1;
    nums1.resize(6);
    nums1[0] = 3;
    nums1[1] = 4;
    nums1[2] = 5;
    nums1[3] = 0;
    nums1[4] = 0;
    nums1[5] = 0;
    vector<int> nums2;
    nums2.resize(3);
    nums2[0] = 1;
    nums2[1] = 2;
    nums2[2] = 6;
    MergeSortedArray::main(nums1, 3, nums2, 3);

	return 0;
}
