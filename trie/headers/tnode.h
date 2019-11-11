#pragma once
#include <string>
// #include "tools.h"
/*FILL_LATER*/

using str = std::string;    //type abstraction for easier use

namespace tnode
{//namespace definition for use elsewhere
    
    struct Node
    {//basic building block for compact trie
        char head;          //can be null for root, first char in label
        str label;          //can be null for root, but holds compacted strings in words
        bool eow;           //"end of word" flag to tell whether or not this node ends a word
        Node *rightsib;    //right sibling
        Node *child1;       //first child

        //constructors
        Node(); //default
        Node(Node *parent, str s); //custom
        Node *findSibling(char target_head);  //finds the sibling containing the target_head

        //destructor
        ~Node();
    };
}