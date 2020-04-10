#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : private Cache{
    int size;
    public:
    LRUCache(int capacity){
        cp = capacity;
        tail = head = NULL;
        size = 0;
    }
    int get(int key){
        //cout<<"get started";
        auto iter = mp.find(key);
        if(iter != mp.end()){
            Node* node = iter->second;
            return node->value;
        }
        return -1;
    }
    void set(int k, int v){
        if(size<cp){
            if(head==NULL){
                Node *nd = new Node(k,v);
                head = nd;tail = nd;
                size++;
                mp.insert({k,nd});
                //cout<<"set complete";
            }
            else{
                auto iter = mp.find(k);
                if(iter != mp.end()){
                    Node *temp = iter->second;
                    if(temp == head){
                    }
                    else if(temp == tail){
                        tail = temp->prev;  tail->next = NULL;
                        temp->next = head;  temp->prev = NULL;
                        head->prev = temp;  head = head->prev;                  
                    }
                    else{
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp->prev = NULL; temp->next= head;
                        head->prev = temp; head = head->prev;
                    }
                    head->value = v;
                }
                else{
                    Node *nd = new Node(NULL,head,k,v);
                    head->prev= nd;
                    head = nd;
                    size++;
                    mp.insert({k,nd});
                }
            }
        }
        else{
            auto iter = mp.find(k);
            if(iter != mp.end()){
                Node *temp = iter->second;
                if(temp == head){
                }
                else if(temp == tail){
                    tail = temp->prev;  tail->next = NULL;
                    temp->next = head;  temp->prev = NULL;
                    head->prev = temp;  head = head->prev;                  
                }
                else{
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->prev = NULL; temp->next= head;
                    head->prev = temp; head = head->prev;
                }
                head->value = v;
            }
            else{
                Node *temp = tail;
                iter = mp.find(temp->key);
                mp.erase(iter);
                mp.insert({k,temp});
                tail = tail->prev;  tail->next = NULL;
                temp->prev = NULL;  temp->next = head;
                temp->key = k;      temp->value = v;
                head->prev = temp;  head = head->prev;
            }
        }
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
