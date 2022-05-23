#include <list>
#include <iostream>
#include <vector>
using namespace std;

template <typename K, typename V>
class Node
{
public:
    Node() = default;

    Node(K key, V value)
        : _key(key), _value(value)
    {
    }

    K getKey() const { return _key; }

    V getValue() const { return _value; }

    void setValue(V value) { _value = value; }

private:
    K _key;
    V _value;
};

template <typename K, typename V>
class hash_map
{
public:
    hash_map(int bucketSize) : _size(bucketSize)
    {
        _data = vector<list<Node<K, V>>>(bucketSize);
    }

public:
    void insert(K key, V value);
    V find(K key);
    bool empty();
    int size();
    void PrintInfo();

private:
    // 해쉬 알고리즘
    int getHashCode(string key)
    {
        int hashCode = 0;
        for (auto &ch : key)
            hashCode += ch - '0';

        return hashCode;
    }

    int getHashCode(int key)
    {
        return key;
    }

    // 해쉬코드를 인덱스로 컨버트
    int convertToIdx(int hashCode)
    {
        return hashCode % _size;
    }

    // 동일한 key 탐색
    auto searchKey(list<Node<K, V>> &list, K key)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (it->getKey() == key)
            {
                return it;
            }
        }

        return list.end();
    }

private:
    Node<K, V> node;
    vector<list<Node<K, V>>> _data;
    int _size;
};

template <typename K, typename V>
void hash_map<K, V>::PrintInfo()
{
    for (int i = 0; i < _data.size(); i++)
    {
        cout << "[bucket " << i << "] : ";
        for (auto it = _data[i].begin(); it != _data[i].end(); ++it)
        {
            cout << "(" << it->getKey() << ", " << it->getValue() << "), ";
        }
        cout << endl;
    }
}

template <typename K, typename V>
void hash_map<K, V>::insert(K key, V value)
{
    int hashCode = getHashCode(key);
    int idx = convertToIdx(hashCode);
    list<Node<K, V>> &li = _data[idx];

    // 해쉬알고리즘을 통해 얻은 버킷이 비어있다면
    if (li.empty())
    {
        // 그냥 넣어준다.
        li.push_back({key, value});
    }
    // 버킷이 비어있지 않다면
    else
    {
        // 현재 key와 동일한 key가 있는지 찾고
        auto it = searchKey(li, key);

        // 동일한 key가 있었다면 value만 덮어씌운다.
        if (it != li.end())
            it->setValue(value);
        // 동일한 key가 없었다면 그냥 넣어준다.
        // (동일한 버킷의 연결 리스트가 증가, 효율성 떨어짐)
        else
            li.push_back({key, value});
    }
}

template <typename K, typename V>
V hash_map<K, V>::find(K key)
{
    int hashCode = getHashCode(key);
    int idx = convertToIdx(hashCode);

    list<Node<K, V>> &li = _data[idx];
    auto it = searchKey(li, key);

    if (it == li.end())
        return "Not found";
    else
        return it->getValue();
}

template <>
int hash_map<string, int>::find(string key)
{
    int hashCode = getHashCode(key);
    int idx = convertToIdx(hashCode);

    list<Node<string, int>> &li = _data[idx];
    auto it = searchKey(li, key);

    if (it == li.end())
        return -999;
    else
        return it->getValue();
}

template <typename K, typename V>
bool hash_map<K, V>::empty()
{
    if (size() == 0)
        return true;
    else
        return false;
}

template <typename K, typename V>
int hash_map<K, V>::size()
{
    int ret = 0;
    for (auto &item : _data)
        ret += item.size();

    return ret;
}

int main()
{
    hash_map<string, string> myMap(7);

    myMap.insert("hhj", "123");
    myMap.insert("jhh", "333");
    myMap.insert("jhh", "333");
    myMap.insert("a", "333");
    myMap.insert("d", "333");
    myMap.insert("e", "333");
    cout << myMap.find("hhj") << endl;
    cout << myMap.find("sss") << endl;
    cout << myMap.size() << endl;
    myMap.PrintInfo();
    cout << endl;

    hash_map<string, int> myMap2(7);

    myMap2.insert("hhj", 123);
    myMap2.insert("jhh", 333);
    cout << myMap2.find("hhj") << endl;
    cout << myMap2.find("sss") << endl;
    cout << myMap2.size() << endl;
    myMap2.PrintInfo();
}