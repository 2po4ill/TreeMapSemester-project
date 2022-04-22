#include <catch2/catch.hpp>

#include "data_structure.hpp"  // Treemap

using namespace itis;

void check_children(const Node* node)
{
  CHECK(node->left == nullptr);
  CHECK(node->right == nullptr);
}

void check_node(const Node*node, int key, int value)
{
  CHECK(node->key == key);
  CHECK(node->value == value);
}

TEST_CASE("Treemap constructor")
{
  Treemap treemap;

  CHECK(treemap.IsEmpty());
  CHECK(treemap.root() == nullptr);
}

TEST_CASE("Treemap insert")
{
  Treemap tree;
  REQUIRE(tree.IsEmpty());

  // 0
  tree.Insert(4, 0);

  CHECK_FALSE(tree.IsEmpty());

  const Node* check = tree.root();

  REQUIRE(check_node != nullptr);
  check_children(check);
  check_node(check, 4, 0);

  // 1
  tree.Insert(2, 1);

  check = tree.root()->left;

  REQUIRE(check != nullptr);
  check_children(check);
  check_node(check, 2, 1);

  // 2
  tree.Insert(8, 2);

  check = tree.root()->right;

  REQUIRE(check != nullptr);
  check_children(check);
  check_node(check, 8, 2);

  // 3
  tree.Insert(1, 3);

  check = tree.root()->left->left;

  REQUIRE(check != nullptr);
  check_children(check);
  check_node(check, 1, 3);

  // 4
  tree.Insert(3, 4);

  check = tree.root()->left->right;

  REQUIRE(check_node != nullptr);
  check_children(check);
  check_node(check, 3, 4);

  // 5
  tree.Insert(9, 5);

  check = tree.root()->right->right;

  REQUIRE(check_node != nullptr);
  check_children(check);
  check_node(check, 9, 5);

  // 6
  tree.Insert(10, 6);

  check = tree.root()->right->right->right;

  REQUIRE(check != nullptr);
  check_children(check);
  check_node(check, 10, 6);

  // 7
  tree.Insert(6, 7);

  check = tree.root()->right->left;

  REQUIRE(check != nullptr);
  check_children(check);
  check_node(check, 6, 7);

  // 8
  tree.Insert(7, 8);

  check = tree.root()->right->left->right;

  REQUIRE(check != nullptr);
  check_children(check);
  check_node(check, 7, 8);

  // 9
  tree.Insert(5, 9);

  check = tree.root()->right->left->left;

  REQUIRE(check_node != nullptr);
  check_children(check);
  check_node(check, 5, 9);
}

TEST_CASE("Treemap remove")
{
  Treemap tree;

  tree.Insert(8, 1);
  tree.Insert(3, 2);
  tree.Insert(10, 3);
  tree.Insert(1, 4);
  tree.Insert(6, 5);
  tree.Insert(4, 6);
  tree.Insert(7, 7);
  tree.Insert(14, 8);
  tree.Insert(13, 9);

  REQUIRE_FALSE(tree.IsEmpty());
  REQUIRE(tree.root() != nullptr);

  SECTION("нет детей")
  {
    const int remove_key = GENERATE(1, 4, 7, 13);
    CHECK(tree.Remove(remove_key));
    CHECK_FALSE(tree.Contains(remove_key));
  }

  SECTION("1 ребенок")
  {
    const int remove_key = GENERATE(14, 10);
    CHECK(tree.Remove(remove_key));
    CHECK_FALSE(tree.Contains(remove_key));
  }
  SECTION("2 ребенка")
  {
    const int remove_key = GENERATE(3, 6, 8);
    CHECK(tree.Remove(remove_key));
    CHECK_FALSE(tree.Contains(remove_key));
  }
}

TEST_CASE("Treemap clear")
{
  Treemap tree;

  tree.Insert(8, 1);
  tree.Insert(3, 2);
  tree.Insert(10, 3);
  tree.Insert(1, 4);
  tree.Insert(6, 5);
  tree.Insert(4, 6);
  tree.Insert(7, 7);
  tree.Insert(14, 8);
  tree.Insert(13, 9);

  REQUIRE_FALSE(tree.IsEmpty());
  REQUIRE(tree.root() != nullptr);

  tree.Clear();

  CHECK(tree.IsEmpty());
  CHECK(tree.root() == nullptr);
}

TEST_CASE("Treemap search")
{
  Treemap tree;

  const auto keys = std::vector<int>{8, 3, 10, 1, 6, 14, 4, 7, 13};
  const auto values = std::vector<int>{0, 1, 2, 3, 4, 6, 9, 10, 13};

  for (int index = 0; index < keys.size(); ++index)
  {
    tree.Insert(keys[index], values[index]);
  }

  REQUIRE_FALSE(tree.IsEmpty());
  REQUIRE(tree.root() != nullptr);

  //существующие ключи
  for (int index = 0; index < keys.size(); ++index)
  {
    const auto search_exist = tree.Search(keys[index]);
    REQUIRE(search_exist.has_value());
    CHECK(search_exist.value() == values[index]);
  }

  const int key = GENERATE_REF(range(50, 100));

  CHECK_FALSE(tree.Search(key).has_value());
}

TEST_CASE("Treemap contains")
{
  Treemap tree;

  const auto keys = std::vector<int>{8, 3, 10, 1, 6, 14, 4, 7, 13};
  const auto values = std::vector<int>{0, 1, 2, 3, 4, 6, 9, 10, 13};

  for (int index = 0; index < keys.size(); ++index)
  {
    tree.Insert(keys[index], values[index]);
  }

  REQUIRE_FALSE(tree.IsEmpty());
  REQUIRE(tree.root() != nullptr);

  for (int key : keys)
  {
    CHECK(tree.Contains(key));
  }

  const int key = GENERATE_REF(range(50, 100));

  CHECK_FALSE(tree.Contains(key));
}