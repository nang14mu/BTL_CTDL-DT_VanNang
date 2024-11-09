#include<iostream>


 #ifndef __QUEUE__CPP
 #define __QUEUE__CPP

 
using namespace std;
template<typename T>
class Node{
    private:
        T elm;
        Node* next;
    public:
        Node();
        Node(T elm, Node* next=NULL){
            this->elm=elm;
            this->next=next;
        }
        T getElm(){
            return this->elm;
        }
        Node* getNext(){
            return this->next;
        }
        void setElm(T elm){
            this->elm=elm;
        }
        void setNext(Node* node){
            this->next=node;
        }
};

template<typename T>
class queue{
    private:
        int n;
        Node<T>* begin;
        Node<T>* end;
    public:
        queue(){
            n=0;
            begin=nullptr;
            end=nullptr;
        }
        T front(){
            return begin->getElm();
        }
        T back(){
            return end->getElm();
        }
        void push(T x){
            Node<T>* node = new Node<T>(x);
            if(n==0){
                begin=end=node;
            }
            else{
                end->setNext(node);
                end=end->getNext();
            }
            n++;
        }
        void pop(){
            if(n==0) return;
            begin=begin->getNext();
            n--;
        }
        bool empty(){
            return n==0;
        }
};

#endif