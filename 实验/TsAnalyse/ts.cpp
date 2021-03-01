#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
const int maxn = 2E6 + 5;
class encoder
{
private:
    int tot, position;
public:
    struct node
    {
        int code;
        unordered_map< char, int > index;
        node() { code = -1; index.clear(); }
    } trie[maxn];
    void Init()
    {
        tot = 256; trie[0].code = -1; position = 0;
        for (int i = 1; i <= 256; ++i)
        {
            trie[0].index[i] = i;
            trie[i].code = i - 1;
        }
    }
    int Find(string& s)
    {
        for (auto c : s)
        {
            if (!trie[position].index[c]) { position = 0; return -1; }
            position = trie[position].index[c];
        }
        return trie[position].code;
    }
    void Insert(string& s)
    {
        int p = 0;
        for (auto c : s)
        {
            if (trie[p].index[c]) p = trie[p].index[c];
            else
            {
                p = (trie[p].index[c] = tot + 1);
                trie[p].code = tot++;
            }
        }
    }
    void ResetPosition() { position = 0; }
};

int main()
{
    encoder en_coder;
    string a = "asdf", b = "b";
    en_coder.Init();
    cout << en_coder.Find(a) << endl;
    cout << en_coder.Find(b) << endl;
    en_coder.Insert(a);
    en_coder.ResetPosition();
    cout << en_coder.Find(a) << endl;
    return 0;
}
