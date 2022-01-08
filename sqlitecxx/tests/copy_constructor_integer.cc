/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * copy_constructor_integer.cc
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

#include "integer.h"

int main(void) {
    ///////////////////////////////////////////////////////////////////////////
    // Checking Copy Constructor !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Integer<int> myint {0};
    Integer<int> myint2{myint};
    std::cout << "myint address : " << &myint << std::endl;
    std::cout << "myint val : " << myint.get() << std::endl;
    std::cout << "myint2 address : " << &myint2 << std::endl;
    std::cout << "myint2 val : " << myint2.get() << std::endl;
    myint.set(12);
    myint2.set(14);
    std::cout << "myint address : " << &myint << std::endl;
    std::cout << "myint val : " << myint.get() << std::endl;
    std::cout << "myint2 address : " << &myint2 << std::endl;
    std::cout << "myint2 val : " << myint2.get() << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    return (0);
}
