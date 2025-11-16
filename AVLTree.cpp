#include "AVLTree.h"

#include <memory>
#include <string>

size_t AVLTree::AVLNode::numChildren() const {
return (this->isLeaf() ? 0 : (this->right != nullptr && this->left != nullptr) ? 2 : 1);
    // if is leaf return zero else if right exists and left exists, return 2 else return 1
}

bool AVLTree::AVLNode::isLeaf() const {
    return (this->left == nullptr && this->right == nullptr);
}

size_t AVLTree::AVLNode::getHeight() const {
    return this->height;
}

bool AVLTree::removeNode(AVLNode*& current){
    if (!current) {
        return false;
    }

    AVLNode* toDelete = current;
    auto nChildren = current->numChildren();
    if (current->isLeaf()) {
        current = nullptr;
    } else if (current->numChildren() == 1) {
        // case 2 - replace current with its only child
        if (current->right) {
            current = current->right;
        } else {
            current = current->left;
        }
    } else {
        // case 3 - we have two children,
        // get smallest key in right subtree by
        // getting right child and go left until left is null
        AVLNode* smallestInRight = current->right;
        // I could check if smallestInRight is null,
        // but it shouldn't be since the node has two children
        while (smallestInRight->left) {
            smallestInRight = smallestInRight->left;
        }
        std::string newKey = smallestInRight->key;
        int newValue = smallestInRight->value;
        remove(root, smallestInRight->key); // delete this one

        current->key = newKey;
        current->value = newValue;

        current->height = current->getHeight();
        balanceNode(current);

        return true; // we already deleted the one we needed to so return
    }
    delete toDelete;

    return true;
}

/*bool AVLTree::remove(AVLNode *&current, KeyType key) {
    return false;
}*/

void AVLTree::balanceNode(AVLNode *&node) {
    //Goin fishin
    //I keep thinking that if i could use one complete traversal to count the size of the tree, I could then set a goal
    //height for each branch by using a root 2 on the size to get the target height. following this any branch that is
    //larger than the target you stop at the target height for the branch and go fishing until you've got nothing left
    //to hook (null pointer) using inorder to count (left to right) and postorder(right to left) so it's one natural
    //traversal to balance, remove and insert as your operations for balancing.  insert(remove(Node));
}
