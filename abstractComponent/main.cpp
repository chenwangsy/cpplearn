#include "abstract_component.h"

int main()
{
    AbstractComponent *pParent = new AbstractComponent("MultiObjsTracker");
    cout << pParent->hasChild() << pParent->hasParent() << endl;


    AbstractComponent *pchild1 = new AbstractComponent("AbstractAsso");
    AbstractComponent *pchild2 = new AbstractComponent("Fusioner");
    AbstractComponent *pchild3 = new AbstractComponent("ObjsSelector");

    pParent->addChild(pchild1);

    pParent->addChild(pchild2);

    pParent->addChild(pchild3);

    pParent->printChilds();
    pchild1->printChilds();
    pchild2->printChilds();
    pchild3->printChilds();
    cout << "MultiObjsTracker has parent -> " << (int)pParent->hasParent() << endl;

    cout << pchild1->hasParent() << pchild2->hasParent() << pchild3->hasParent() << endl;

    delete pParent;
    return 0;
}