/**
 * Leetcode problem: https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * Leetcode Problem #211
 * Medium difficulty
 */
class TrieNode
{
public:
    bool word;
    TrieNode *children[26];
    TrieNode()
    {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

// boosting IOS using a static block!
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children[c - 'a'])
            {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search(word.c_str(), root);
    }

private:
    TrieNode *root = new TrieNode();

    bool search(const char *word, TrieNode *node)
    {
        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] != '.')
            {
                node = node->children[word[i] - 'a'];
            }
            else
            {
                TrieNode *tmp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = tmp->children[j];
                    if (search(word + i + 1, node))
                    {
                        return true;
                    }
                }
            }
        }
        return node && node->word;
    }
};
