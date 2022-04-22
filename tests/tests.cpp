#include <catch2/catch.hpp>

#include "data_structure.hpp"  // Treemap

using namespace itis;

TEST_CASE("Treemap constructor") {

  Treemap treemap;

  CHECK(treemap.IsEmpty());
  CHECK(treemap.root() == nullptr);
}
