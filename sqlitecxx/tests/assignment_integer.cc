/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * assignment_integer.cc
 * Copyright (C) 2022 Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 * sqlitecxx is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * sqlitecxx is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <integer.h>

TEST(IntegerTest, FundamentalAssignment) {
  ///////////////////////////////////////////////////////////////////////////
  // Assignment operator !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Integer<int> myint{0};
  myint = 14;
  ASSERT_EQ(14, myint.get());
}

TEST(IntegerTest, ObjectAssignment) {
  ///////////////////////////////////////////////////////////////////////////
  // Assignment operator !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Integer<int> myint2 {0};
  Integer<int> myint3 {5};
  myint2 = myint3;
  ASSERT_EQ(5, myint2.get());
  ASSERT_EQ(5, myint3.get());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
