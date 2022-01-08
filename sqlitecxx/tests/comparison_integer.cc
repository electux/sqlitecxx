/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * comparison_integer.cc
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
    // Checking comparison operators !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Integer<int> myint{3456};
    Integer<int> myint2{345};
    if (myint > myint2) {
        std::cout << "myint is greater" << std::endl;
    }
    if (myint < myint2) {
        std::cout << "myint2 is greater" << std::endl;
    }
    if (myint == myint2) {
        std::cout << "myint == myint2" << std::endl;
    }
    if (myint <= myint2) {
        std::cout << "myint <= myint2" << std::endl;
    }
    if (myint >= myint2) {
        std::cout << "myint >= myint2" << std::endl;
    }
    if (myint != myint2) {
        std::cout << "myint != myint2" << std::endl;
    }
    std::cout << myint << std::endl;
    std::cout << myint2 << std::endl;
    return (0);
}
