#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct Node{
    unordered_map<char, Node*> nextChars;
    string word{};
    Node(){}
};

class Dictionary
{
private:
    Node* dictionary;
    void dfs(string_view word, int i, Node* cur, map<int, vector<string>>& alt, int cnt)
    {
        if(i==word.length())
        {
            alt[cnt].push_back(cur->word);
            return;
        }
        if(cur->nextChars.find(word[i]) != cur->nextChars.end())
            dfs(word, i+1, cur->nextChars[word[i]], alt, cnt);
        else
        {
            for(auto &x: cur->nextChars)
                dfs(word, i+1, x.second, alt, cnt+1);
        }
    }
public:
    using Alternatives = pair<int, vector<string>>;
    Dictionary()
    {
        dictionary = new Node();
    }
    void addToDictionary(string_view word)
    {
        Node* itr = dictionary;
        for(auto x: word)
        {
            if(itr->nextChars.find(x) == itr->nextChars.end())
                itr->nextChars[x] = new Node();
            itr = itr->nextChars[x];
        }
        itr->word = word;
    }
    vector<Alternatives> spellCheck(string text)
    {
        stringstream str(text);
        string word{};
        vector<Alternatives> ans;
        int i{};
        while(str>>word)
        {
            map<int, vector<string>> mp;
            dfs(word, 0, dictionary, mp, 0);
            auto alt = mp.begin()->second;
            if(alt.size())
                ans.push_back({i, alt});
            i++;
        }
        return ans;
    }
};


int main()
{
    Dictionary dic;
    dic.addToDictionary("calendar");
    dic.addToDictionary("cylinder");
    vector<Dictionary::Alternatives> vec = dic.spellCheck("calender");
    for(auto &x: vec)
    {
        cout<<x.first<<"\n";
        for(auto &y: x.second)
            cout<<y<<" ";
        cout<<"\n";
    }
    
    return 0;
}