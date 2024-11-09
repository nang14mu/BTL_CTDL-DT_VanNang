#include<iostream>
#include"tree.cpp"

using namespace std;


int main(){
	Tree<int> game;
    int n;
    cout<<"Nhap so nut: ";
    cin >> n;
    for(int i=1; i<=n; i++){
        game.insert(i);
    }
    game.levelOder(game.getroot(),print);
    int x;
    cout << endl <<"Nhap x la vi tri nguoi thu nhat chon: ";
    cin >> x;
    TreeNode<int>* a= game.find(game.getroot(),x);
    int countLeft = game.size(a->getLeft());
    int countRight = game.size(a->getRight());
    int remaining = game.size(game.getroot()) - countLeft -countRight - 1;
    if(countLeft > n/2 || countRight > n/2 || remaining > n/2){
        cout << "true";
    }
    else cout <<"false";
}