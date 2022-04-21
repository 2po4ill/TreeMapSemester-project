#pragma once

// Заголовочный файл с объявлением структуры данных
#include "node.hpp"
#include <optional>

namespace itis {

  struct Treemap final //конструктор тримапы
  {
    Treemap() = default;
    ~Treemap(); //clear
    void Insert(int key, int value); //добавление узла в дерево
    bool Remove(int key); //удаление узла по ключу
    void Clear(); //clear
    std::optional<int> Search(int key) const; //поиск узла по ключу
    bool Contains(int key) const; //проверка на нахождение узла в дереве
    bool IsEmpty() const; //проверка на очистку дерева
    Node *root() const; //корневой узел
    bool Balance();

   private:
    Node *root_{nullptr}; //объявление корня тримапы

    // вспомогательные методы
    void insert(int key, int value, Node *&node);
    bool balance(Node* node);
    bool remove(int key, Node *&node);
    void clear(Node *node);
    Node *search(int key, Node *node) const;
    Node *search_min(Node *node) const;
  };

}  // namespace itis

  // namespace itis