/***
   * MY MY MY MY MY MY MY MY MY MY
   * MY AVLTree.cpp [c source]  MY
   * MY MY MY MY MY MY MY MY MY MY
   * Created by
   * ©️ĥª®Ł¡ē↴ ™️
   * MMMMMM       MMMMMM UUUUUU   UUUUUU     SSSSSSSS      TTTTTTTT /T|\T /    ©️
   *  MMMMMMM   MMMMMMM   UUUU     UUUU    SSSSS  SSSSS    TTTTTTTTTT/ T T_ T
   *  MMMM MMM MMM MMMM   UUUU     UUUU   SSSSS     SSSS   TT    TTT  -X T\|
   *  MMMM  MMMMM  MMMM   UUUU     UUUU    SSSS        S   T     TTT    L \ X
   *  MMMM   MMM   MMMM   UUUU     UUUU   S    SSSSS    S        TTT   T T  L
   *  MMMM         MMMM   UUUU     UUUU   SS       SSSS  S       TTT  T  /|  T|-
   *  MMMM         MMMM   UUUU     UUUU   SSS      SSSSS         TTT    T - \  | -
   *  MMMM         MMMM    UUUUUUUUUUU  SS SSSS   SSSSS         TTTTT     \Z||/-=__I
   * MMMMMM       MMMMMM    UUUUUUUUU   S  S SSSSSSSS          TTTTTTTT  TX\_|_T[|_T
   *
   * 01000011 01101000 01100001 01110010 01101100 01100101 01110011
   * 01001010 01101111 01110011 01100101 01110000 01101000
   * 01001101 01110101 01110011 01110100
   * AVLTree.cpp
****/

#include "AVLTree.h"

#include <memory>
#include <string>
#include <vector>
#include <optional>

bool AVLTree::insert(const std::string &key, size_t value) {
    AVLNode* nodeToInsert = new AVLNode(std::string key*&, value*&);
}

vector<std::string> AVLTree::findRange(const std::string &lowKey, const std::string &highKey) const;
{}

std::optional<size_t> AVLTree::get(const std::string &key) {
    //key in hand 🎶🎶skip the the node my darling🎵🎵

        ValueType* nodeValue = nullptr;
        AVLNode* hoppyNode;
        hoppyNode = AVLTree::root;


        (hoppyNode->key != key && !hoppyNode->isLeaf() ?
            (key < hoppyNode->key ?
                (hoppyNode->left ? hoppyNode = hoppyNode->left : nodeValue = nullopt)
                : (hoppyNode->right ? hoppyNode = hoppyNode->right : nodeValue = nullopt))
            : hoppyNode->key == key ? nodeValue = hoppyNode->value : nodeValue = nullopt);

        if (nodeValue != nullptr){
            return nodeValue;
        }else get(key);
    }

        hoppyNode->value = returnValue;
        : return hoppyNode->value;
        get(key);
    }

}

size_t AVLTree::size() const {
    return this->keys().size();
}
//uses math.h log2(n) and ceil to round up to get the ideal max height of the tree
size_t AVLTree::getMaxBalancedHeight(){
    AVLTree::maxBalancedHeight = ceil(log2(size()));;  //line 2394 of cmath.h, because it's built in
    return maxBalancedHeight;                               //but this was interesting in 2917 - 2920 some DR really
}                                                           //wanted credit for it, i didn't think Euler new C++ lol
                                                            /*   ------
                                                            // DR 568.          <-this line specifically
                                                            constexpr _Float32
                                                            log2(_Float32 __x)
                                                            { return __builtin_log2f(__x); }
                                                            *  ------
                                                            */

size_t &AVLTree::operator[](const std::string &key);

bool AVLTree::contains(const std::string &key) const{}

size_t AVLTree::AVLNode::numChildren() const {
    return (this->isLeaf() ? 0 : (this->right && this->left) ? 2 : 1);
    // if is leaf return zero else if right exists and left exists, return 2 else return 1
}

bool AVLTree::AVLNode::isLeaf() const {
    return (!this->left && !this->right);
}

size_t AVLTree::AVLNode::getHeight() const {
    return this->height;
}

vector<std::string> AVLTree::keys() const {
    return this->keyList;
}

bool AVLTree::removeNode(AVLNode *&current) {
    if (!current) {
        return false;
    }

    AVLNode *toDelete = current;
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
        AVLNode *smallestInRight = current->right;
        // I could check if smallestInRight is null,
        // but it shouldn't be since the node has two children
        while (smallestInRight->left) {
            smallestInRight = smallestInRight->left;
        }
        std::string newKey = smallestInRight->key;
        int newValue = smallestInRight->value;
        remove(root, smallestInRight->key); // delete this one
                //remove will start the thread from root with 'smallest in Right' key in hand
                //hop down ask is greater or less than each node and respond accordingly left or right,
                //to my understanding, return false if never found, so is removeNode supposed to be a
                //public function with remove used under the hood as a privbate function
                //here or should i just ignore those details, also with the vector representation available to
                //us ...nvm
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
    //traversal to balance, remove and insert as your operations for balancing.
    AVLNode *highestNode;

    //this serves as the search function, holding on to the pointer for the most out of balance node (highest)
    !node->isLeaf()
        ? (node->getHeight() > highestNode->getHeight()
               ? highestNode = node
               : (node->right ? node = node->right : node = node->left))
        : els
    else
    if () {
        //
        //current!=lastRemovedNode ?
        //      lastRemovedNode = current
        //      insert(remove(lastRemovedNode) : insert(remove(N;
    }


    void operator=(const AVLTree &other);

    ~AVLTree();

    friend std::ostream &operator<<(ostream &os, const AVLTree &avlTree);
}
