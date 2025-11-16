//MY MY MY MY MY MY MY MY MY
// MY function test script MY
// MY MY MY MY MY MY MY MY MY
// Created by
// ©️ĥª®Ł¡ē↴ ™️
// MMMMMM       MMMMMM UUUUUU   UUUUUU     SSSSSSSS      TTTTTTTT /T|\TT    ©️
//  MMMMMMM   MMMMMMM   UUUU     UUUU    SSSSS  SSSSS    TTTTTTTTTTT T TT[
//  MMMM MMM MMM MMMM   UUUU     UUUU   SSSSS     SSSS   TT    TTT    T\|
//  MMMM  MMMMM  MMMM   UUUU     UUUU    SSSS        S   T     TTT    L \
//  MMMM   MMM   MMMM   UUUU     UUUU   S    SSSSS    S        TTT   T T
//  MMMM         MMMM   UUUU     UUUU   SS       SSSS  S       TTT  T  /|   |-
//  MMMM         MMMM   UUUU     UUUU   SSS      SSSSS         TTT    T - \    -
//  MMMM         MMMM    UUUUUUUUUUU  SS SSSS   SSSSS         TTTTT     \Z||/-=__I
// MMMMMM       MMMMMM    UUUUUUUUU   S  S SSSSSSSS          TTTTTTTT  TX\_|_T[|_T
//
// 01000011 01101000 01100001 01110010 01101100 01100101 01110011 00100000 01001010 01101111 01110011 01100101 01110000 01101000 00100000 01001101 01110101 01110011 01110100
//
// Created by sunbu on 11/11/2025.
//

#include "FunctionTester.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <ranges>

using namespace safeTests;
using namespace std;


int main() {

    srand(time(NULL));

    pthread_t testThread;

        AVLTree tree;
        AVLNode* root = tree.getRoot();
        root->insert("6", '3');
        root->insert("3", '2');
        root->insert("4", 'X');
        root->insert("2", '4');
        root->insert("e", 'A');
        root->insert("1", '2');
        root->insert("4", 'f');
        root->insert("3", 'f');
        root->insert("M", '1');
        root->insert("j", 'w');


    }
}
