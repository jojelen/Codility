// 100 % solution of finding height of binary tree

int treeHeight(tree* T) {
    if (T == nullptr) return 0;
    return 1 + std::max(treeHeight(T->l), treeHeight(T->r));
}
int solution(tree* T) { return treeHeight(T) - 1; }
