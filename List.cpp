#include "List.h"




RBNode::RBNode()
{
    color = 'R';
    data = 0;
    parent = left = right = NULL;
}


RBTree::RBTree()
{
   root = NULL;
   q = NULL;
}

RBTree::~RBTree()
{
  if(root) DeleteTree(root);
}

void RBTree::Insert(int num)
{

   int index = 0;
   RBNode *curr, * prev;
   RBNode * temp = new RBNode;
   temp->data = num;
  curr = root;
   q = NULL;

   if(!root)
       root = temp;
   else
   {
       while( curr )
       {
           prev = curr;
           if(temp->data > curr->data)
               curr = curr->right;
           else
               curr = curr->left;
       }
       temp->parent = prev;
       if(temp->data > prev->data)
           prev->right = temp;
       else
           prev->left = temp;
   }
   InsertFIX(temp);
}

void RBTree::InsertFIX(RBNode * temp)
{
    RBNode * hold;
    if(root==temp)
    {
        root->color = 'B';
        return;
    }
    while(temp->parent && temp->parent->color == 'R')
    {
        RBNode * gParent = temp->parent->parent;
        if(gParent->left == temp->parent)
        {
            if(gParent->right)
            {
                hold = gParent->right;
                if(hold->color == 'R')
                {
                    temp->parent->color = 'B';
                    hold->color = 'B';
                    gParent->color = 'R';
                    temp = gParent;
                }
            }
            else
            {
                if(temp->parent->right == temp)
                {
                    temp = temp->parent;
                    RotateRight(temp);
                }
                temp->parent->color = 'B';
                gParent->color = 'R';
                RotateLeft(gParent);
            }
        }
        root->color = 'B';
    }


}

void RBTree::RotateLeft(RBNode * temp)
{
    if(!temp->right)
        return;
    else
    {
        RBNode * hold = temp->right;
        if(hold->left)
        {
            temp->right = hold->left;
            hold->left->parent = temp;
        }
        else
            temp->right = NULL;
        if(temp->parent) 
            hold->parent = temp->parent;
        if(!temp->parent)
            root = hold;
        else
        {
            if(temp == temp->parent->left)
                temp->parent->left = hold;
            else
                temp->parent->right = hold;
        }
        hold->left = temp;
        temp->parent = hold;
    }
}

void RBTree::RotateRight(RBNode * temp)
{
    if(!temp->left)
        return;
    else
    {
        RBNode * hold = temp->left;
        if(hold->right)
        {
            temp->left = hold->right;
            hold->right->parent = temp;
        }
        else
            temp->left = NULL;
        if(temp->parent)
            hold->parent = temp->parent;
        if(!temp->parent)
            root = hold;
        else
        {
            if(temp == temp->parent->left)
                temp->parent->left = hold;
            else
                temp->parent->right = hold;
        }
        hold->right = temp;
        temp->parent = hold;
    }
}

RBNode * RBTree::Successor( RBNode * temp)
{
    RBNode * hold = NULL;
    if(temp->left)
    {
        hold = temp->left;
        while(hold->right)
            hold = hold->right;
    }
    else
    {
        hold = temp->right;
        while(hold->left)
            hold = hold->left;
    }
    return hold;
}


void RBTree::Remove(int num)
{
}

void RBTree::Search(int num)
{
    if(!root)
    {
        cout <<"\nEmpty Tree";
        return;
    }
    char flag = 'N';
    RBNode * hold = root;

    while(hold && flag == 'N')
    {
        if(hold->data == num)
            flag = 'F';
        if(flag == 'N')
        {

            if(hold->data > num)
                hold = hold->left;
            else
                hold = hold->right;
        }
    }
    if(flag == 'F')
        DisplayOne(hold);
    else
        cout <<"\nNumber not found";

    return;
    
}

void RBTree::DisplayOne(const RBNode * disp)
{
	if(!disp)
    {
        cout <<"\nEmpty Node";
        return;
    }
    
    cout <<"\n\t Number: "<< disp->data;
    cout <<"\n\t Color: ";
    if(disp->color == 'B')
        cout <<"Black";
    else
        cout <<"Red";
    return;

}

void RBTree::DisplayTree()
{
    if(!root)
        cout <<"\nEmpty Red Black Tree\n";
    else
        DisplayTree(root);
}

void RBTree::DisplayTree(RBNode *& root)
{
	if(!root)
        return;

	DisplayTree(root->left);
	
    cout <<"\n\t Number: "<< root->data;
    cout <<"\n\t Color: ";

    if(root->color == 'B')
        cout <<"Black";
    else
        cout <<"Red";

	DisplayTree(root->right);

}

void RBTree::DeleteTree()
{
    DeleteTree(root);
}

void RBTree::DeleteTree(RBNode *& root)
{
    if(!root) return;
    
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = NULL;
}
