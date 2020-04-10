#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    string tag_name;
    vector<Node *> child_tags;
    vector<pair<string, string>> attributes;
    Node *parent_tag;
};

int main() {
    int n, q;
    cin>>n>>q;
    cin.ignore();
    Node *root = new Node();
    Node *temp = root;
    for(int i=0;i<n;i++){
        string str,subs;
        getline(cin,str);
        vector<string> tokens;
        int prev = 0;
        string chars = "<>";
        for(char c:chars){
            str.erase(remove(str.begin(),str.end(),c),str.end());
        }
        for(int j=0;j<str.length();j++){
            if(str[j] == ' '){
                subs = str.substr(prev, j-prev);
                tokens.push_back(subs);
                prev = j+1;
            }
        }
        subs = str.substr(prev, str.length()-prev);
        tokens.push_back(subs);
        //cout<<tokens.size()<<endl;
        for(int j =0;j<tokens.size();j++){
            //cout<<tokens[j]<<endl;
        }
        Node *newNode;
        for(int j=0;j<tokens.size();j++){
            if(j==0){
                if(tokens[j][0]!='/'){
                    newNode = new Node();
                    newNode->parent_tag = temp;
                    temp->child_tags.push_back(newNode);
                    newNode->tag_name = tokens[j].substr(0,tokens[j].length());
                    temp = newNode;
                }
                else{
                    temp = temp->parent_tag;
                }
            }
            if(j%3 ==1){
                auto newPair = make_pair(tokens[j], tokens[j+2].substr(1,tokens[j+2].length()-2));
                newNode->attributes.push_back(newPair);
            }
        }
    }
   // cout<<"Tree created"<<endl;
    for(int i = 0;i<q;i++){
        string str,subs;
        getline(cin,str);
        //cout<<str<<endl;
        vector<string> tokens;
        int prev = 0;
        for(int j = 0;j<str.length();j++){
            if(str[j] == '.' || str[j] == '~'){
                subs = str.substr(prev, j-prev);
                tokens.push_back(subs);
                prev = j+1;
            }
        }
        subs = str.substr(prev, str.length()-prev);
        tokens.push_back(subs);
        //cout<<"Tokenization completed"<<endl<<tokens.size()<<endl;
        Node *temp = root;
        bool flag = false;
        for(int j=0;j<tokens.size() -1;j++){
            flag = false;
            for(int k=0;k<temp->child_tags.size();k++){
                if(temp->child_tags[k]->tag_name == tokens[j]){
                    temp = temp->child_tags[k];
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false){
            cout<<"Not Found!"<<endl;
        }
        else{
            flag = false;
            for(auto iter: temp->attributes){
                if(iter.first == tokens[tokens.size()-1]){
                    cout<<iter.second<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                cout<<"Not Found!"<<endl;
            }
        }
    }
    return 0;
}
