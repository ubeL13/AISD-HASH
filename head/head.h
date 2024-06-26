#include <iostream>
#include <random>
#include <cstdlib>
#include<array>
#include <cstdint>




template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;

    Node(K k, V v) : key(k), value(v), next(nullptr) {}
};

template<typename K, typename V>
class UnorderedMap {
private:
    Node<K, V>** table;
    size_t tableSize;

    size_t hashFunction(K key) const {
        return static_cast<size_t>(key) % tableSize;
    }

public:
    UnorderedMap(size_t size) : tableSize(size) {
        table = new Node<K, V>* [tableSize];
        for (size_t i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    UnorderedMap(const UnorderedMap<K, V>& other) : tableSize(other.tableSize) {
        table = new Node<K, V>* [tableSize];
        for (size_t i = 0; i < tableSize; ++i) {
            if (other.table[i] == nullptr) {
                table[i] = nullptr;
            }
            else {
                Node<K, V>* current = other.table[i];
                Node<K, V>* newChain = new Node<K, V>(current->key, current->value);
                table[i] = newChain;

                while (current->next != nullptr) {
                    current = current->next;
                    newChain->next = new Node<K, V>(current->key, current->value);
                    newChain = newChain->next;
                }
            }
        }
    }

    UnorderedMap(size_t size, size_t numElements, K keyMin, K keyMax, V valueMin, V valueMax) : tableSize(size) {
        table = new Node<K, V>* [tableSize];
        for (size_t i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<K> distribKey(keyMin, keyMax);
        std::uniform_int_distribution<V> distribValue(valueMin, valueMax);

        for (size_t i = 0; i < numElements; ++i) {
            K randomKey = distribKey(gen);
            V randomValue = distribValue(gen);
            insert(randomKey, randomValue);
        }
    }

    ~UnorderedMap() {
        clear();
    }

    UnorderedMap<K, V>& operator=(UnorderedMap<K, V> other) {
        clear();
        table = other.table;
        tableSize = other.tableSize;
        other.table = nullptr;
        other.tableSize = 0;

        return *this;
    }

    void clear() {
        for (size_t i = 0; i < tableSize; ++i) {
            Node<K, V>* current = table[i];
            while (current != nullptr) {
                Node<K, V>* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] table;
    }

    void print() {
        for (size_t i = 0; i < tableSize; ++i) {
            Node<K, V>* current = table[i];
            while (current != nullptr) {
                std::cout << "{" << current->key << ", " << current->value << "}, " << std::endl;
                current = current->next;
            }
        }
    }
  
    void insert(K key, V value) {
        if (search(key) != nullptr) {
            return;
        }
        size_t idx = hashFunction(key);
        Node<K, V>* node = new Node<K, V>(key, value);
        if (table[idx] == nullptr) {
            table[idx] = node;
        }
        else {
            Node<K, V>* current = table[idx];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void insert_or_assign(K key, V value) {
        size_t idx = hashFunction(key);
        Node<K, V>* current = table[idx];
        while (current) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        insert(key, value);
    }

    bool contains(V value) {
        for (size_t i = 0; i < tableSize; ++i) {
            Node<K, V>* current = table[i];
            while (current != nullptr) {
                if (current->value == value) {
                    return true;
                }
                current = current->next;
            }
        }
        return false;
    }

    V* search(K key) {
        size_t idx = hashFunction(key);
        Node<K, V>* current = table[idx];
        while (current) {
            if (current->key == key) {
                return &(current->value);
            }
            current = current->next;
        }
        return nullptr;
    }

    bool erase(K key) {
        size_t idx = hashFunction(key);
        Node<K, V>* current = table[idx];
        Node<K, V>* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    table[idx] = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }


    int count(K key) {
        size_t idx = hashFunction(key);
        Node<K, V>* current = table[idx];
        int count = 0;
        while (current) {
            if (current->key == key) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

};

std::vector<int> generateRandomVector() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    std::vector<int> vec(100);

    for (auto& i : vec) {
        int randomValue = distrib(gen);
        i = randomValue;
    }
    return vec;
}

UnorderedMap<int, int> count_numbers(const std::vector<int>& vec) {
    UnorderedMap<int, int> map(vec.size());
    for (auto& i : vec) {
        int* count = map.search(i);
        if (count == nullptr) {
            map.insert(i, 1);
        }
        else {
            (*count)++;
        }
    }
    return map;
}

void print_numbers_count(UnorderedMap<int, int>& table) {
    for (int i = 1; i <= 100; i++) {
        int* count_ptr = table.search(i);
        if (count_ptr != nullptr) {
            std::cout << "Number " << i << " counts " << *count_ptr << " times" << std::endl;
        }
    }
}