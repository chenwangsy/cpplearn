#include "abstract_component.h"

AbstractComponent::AbstractComponent(const string &compoName)
    : compoName_(compoName), parent_(nullptr)
{
    
}

AbstractComponent::~AbstractComponent()
{   
    if(hasChild())
    {
        for(auto p : childCompos_)
        {
            delete p;
        }
        cout << "delete children complete !" << endl;
    }


}

void AbstractComponent::setParent(AbstractComponent *pParent)
{
    parent_ = pParent;
}

void AbstractComponent::addChild(AbstractComponent *pChild)
{
    childCompos_.push_back(pChild);
    pChild->setParent(this);
}

bool AbstractComponent::hasParent() const
{
    return parent_ != nullptr;
}

bool AbstractComponent::hasChild() const
{
    return childCompos_.size() != 0;

}

void AbstractComponent::printChilds() const
{   
    if(hasChild())
    {
        for(auto pChild : childCompos_)
        {
            cout << pChild->compoName_ << "  ";
        }
        cout << endl;
    }
    else
    {
        cout << compoName_ << " doesn't have any child" << endl;
    }

}