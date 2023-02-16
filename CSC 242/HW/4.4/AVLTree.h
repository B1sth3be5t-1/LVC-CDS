//
// Created by Brian Myers on 2/16/23.
//

#ifndef INC_4_4_AVLTREE_H
#define INC_4_4_AVLTREE_H

#include <functional>

template <typename T>
class AVLTree {
public:
    struct AvlNode {
        T element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode( const T & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element{ ele }, left{ lt }, right{ rt }, height{ h } { }

        AvlNode( T && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
        };
};

#endif //INC_4_4_AVLTREE_H
