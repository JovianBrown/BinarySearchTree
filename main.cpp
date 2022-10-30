#include <iostream>
#include <stack>




struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(int v)
    {
        left = NULL;
        right = NULL;
        value = v;
    }
    
};

void insertNode(Node& n, Node& rootNode)
{
    
    if(n.value > rootNode.value ) // should insert on right
    {
        if(rootNode.right == NULL)
        {
            rootNode.right = &n;

        }
        else
        {
            insertNode(n, *rootNode.right);
        }
        
    }
    else  //should insert on left
    {
        if(rootNode.left == NULL)
        {
            rootNode.left = &n;
            std::cout<<"Inserting on left of root node"<<std::endl;
        }
        else
        {
            insertNode(n, *rootNode.left);
        }
        
    }
}



void printBST(Node* rootNode)
{
    std::stack<int> allNodes;
    
    if(rootNode==NULL)
    {
        std::cout<<"Root node null, nothing to print"<<std::endl;
    }
    if(rootNode->left == NULL && rootNode->right == NULL)
    {
        allNodes.push(rootNode->value);
        
    }
    else
    {
        if(rootNode->left!=NULL)
        {
            allNodes.push(rootNode->left->value);
            printBST(rootNode->left);
        }
    }
    std::cout<<"Printing all nodes: "<<std::endl;
    for(int i = 0; i<allNodes.size(); i++)
    {
        
        std::cout<<allNodes.top()<<std::endl;
        allNodes.pop();
    }
   
}

bool searchBST(int value, Node* rootNode)
{
    if(rootNode==NULL)
    {
        return false;
    }
    if(rootNode->value == value)
    {
        return true;
    }
    if(value > rootNode->value)
    {
       return searchBST(value, rootNode->right);
        
    }
    else
    {
        return searchBST(value, rootNode->left);
    }
    
}
bool isInStack(std::stack<int> allNodes, int value)
{

    for(int i = 0; i< allNodes.size();i++)
    {
        if(value == allNodes.top())
            return true;
        allNodes.pop();
    }
    return false;
}
void printNodes(Node* rootNode, Node* currentNode, std::stack<int> &allNodes) //Goes through entire node tree and lists values of each node
{
  
    if(!isInStack(allNodes,currentNode->value))
    {
        allNodes.emplace(currentNode->value);    
    }
    
    if(currentNode->left)
    {
        printNodes(rootNode, currentNode->left, allNodes);
    }
    if(currentNode->right)
    {
  
        printNodes(rootNode, currentNode->right, allNodes);   
        
    }

}
int main()
{
    int arrayOne[] = {11,2,4, 5, 23, 8,9,22};
    Node* rootNode = new Node(10);
    int arraySize = 8;
    
    for(int i = 0; i<8; i++) //Insert nodes for each element in arrayOne
    {
        Node* n = new Node(arrayOne[i]);
        insertNode(*n, *rootNode);
    }
    
    std::stack<int> allNodes; 
    printNodes(rootNode, rootNode, allNodes);
    
    if(searchBST(23, rootNode))
    {
        std::cout<<"Node found"<<std::endl;
    }
    int allNodesSize = (int)allNodes.size();
    for(int i = 0; i < allNodesSize ; i++)
    {
        int nodeValue = allNodes.top();
        
        std::cout<<"Node Value: "<<nodeValue<<std::endl;
        
        allNodes.pop();
        
    }

    
    return 0;
}
