#include <cstdlib> 

template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;

    Node(K k, V v) : key(k), value(v), next(NULL) {}
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
            table[i] = NULL;
        }
    }



    UnorderedMap(const UnorderedMap<K, V>& other) : tableSize(other.tableSize) {
        table = new Node<K, V>* [tableSize];
        for (size_t i = 0; i < tableSize; ++i) {
            if (other.table[i] == NULL) {
                table[i] = NULL;
            }
            else {
                Node<K, V>* current = other.table[i];
                Node<K, V>* newChain = new Node<K, V>(current->key, current->value);
                table[i] = newChain;

                while (current->next != NULL) {
                    current = current->next;
                    newChain->next = new Node<K, V>(current->key, current->value);
                    newChain = newChain->next;
                }
            }
        }
    }

    ~UnorderedMap() {
        for (size_t i = 0; i < tableSize; ++i) {
            Node<K, V>* current = table[i];
            while (current != NULL) {
                Node<K, V>* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] table;
    }

    UnorderedMap<K, V>& operator=(const UnorderedMap<K, V>& other) {
        if (this != &other) {
            for (size_t i = 0; i < tableSize; ++i) {
                Node<K, V>* current = table[i];
                while (current != NULL) {
                    Node<K, V>* toDelete = current;
                    current = current->next;
                    delete toDelete;
                }
            }
            delete[] table;
            tableSize = other.tableSize;
            table = new Node<K, V>* [tableSize];
            for (size_t i = 0; i < tableSize; ++i) {
                if (other.table[i] == NULL) {
                    table[i] = NULL;
                }
                else {
                    Node<K, V>* current = other.table[i];
                    Node<K, V>* newChain = new Node<K, V>(current->key, current->value);
                    table[i] = newChain;

                    while (current->next != NULL) {
                        current = current->next;
                        newChain->next = new Node<K, V>(current->key, current->value);
                        newChain = newChain->next;
                    }
                }
            }
        }
        return *this;
    }
};
