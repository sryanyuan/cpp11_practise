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
#include "src/leetcode/binary_tree_level_order_traversal_ii.h"
#include "src/leetcode/convert_sorted_array_to_binary_search_tree.h"
#include "src/leetcode/balanced_binary_tree.h"
#include "src/leetcode/minimum_depth_of_binary_tree.h"
#include "src/leetcode/path_sum.h"
#include "src/leetcode/pascals_triangle.h"
#include "src/leetcode/pascals_triangle_ii.h"

int main(int argc, char* argv[])
{
    //CopyOnWrite::main(argc, argv);
    //WeakFactory::main(argc, argv);
    //VariadicTemplate::main(argc, argv);
    //blocking_queue_test_overview();
    PascalsTriangleII::test();

	return 0;
}
