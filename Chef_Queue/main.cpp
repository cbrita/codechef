#include <iostream>
#include <deque>
#include <iterator>
#define C 1000000007

using namespace std;
typedef struct node {
    int index, value;
}QNode;
deque<QNode> q;

int main()
{   int n,k,a1;
    int p=1;

    cin>>n>>k;

    cin>>a1;
    QNode qNode;
    qNode.index=n;
    qNode.value=a1;
    q.push_back(qNode);
    for(int i=2;i<=n;i++){
        cin>>a1;
        QNode current = q.back();
        QNode newNode;
        newNode.index = n-i+1;
        newNode.value = a1;
        if(current.value <= a1){
            QNode frontNode = q.front();
            if(frontNode.value > a1) {
                p=p*(frontNode.index-(n-i+1)+1);
                q.pop_front();
            }
            q.push_front(newNode);
        } else {
            while(!q.empty()){
                p=p*(current.index-(n-i+1)+1);
                q.pop_back();
                current=q.back();
            }
            q.push_front(newNode);
        }
    }
    cout<<p%C;

    return 0;
}
