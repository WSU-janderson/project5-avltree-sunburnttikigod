#include "AVLTree.h"

#include <memory>
#include <string>

size_t AVLTree::AVLNode::numChildren() const {
    std:weak_ptr<AVLTree> childCount = ;
    =+ findChild(this->right);
    AVLNode::childCount =+ findChild(this->left);
    return childCount;
}

size_t AVLTree::AVLNode::findChild(AVLNode* sideChildptr){
    size_t childAdder = new size_t*;
    sideChildptr != nullptr ? childAdder = 1 : childAdder = 0;
    findChild(sideChildptr);
return childAdder;
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

bool AVLTree::remove(AVLNode *&current, KeyType key) {
    return false;
}

void AVLTree::balanceNode(AVLNode *&node) {
}
