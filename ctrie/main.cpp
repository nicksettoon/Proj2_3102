#include<fstream>
#include <chrono>
// #include<iostream>  //included in node.h
// #include<string>    //included in node.h
#include "headers/ll_trie.h"
#include "headers/hsh_trie.h"

using str = std::string;
using Hash = HashTrie::Hashes;

int main()
{

    LinkedList* trie;
    trie = new LinkedList;
    std::ifstream input;
    str word;
    input.open("words.txt");
    int count;
    while (input >> word)
    {
        trie->insert(word);
        count++;
    }
    std::cout << count << std::endl;
    input.close();

    Hash hashtype = Hash::prime; 
    HashTrie* hshtrie = new HashTrie(1009, hashtype);
    trie->getNodes(hshtrie, nullptr, trie->root, trie->root->label);

    // input.open("words.txt");
    // auto start = std::chrono::high_resolution_clock::now();
    // while(input >> word)
    // {
    //     trie->search(word);
    // }
    // input.close();
    // auto elapsed = std::chrono::high_resolution_clock::now() - start;
    // long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    // std::cout << "Linked list performance for search: " << microseconds << " micro-sec" << std::endl;

    return 0;
}
