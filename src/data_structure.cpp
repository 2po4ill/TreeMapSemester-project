#include "data_structure.hpp"
#include "node.hpp"

// файл с определениями

namespace itis {

  Treemap::~Treemap()
  {
    Treemap::Clear();
  }

  void Treemap::Insert(int key, int value)
  {
    insert(key, value, root_);
  }

  bool Treemap::Remove(int key)
  {
    return remove(key, root_);
  }

  void Treemap::Clear()
  {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> Treemap::Search(int key) const
  {
    Node* current = search(key, root_);
    if (current == nullptr)
    {
      return std::nullopt;
    }
    return current->value;
  }

  bool Treemap::Contains(int key) const
  {
    Node* current = search(key, root_);
    if (current == nullptr)
    {
      return false;
    }
    return true;
  }

  bool Treemap::IsEmpty() const
  {
    if(root_ == nullptr) //тримапа считается пустой, когда ее корневой узел содержит нулевой указатель
    {
      return true;
    }
    return false;
  }

  Node* Treemap::root() const
  {
    return root_;
  }

  bool Treemap::Balance()
  {
    balance(root_);
    return true;
  }

  // вспомогательные методы

  void Treemap::insert(int key, int value, Node*& node)
  {
    if (node == nullptr) //если узла нет, то вставляем входящий узел, алгоритм закончил работу
    {
      Node* new_Node = new Node(key, value);
      node = new_Node;
    }
    if (key < node->key) //если ключ входящего узла меньше, узел уходит влево, идет рекурсия
    {
      insert(key, value, node->left);
    }
    else if (key > node->key) //если ключ входящего узла больше, узел уходит вправо, идет рекурсия
    {
      insert(key, value, node->right);
    }
    else if (key == node->key) //если ключ входящего узла равен, значение узлов заменяются, алгоритм закончил работу
    {
      node->value = value;
    }
  }

  bool Treemap::remove(int key, Node*& node)
  {
    if (node == nullptr)
    {
      return false;
    }
    if (key == node->key)
    {
      if (node->left != nullptr && node->right != nullptr) //если у удаляемого узла есть потомки, то заменяем его на минимальный правый потомок, повторяем рекурсивно
      {
        Node* minim = search_min(node->right);
        node->key = minim->key;
        node->value = minim->value;
        return remove(minim->key, node->right);
      }
      else if (node->left != nullptr) //если остается только левый узел, то сохраняем его значение, удаляем искомый, заменяем
      {
        Node* minchild = node->left;
        delete node;
        node = minchild;
        return true;
      }
      else
      {
        Node* maxchild = node->right; //если остается только правый узел, то сохраняем его значение, удаляем искомый, заменяем
        delete node;
        node = maxchild;
        return true;
      }
    }
    if (key < node->key) // рекурсивно ищем искомый узел
    {
      return remove(key, node->left);
    }
    return remove(key, node->right);
  }

  void Treemap::clear(Node* node)
  {
    if (node != nullptr)
    {
      clear(node->left);
      clear(node->right); //рекурсивно удаляем каждый узел начиная с потомков
      delete node;
    }
  }

  Node* Treemap::search(int key, Node* node) const //метод рекурсивного поиска узла
  {
    if (node == nullptr)
    {
      return nullptr;
    }

    if (key == node->key)
    {
      return node;
    }

    if (key < node->key)
    {
      return search(key, node->left);
    }

    if (key > node->key)
    {
      return search(key, node->right);
    }
  }

  Node* Treemap::search_min(Node* node) const
  {
    while (node->left != nullptr)
    {
      node = node->left;
    }
    return node;
  }

  bool Treemap::balance(Node* node)
  {

  }

}  // namespace itis