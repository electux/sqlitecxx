/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * sqlitecxx.h
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

#ifndef SQLITECXX_H
#define SQLITECXX_H

#include <string>
#include <memory>
#include <sqlite3.h>

/**
 * @brief 
 * 
 */
class SQLiteCXX {

std::string db_name{nullptr};
sqlite3* db{nullptr};
int db_status{0};

public:
    SQLiteCXX(std::string database_name);
    ~SQLiteCXX();
    int create_table(std::string sql_create_table);
};

#endif