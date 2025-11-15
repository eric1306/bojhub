// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
struct Node
{
    Node(int d) : data(d) { }

    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

void printNode(Node* node)
{
    if(node->left!=nullptr) printNode(node->left);
    if(node->right!=nullptr) printNode(node->right);
    cout<<node->data<<'\n';
}

void AddNodeRight(Node* parent, int data)
{
    Node* child = new Node(data);
    parent->right = child;
}
void AddNodeLeft(Node* parent, int data)
{
    Node* child = new Node(data);
    parent->left = child;
}

int main(){
    FASTIO;
    //이진트리 전위 순회 값을 입력 받아서, 후위 순회로 변경
    int input;
    cin>>input;
    Node* root = new Node(input);
    Node* lastNode = root;
    while(cin>>input){
        //이진 검색 트리의 전위 순회 결과
        //루트를 통해 현재 나오는 값이 left인지 right인지 알 수 있음.
        Node* cur = root;
        while(cur)
        {
            if(input < cur->data)
            {
                if(cur->left == nullptr)
                {
                    AddNodeLeft(cur, input);
                    break;
                }
                cur = cur->left;
            }
            else
            {
                if(cur->right == nullptr)
                {
                    AddNodeRight(cur, input);
                    break;
                }
                cur = cur->right;
            }
        }
    }
    printNode(root);
}