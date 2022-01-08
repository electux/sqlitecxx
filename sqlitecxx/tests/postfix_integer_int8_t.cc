/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * postfix_integer_int8_t.cc
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
    // Checking postfix increment/decrement !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // ===> int8_t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Integer<int8_t> myint {0};
    ssize_t counter{0};
    do {
        std::cout << myint << std::endl;
        std::cout << myint++ << std::endl;
        std::cout << "counter : " << counter << std::endl;
        ++counter;
        std::cout << "-----------------------------------" << std::endl; 
    } while(counter <= UINT8_MAX);
    return 0;
}
