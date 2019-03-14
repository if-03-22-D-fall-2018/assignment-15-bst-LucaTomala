/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdlib.h>
#include "general.h"

struct Node{
  int value;
  struct Node* right_subtree;
  struct Node* left_subtree;
};

Bst new_bst()
{
  return 0;
}

void delete_bst(Bst bst)
{
  if(bst != 0)
  {
    delete_bst(bst->left_subtree);
    delete_bst(bst->right_subtree);
    sfree(bst);
  }
}
int get_depth(Bst bst){
  if (bst == 0)
  {
    return 0;
  }
  if(bst->right_subtree == 0 && bst->left_subtree == 0)
  {
    return 1;
  }
  if(get_depth(right_subtree(bst)) >  get_depth(left_subtree(bst))) return 1 + get_depth(right_subtree(bst));
  {
    return 1 +get_depth(left_subtree(bst));
  }
}
void add(Bst* bst, int value){
  Bst new_Node = (Bst)malloc(sizeof(struct Node));
  new_Node->value = value;
  new_Node->left_subtree = 0;
  new_Node->right_subtree = 0;
  if (*bst == 0)
  {
    *bst = new_Node;
  }
  else if(value<=(*bst)->value)
  {
    if((*bst)->left_subtree == 0)
    {
    (*bst)->left_subtree=new_Node;
    }
    else
    {
      add(&(*bst)->left_subtree, value);
    }
  }
  else if(value>(*bst)->value)
  {
    if((*bst)->right_subtree == 0)
    {
      (*bst)->right_subtree=new_Node;
    }
    else
    {
      add(&(*bst)->right_subtree, value);
    }
  }
}
int root_value(Bst bst){
  return bst->value;
}
Bst left_subtree(Bst root){
  return root->left_subtree;
}
Bst right_subtree(Bst root){
  return root->right_subtree;
}
int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst != 0)
  {
        elements[start] = bst->value;
        if(get_depth(bst) > 0)
        {
          start+=1;
          start = traverse_pre_order(bst->left_subtree, elements, start);
          start = traverse_pre_order(bst->right_subtree, elements, start);
        }
     }
  return start;
}
int traverse_in_order(Bst bst, int *elements, int start){
  if(bst != 0)
  {
        if(get_depth(bst) > 0)
        {

          start = traverse_in_order(bst->left_subtree, elements, start);
          elements[start] = bst->value;
          start+=1;
          start = traverse_in_order(bst->right_subtree, elements, start);
        }
     }
  return start;
}
int traverse_post_order(Bst bst, int *elements, int start){
  if(bst != 0)
  {
        if(get_depth(bst) > 0)
        {

          start = traverse_post_order(bst->left_subtree, elements, start);
          start = traverse_post_order(bst->right_subtree, elements, start);
          elements[start] = bst->value;
          start+=1;
        }
     }
  return start;
}
bool are_equal(Bst bst1, Bst bst2)
{
  if (bst2 == 0)
  {
    return bst1 == 0;
  }
}
void most_left_longest_branch(Bst bst, Bst* branch){

}
int get_number_of_subtrees(Bst bst){
  return 0;
}
