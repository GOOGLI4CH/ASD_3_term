#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct HuffmanNode
{
    char data;
    int frequency;
    HuffmanNode* left, * right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes 
{
    bool operator()(HuffmanNode* left, HuffmanNode* right) 
    {
        return left->frequency > right->frequency;
    }
};

HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyMap)
{
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    for (const auto& pair : frequencyMap) 
    {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1) 
    {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) 
{
    if (root) 
    {
        if (root->data != '$') 
        {
            huffmanCodes[root->data] = code;
        }

        generateHuffmanCodes(root->left, code + "0", huffmanCodes);
        generateHuffmanCodes(root->right, code + "1", huffmanCodes);
    }
}

void printFrequencyTable(const unordered_map<char, int>& frequencyMap)
{
    cout << "Таблица встречаемости символов:" << endl;

    for (const auto& pair : frequencyMap) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << endl;
}

void printCodeTable(const unordered_map<char, string>& huffmanCodes) 
{
    cout << "Таблица соответствия символа и кодовой последовательности:" << endl;

    for (const auto& pair : huffmanCodes) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << endl;
}

void printEncodedMessage(const string& input, const unordered_map<char, string>& huffmanCodes)
{
    cout << "Выходная последовательность:" << endl;

    for (char c : input) 
    {
        if (huffmanCodes.find(c) != huffmanCodes.end())
        {
            cout << huffmanCodes.at(c);
        }
        else
        {
            cerr << "Ошибка: Символ '" << c << "' не представлен в таблице Хаффмана." << endl;
            return;
        }
    }

    cout << endl;
}


int main() 
{
    setlocale(LC_ALL, "rus");

    string input;
    cout << "Введите текст произвольной длины: ";
    getline(cin, input);

    unordered_map<char, int> frequencyMap;

    for (char c : input)
    {
        frequencyMap[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(frequencyMap);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    printFrequencyTable(frequencyMap);
    printCodeTable(huffmanCodes);
    printEncodedMessage(input, huffmanCodes);
}
