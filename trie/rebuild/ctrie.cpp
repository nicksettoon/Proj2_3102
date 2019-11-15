#include "headers/ctrie.h"




compResult::compResult(int index_in, CompCase case_in)
{//constructor for compResult struct
    index = index_in;
    resultcase = case_in;
}

compResult CompTrie::compareLabel(node* target_node, str target_label)
{//Compares the target_label to the node_label at target_node.
 //returns case the comparison falls under, as well as the index at which to split if necessary
    prt("Entering compareLabel().")
    str& t_l = target_label;            //reference ("target label") to make it easier to type
    str& n_l = target_node->label;      //reference ("node label") to make it easier to type

    int i = 0;  //initialize iterator for moving through target_node's label below
    trie::compResult result;    //instantiate struct for returning later

    for(char c:t_l) //What if comparing single letter which already exists at target_node? c=null?
    {//for each char in the target_label, compare it against the label @ the target_node

        if(i == n_l.length())
        {//case 1: If the index for node_label is equal to the  length of node_label and
         //the for loop is still going, the target_label is a superstring of the node_label
            prt("hit case 1");
            result.index = i;  //return index of where to begin 
            result.compCase = CaseSuperstr; //set case to show the target_label is a superstring of the node_label
            return result;
        }

        if(c == n_l[i])
        {//If current char in target_label is the same as the char @ same position in the node_label
            i++;    //move to next char in node_label and next iteration of for loop
        }
        else
        {//case 2.1: Neither target_label nor node_label have run out of chars, but the current chars differ
         //the target_label diverges from the node_label
            prt("hit case 2.1");
            result.index = i; //return the index at which they diverge for splitting later
            result.compCase = CaseDiv; //set case to show the target_label diverges from the node label at i
            return result; 
        }
    }
    //all chars in target_label have been compared
    if(i < n_l.length())
    {//case 2.2: 1. The for loop ended without differing strings, and 2. end of node_label was not reached
     //The target_label is a substring of target_node's label.
        prt("hit case 2.1");
        result.index = i; //return the index at which they diverge for splitting later
        result.compCase = CaseSubstr;   //set case to show the target_label is a substring of the label
        return result;
    }
    else if(i == n_l.length())
    {//case 3: 1. The for loop ended without differing strings, and 2. the entire target_node's label was compared, 
     //then the target_label is the node_label.
        prt("hit case 3");
        result.index = -1;
        result.compCase = CaseInTrie;   //set case to show the target_label is in the trie
        return result;
    }
    else
        prt("Something went wrong in ctrie::compareLabel! HELP!");
}