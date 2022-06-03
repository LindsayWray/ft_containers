#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "../Containers/map.hpp"
#include "../Utils/RBtree.hpp"
#include "../Utils/node.hpp"

/*             ⢀⣴⡆                               
              ⢀⣾⣿⣧                               
             ⢀⣾⣿⣿⣿                               
             ⡾⠋⠉ ⡇  ~~* Special thanks to MRaasveldt!! *~~                         
            ⣼⠃   ⡇                             
           ⢀⡏    ⡇                               
           ⢸     ⡇                     ⢀⣀⣀⣠⣤⣤⣤⣤  
           ⡏    ⢸⠃               ⣀⡤⠴⠒⠊⠉⠉  ⣿⣿⣿⠿⠋  
           ⡇  ⢀⡠⠼⠴⠒⠒⠒⠒⠦⠤⠤⣄⣀ ⢀⣠⠴⠚⠉        ⣼⠿⠋⠁    
           ⣇⠔⠂⠈           ⢨⠿⠋        ⣀⡤⠖⠋⠁       
          ⢰⠋                    ⣀⣠⠤⠒⠋⠁           
         ⢀⡟ ⣠⣄⡀              ⠈⠉⢻⠁         ⢀⣠⣤⣤⡤⠤⢴
         ⣸⠁⣾⣿⣀⣽⡆       ⢠⣾⠉⢿⣦   ⢸⡀  ⢀⣠⠤⠔⠒⠋⠉⠉    ⢀⡞
        ⢀⡏ ⠹⠿⠿⠟⠁ ⠰⠦    ⠸⣿⣿⣿⡿   ⢘⡧⠖⠋⠁           ⡼ 
        ⣼⠦⣄  ⢠⣀⣀⣴⠟⠶⣄⡀  ⡀ ⠉⠁    ⢸⠇             ⣸⠁ 
       ⢰⡇ ⠈⡇  ⠸⡾⠁   ⠉⠉⡏   ⣠⠖⠉⠓⢤⢸             ⣰⠃  
        ⢧⣀⡼⠃   ⢧     ⢸⠃   ⣧   ⣸⢹            ⡰⠃   
        ⠈⢧⡀    ⠘⣆   ⢠⠏    ⠈⠳⠤⠖⠃⡟   ⢾⠛⠛⠛⠛⠛⠛⠛⠛⠁    
          ⠙⣆    ⠈⠦⣀⡴⠋        ⢀⣼⠙⢦  ⠘⡇            
          ⢠⡇⠙⠦⣄           ⢀⣠⠴⠋⠸⡇⠈⢳⡀ ⢹⡀           
          ⡼⣀  ⠈⠙⠂         ⠉    ⣷⠴⠚⠁ ⣀⣷           
         ⡴⠁⡏         ⢠         ⠘⣆⡴⠚⠉⠉            
   ⣼⢷⡆ ⣠⡴⠧⣄⣇       ⢲ ⡟       ⢀⡇⣠⣽⢦⣄⢀⣴⣶           
   ⡿⣼⣽⡞⠁   ⢹⡀      ⠈⣷⠃       ⣼⠉⠁  ⢠⢟⣿⣿⠁          
   ⣷⠉⠁⢳    ⠈⣧       ⣻       ⣰⠃    ⠏  ⡿           
   ⠹⡆ ⠈⡇    ⠘⣆      ⡇      ⣰⠃       ⣸⠁           
    ⢳⡀ ⠙     ⠘⣆     ⡇     ⣰⠃    ⢀⡄ ⢠⠇            
     ⢳⡀⣰⣀⣀⣀   ⠘⣦⣀   ⡇   ⢀⡴⠃     ⢸⡇⢠⠏             
      ⠉⠉  ⠈⠉⠉⠉⠙⠻⠿⠾⠾⠻⠓⢦⠦⡶⡶⠿⠛⠛⠓⠒⠒⠚⠛⠛⠁*/             


namespace ft{
    template <typename T>
    bool isBlack(const node<T>* element) {
        return element == NULL || element->color == BLACK;
    }

    template <typename T>
    int blackHeight(const node<T>* element) {
        if (element == NULL || (element->left && element->left->right == element))
            return 0;
        int blackHeightLeft = blackHeight(element->left);
        int blackHeightRight = blackHeight(element->right);
        assert(blackHeightLeft == blackHeightRight);
        if (isBlack(element))
            return blackHeightLeft + 1;
        return blackHeightLeft;
    }

    template <typename T, typename value_compare>
    int testNode(const node<T>* element, const value_compare& comp) {
        if (element == NULL || (element->left && element->left->right == element))
            return 0;
        if (element->right) {
            assert(element->right->parent == element);
            assert(comp(*element->data, *element->right->data));
        }
        if (element->left) {
            assert(element->left->parent == element);
            assert(comp(*element->left->data, *element->data));
        }
        if (element->color == RED)
            assert(element->parent->color == BLACK);
        assert(testNode(element->left, comp) == testNode(element->right, comp));
        return blackHeight(element);
    }

    template <typename T, typename value_compare>
    bool testRedBlackInvariant(const node<T>* root, const value_compare& comp) {
        if (root == NULL)
            return true;
        assert(root->color == BLACK);
        testNode(root, comp);
        return true;
    }

    template <typename T, typename Alloc, typename value_compare>
    bool validRB(const ft::RBtree<T, Alloc, value_compare>& tree, const value_compare& comp) {
        return testRedBlackInvariant(tree.getRoot(), comp);
    }
}
