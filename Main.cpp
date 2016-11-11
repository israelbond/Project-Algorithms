#include "List.h"

void TestRBTree();


int main()
{
	cout <<"UP AND RUNNING"<<endl;

    TestRBTree();

return 0;
}


void TestRBTree()
{
    RBTree twig;

    cout<<"\n\t\tDisp 1";
    twig.DisplayTree();
    cout<<"\n\t\tINSERT";
    twig.Insert(15);
    cout<<"\n\t\tFALSE SEARCH";
    twig.Search(10);
    cout<<"\n\t\tTRUE SEARCH";
    twig.Search(15);
    cout<<"\n\t\tDisp 2";
    twig.DisplayTree();
    cout<<"\n\t\tBURN TREE";
    twig.DeleteTree();
    cout<<"\n\t\tDisp 3";
    twig.DisplayTree();

}
