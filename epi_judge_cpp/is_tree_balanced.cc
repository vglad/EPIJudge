#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int height(const unique_ptr<BinaryTreeNode<int>>& node) {
    if (node == nullptr) {
        return 0;
    }
    auto l = height(node->left);
    auto r = height(node->right);
    return (l > r ? l : r) + 1;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (tree == nullptr) {
        return true;
    }
    auto l = height(tree->left);
    auto r = height(tree->right);
    return abs(l - r) <= 1 && IsBalanced(tree->left) && IsBalanced(tree->right);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
