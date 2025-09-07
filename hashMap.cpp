#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class HashMap
{
private:
    int BUCKETS;                           // size of hash table
    vector<list<pair<string, int>>> table; // each bucket is a linked list

    int hash(string key)
    {
        int h = 0;
        for (char c : key)
        {
            h = (h * 31 + c) % BUCKETS; // simple polynomial rolling hash
        }
        return h;
    }

public:
    HashMap(int size = 7)
    { // default table size
        BUCKETS = size;
        table.resize(BUCKETS);
    }

    void put(string key, int value)
    {
        int index = hash(key);
        // check if key already exists, update
        for (auto &p : table[index])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }
        // if not found, insert new
        table[index].push_back({key, value});
    }

    bool get(string key, int &value)
    {
        int index = hash(key);
        for (auto &p : table[index])
        {
            if (p.first == key)
            {
                value = p.second;
                return true;
            }
        }
        return false;
    }

    void remove(string key)
    {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < BUCKETS; i++)
        {
            cout << i << ": ";
            for (auto &p : table[i])
            {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap map(5);

    map.put("apple", 10);
    map.put("banana", 20);
    map.put("grape", 30);
    map.put("orange", 40);

    map.display();

    int val;
    if (map.get("banana", val))
    {
        cout << "Value for 'banana': " << val << endl;
    }

    map.remove("apple");
    cout << "After removing 'apple':" << endl;
    map.display();

    return 0;
}
