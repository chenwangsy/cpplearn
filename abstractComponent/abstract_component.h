#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractComponent
{
    public:
        AbstractComponent(const string &compoName);
        ~AbstractComponent();
        void addChild(AbstractComponent *pChild);
        bool hasParent() const;
        bool hasChild() const;
        void printChilds() const;

    private:
        void setParent(AbstractComponent *pParent);


    private:
        string compoName_;
        AbstractComponent *parent_;
        vector<AbstractComponent *> childCompos_;
};
