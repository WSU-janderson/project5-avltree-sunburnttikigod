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

/*My biggest hold up here was trying to figure out the recursive logic,
 *not the base case, but rather the initial check and creation of my tree and
 *travesal node I finally think i found the structure that works, did some rucursion practice
 *on coding bat, and remembered what one of the kids asked in class about
 *using a helper function for the recursion.  so I will verify my traveler and
 *create/assign if needed then isolate the recursion to it's own function, so
 *I don't have to worry about 'stacking' nodes
 *
 */

bool AVLTree::insert(const std::string &key, size_t value) {
    // check's for root nodes existence / contents not assigned
    // this is for the first value in the tree
    if (!root) {
        root = new AVLNode(key, value); // assign root's key/value
        return true; //return type bool - successful insert = true
    }
    recursivelyInsert(root, key, value);
}

bool AVLTree::recursivelyInsert(AVLNode *&nodeIn, const std::string &key, size_t value) {
    //Since the other function takes care of the initial value situation
    //this one can headline with the base case
    if (!nodeIn) {
        //if node is null make new node and assign key&value
        nodeIn = new AVLNode(key, value);
        return true; //return true
    }
    //if key is less than, fall left
    if (key < nodeIn->key) {
        recursivelyInsert(nodeIn->left, key, value);
    }
    //if key is greater than fall right
    else if (key > nodeIn->key) {
        recursivelyInsert(nodeIn->left, key, value);
    }
    // This means theres a dupe so return false
    else {
        nodeIn->value = value;
        return false;
    }
    keyList.push_back(key);
    balanceNode(nodeIn);
}

//now to redo this mess with the same technique i used with insert
// i guess like a init and a recurse function

vector<std::string> AVLTree::findRange(const std::string &lowKey, const std::string &highKey) {
    vector<std::string> *rangeList = new vector<std::string>;
    rangingRecursively(root, lowKey, highKey, rangeList);
    return *rangeList;
}

void AVLTree::rangingRecursively(AVLNode *ranger, std::string &lowKey,
                                 const std::string &highKey, vector<std::string> *&rangeList) {
    //base case -> if it's at the end of the branch !//HOPPING_NODE_NAME// then return
    if (!ranger) {
        return;
    } //if key is greater than fall right

    //if travelling node key is greater than lowKey add and higher than highKey
    if (ranger->key > lowKey && ranger->key < highKey) {
        rangeList->push_back(to_string(ranger->value)); //add it to the node list
    }
    //traversal logic
    if (ranger->key > lowKey) {
        rangingRecursively(ranger->left, lowKey, highKey, rangeList);
    } else if (ranger->key < highKey) {
        rangingRecursively(ranger->left, lowKey, highKey, rangeList);
    }
}

/*
 * 'get' retrieves the value held in a node that carries the key requested
 * using a recursive function that it calles with the root pointer and the
 * requested key
 */

std::optional<size_t> AVLTree::get(const std::string &key) const {
    return (getRecursively(root, key));
}

/*
 * getRecursively is called as the recursive function for 'get'
 * it will return 'nullopt' if a matching 'key' is not found
 *    1.  first is one basecase => if the current node is null - return nullopt
 *      * nullopt is an option only available when the return is std::optional
 *      * 'optional' is included at the beginning
 *    2. next is the second base case => the key was found - the currentNode returns it's 'value'
 *    3. then if current node exists and is not empty, tree traversal logic
 *      * if the requested key is less than current node key go left(lower)
 *      * if the requested key is greater than the current node key go right(higher)
 *          *no conditional because it's the only option left if it made it this far.
*/

std::optional<size_t> AVLTree::getRecursively(AVLNode *currentNode,
                                              const std::string &key) const {
    //base case one end of line not found
    if (!currentNode) {
        return nullopt;
    }
    // base case two found node return value
    if (currentNode->key == key) {
        return currentNode->value;
    }
    // not found continue tree traversal
    if (key < currentNode->key) {
        return getRecursively(currentNode->left, key);
    }
    return getRecursively(currentNode->right, key);
}


size_t AVLTree::size() const {
    return this->keys().size();
}

//uses math.h log2(n) and ceil to round up to get the ideal max height of the tree
size_t AVLTree::getMaxBalancedHeight() {
    AVLTree::maxBalancedHeight = ceil(log2(size()));
    return maxBalancedHeight;
}

//but this was interesting in 2917 - 2920 some DR really
//wanted credit for it, i didn't think Euler new C++ lol
/*   ------
// DR 568.          <-this line specifically
constexpr _Float32
log2(_Float32 __x)
{ return __builtin_log2f(__x); }
*  ------
*/

size_t &AVLTree::operator[](const std::string &key);

bool AVLTree::contains(const std::string &key) const {
}

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
        remove(root, smallestInRight->key);
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

/*
 *Taken from AVL slides:
MM__________WW___________MM________WW______MM________WW
||  Problem || Rotation  ||  Hook  || Hook || Single ||
||  Balance || Direction ||  Node  || Bal  || Double ||
||==========||===========||========||======||========||
||    2     ||   Right   ||  Left  ||   1  || Single ||
||    2     ||   Right   ||  Left  ||  -1  || Double ||
||   -2     ||   Left    ||  Right ||  -1  || Single ||
||   -2     ||   Left    ||  Right ||   1  || Double ||
\\==========/\===========/\========/\======/\========//
Source: https://pilot.wright.edu/d2l/le/content/760093/viewContent/5457997/View
Author: Dr. James Anderson
/*           |\    ↷       ✓✓✓✓✓✓✓✓
 *          / ↱\(3) ↓     ✓✓✓✓(2)✓✓✓✓
 *          \ ↑ /   ↓    ✓✓✓✓/✓✓✓\✓✓✓✓
 *           ¿(2) ← ↵  ✓✓✓✓(1)✓✓✓(3)✓✓✓✓
 *            /       ✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓
 *          (1)
*/

void AVLTree::balanceNode(AVLNode *&node) {
    int balance = getBalance(node);

    //if the left subtree is longer than the right
    // perform a right rotation of current node after hooking
    // the left child, if the left child's balance is
    // greater than zero rotate left
    if (balance > 1) {
        if (getBalance(node->left) > 0) {
            rotateLeft(node->left); //rotate left child left
        }
        rotateRight(node);
    }
    //if the left subtree is longer than the right
    // perform a right rotation of current node after hooking
    // the left child, if the left child's balance is
    // greater than zero rotate left
    else if (balance < -1) {
        if (getBalance(node->right) > 0) {
            rotateRight(node->right); //rotate right child right
        }
        rotateLeft(node);
    }

    node->height = node->getHeight();
}

void AVLTree::rotateLeft(AVLNode *&node) {
    AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = nullptr;
    node = newRoot;
}

void AVLTree::rotateRight(AVLNode *&node) {
    AVLNode *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = nullptr;
    node = newRoot;
}

void operator=(const AVLTree &other) {
}

~AVLTree() {
    Delete(getLeaf(root));
}

AVLNode getLeaf(AVLTree::AVLNode *&node) {
    if (!node->isLeaf()) {
        if (node->left = nullptr) {
            node = node->left;
            delete node;
            AVLTree::getLeaf(root);
        } else node = node->right;

        getleaf

                friend std::ostream &operator<<(ostream &os, const AVLTree &avlTree);
    }
