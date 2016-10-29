#include "List.h"

RBTree::RBTree()
{
   root = NULL;
}

RBTree::~RBTree()
{
  if(root) return DeleteTree(root);
}

void RBTree::Insert(int num)
{
}

void RBTree::Remove(int num)
{
}

void RBTree::Search(int num)
{
}

void RBTree::DisplayOne()
{
}

void RBTree::DisplayTree()
{
	if(root) DisplayTree(root);
}

void RBTree::Display(RBNode *& root)
{
	if(!root) return;
	Display(root->left);
	cout <<"\t Data: "<< root->data <<"\t Color: "<< color"\n";
	Display(root->right);

}

//RBTree::
