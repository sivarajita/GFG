class Solution {
    struct TrieNode {
        TrieNode* child[26];
        int freq;

        TrieNode() {
            freq = 0;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;

    void insert(string &word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
            curr->freq++;
        }
    }

    string getPrefix(string &word) {
        TrieNode* curr = root;
        string prefix = "";

        for (char ch : word) {
            int idx = ch - 'a';
            curr = curr->child[idx];
            prefix += ch;

            if (curr->freq == 1)
                break;
        }

        return prefix;
    }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        root = new TrieNode();

        for (string &word : arr)
            insert(word);

        vector<string> ans;
        for (string &word : arr)
            ans.push_back(getPrefix(word));

        return ans;
    }
};