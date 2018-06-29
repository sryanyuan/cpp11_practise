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
#include "src/leetcode/best_time_to_buy_and_sell_stock.h"
#include "src/leetcode/valid_palindrome.h"
#include "src/leetcode/min_stack.h"
#include "src/leetcode/palindrome_linked_list.h"
#include "src/leetcode/lowest_common_ancestor_of_a_binary_search_tree.h"
#include "src/leetcode/ugly_number.h"
#include "src/leetcode/first_bad_version.h"
#include "src/leetcode/move_zeros.h"
#include "src/leetcode/word_pattern.h"
#include "src/leetcode/range_sum_query_immutable.h"
#include "src/leetcode/power_of_four.h"
#include "src/leetcode/reverse_string.h"
#include "src/leetcode/reverse_vowels_of_a_string.h"
#include "src/leetcode/valid_perfect_square.h"
#include "src/leetcode/guess_number_higher_or_lower.h"
#include "src/leetcode/first_unique_character_in_a_string.h"
#include "src/leetcode/nth_digit.h"
#include "src/leetcode/binary_watch.h"
#include "src/leetcode/convert_a_number_to_hexademical.h"
#include "src/leetcode/longest_palindrome.h"
#include "src/leetcode/third_maximum_number.h"
#include "src/leetcode/trapping_rain_water.h"
#include "src/leetcode/add_strings.h"
#include "src/leetcode/number_of_segments_in_a_string.h"
#include "src/leetcode/path_sum_iii.h"
#include "src/leetcode/find_all_anagrams_in_a_string.h"
#include "src/leetcode/arranging_coins.h"
#include "src/leetcode/string_compression.h"
#include "src/leetcode/assign_cookies.h"
#include "src/leetcode/repeated_substring_pattern.h"
#include "src/leetcode/hamming_distance.h"
#include "src/leetcode/island_perimeter.h"
#include "src/leetcode/heaters.h"
#include "src/leetcode/number_complement.h"
#include "src/leetcode/license_key_formatting.h"
#include "src/leetcode/max_consecutive_ones.h"
#include "src/leetcode/construct_the_rectangle.h"
#include "src/leetcode/keyboard_row.h"
#include "src/leetcode/find_mode_in_binary_search_tree.h"
#include "src/leetcode/base_7.h"
#include "src/leetcode/perfect_number.h"
#include "src/leetcode/k_diff_pairs_in_an_array.h"
#include "src/leetcode/diameter_of_binary_tree.h"
#include "src/leetcode/reverse_words_in_a_string_iii.h"
#include "src/leetcode/reshape_the_matrix.h"
#include "src/leetcode/subtree_of_another_tree.h"
#include "src/leetcode/shortest_unsorted_continuous_subarray.h"
#include "src/leetcode/longest_harmonious_subsequence.h"
#include "src/leetcode/minimum_index_sum_of_two_lists.h"
#include "src/leetcode/can_place_flowers.h"
#include "src/leetcode/construct_string_from_binary_tree.h"
#include "src/leetcode/merge_two_binary_trees.h"
#include "src/leetcode/maximum_product_of_tree_numbers.h"
#include "src/leetcode/average_of_levels_in_binary_tree.h"
#include "src/leetcode/maximum_average_subarray_i.h"
#include "src/leetcode/set_mismatch.h"
#include "src/leetcode/two_sum_iv_input_is_bst.h"
#include "src/leetcode/non_decreasing_array.h"
#include "src/leetcode/trim_a_binary_search_tree.h"
#include "src/leetcode/second_minimum_node_in_a_binary_tree.h"
#include "src/leetcode/valid_palindrome_ii.h"
#include "src/leetcode/repeated_string_match.h"
#include "src/leetcode/longest_univalue_path.h"
#include "src/leetcode/binary_number_with_alternating_bits.h"
#include "src/leetcode/count_binary_substrings.h"
#include "src/leetcode/degree_of_an_array.h"
#include "src/leetcode/longest-word-in-dictionary.h"
#include "src/leetcode/find-pivot-index.h"
#include "src/leetcode/flood-fill.h"
#include "src/leetcode/find-smallest-letter-greater-than-target.h"
#include "src/leetcode/min-cost-climbing-stairs.h"
#include "src/leetcode/prime-number-of-set-bits-in-binary-representation.h"
#include "src/leetcode/letter-case-permutation.h"
#include "src/leetcode/rotate-string.h"
#include "src/leetcode/subdomain-visit-count.h"
#include "src/leetcode/magic-squares-in-grid.h"
#include "src/leetcode/maximize-distance-to-closest-person.h"
#include "src/leetcode/peak-index-in-a-mountain-array.h"
#include "src/leetcode/3sum.h"
#include "src/leetcode/3sum-closest.h"
#include "src/leetcode/letter-combinations-of-a-phone-number.h"
#include "src/leetcode/4sum.h"
#include "src/leetcode/generate-parentheses.h"
#include "src/leetcode/swap-nodes-in-pairs.h"
#include "src/leetcode/divide-two-integers.h"
#include "src/leetcode/next-permutation.h"
#include "src/leetcode/combination-sum.h"
#include "src/leetcode/multiply-strings.h"
#include "src/leetcode/rotate-image.h"
#include "src/leetcode/group-anagrams.h"
#include "src/leetcode/jump-game.h"
#include "src/leetcode/spiral-matrix-ii.h"
#include "src/leetcode/permutation-sequence.h"
#include "src/leetcode/rotate-list.h"
#include "src/leetcode/unique-paths.h"
#include "src/leetcode/search-a-2d-matrix.h"
#include "src/leetcode/word-search.h"
#include "src/leetcode/remove-duplicates-from-sorted-list-ii.h"
#include "src/leetcode/partition-list.h"
#include "src/leetcode/gray-code.h"
#include "src/leetcode/subsets-ii.h"
#include "src/leetcode/decode-ways.h"
#include "src/leetcode/reverse-linked-list-ii.h"
#include "src/leetcode/restore-ip-addresses.h"
#include "src/leetcode/construct-binary-tree-from-preorder-and-inorder-traversal.h"
#include "src/leetcode/construct-binary-tree-from-inorder-and-postorder-traversal.h"
#include "src/leetcode/convert-sorted-list-to-binary-search-tree.h"

int main(int argc, char* argv[])
{
	ConvertSortedListToBinarySearchTree::test();

	return 0;
}
