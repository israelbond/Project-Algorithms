#include <iostream>
using namespace std;

struct RBNode
{
    RBNode();

	char color;
	int data;

    RBNode * parent;
	RBNode * left;
	RBNode * right;
	
};

class RBTree
{
	public:
	RBTree();
	~RBTree();
	void Insert(int);
    void InsertFIX(RBNode *);
    void RotateLeft(RBNode *);
    void RotateRight(RBNode *);
    RBNode * Successor(RBNode *);
    void Delete();
    void DontDelete(RBNode *);
	void Remove(int);
	void Search(int);
	void DisplayOne(const RBNode *);
	void DisplayTree();
    void DeleteTree();

	private:
	RBNode * root;
    RBNode * q;

	void DisplayTree(RBNode *&);
    void DeleteTree(RBNode *&);

};
