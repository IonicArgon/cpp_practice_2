#pragma once
#include <concepts>
#include <cstdlib>
#include <functional>
#include <list>
#include <stdexcept>
#include <utility>

template <class Tk, class Tv, int N>
class HashMap {
 public:
  using HashFunc = std::function<int(const Tk&)>;

  HashMap(HashFunc hashFunc) : hash(hashFunc) {};
  HashMap(const HashMap<Tk, Tv, N>& ref) : hash(ref.hash) {
    for (int i = 0; i < N; ++i) {
      this->table[i] = ref.table[i];
    }
  };
  HashMap& operator=(const HashMap<Tk, Tv, N>& ref) {
    if (this != &ref) {
      for (int i = 0; i < N; ++i) {
        this->table[i] = ref.table[i];
      }
      this->hash = ref.hash;
    }
    return *this;
  };
  ~HashMap() = default;

  void insert(const Tk& key, const Tv& val) {
    size_t index = hash(key) % N;
    table[index].push_back(std::make_pair(key, val));
  };
  bool erase(const Tk& key) {
    size_t index = hash(key) % N;

    for (auto it = this->table[index].begin(); it != this->table[index].end();
         ++it) {
      if (it->first == key) {
        this->table[index].erase(it);
        return true;
      }
    }

    return false;
  };
  Tv& operator[](const Tk& key) {
    size_t index = hash(key) % N;
    for (auto& pair : this->table[index]) {
      if (pair.first == key) {
        return pair.second;
      }
    }

    throw std::out_of_range("Key not found in HashMap");
  };

 private:
  std::list<std::pair<Tk, Tv>> table[N];
  const HashFunc hash;
};
