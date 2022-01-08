/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * sqlitecxx.cc
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

#include <iostream>
#include "sqlitecxx.h"

/**
 * @brief Construct a new SQLiteCXX::SQLiteCXX object
 * 
 * @param database_name 
 */
SQLiteCXX::SQLiteCXX(std::string database_name)
: db_name{database_name} {
    this->db_status = sqlite3_open(this->db_name.c_str(), &(this->db));
    std::cout << "Opened Database Successfully!" << std::endl;
}

/**
 * @brief Destroy the SQLiteCXX::SQLiteCXX object
 * 
 */
SQLiteCXX::~SQLiteCXX() {
    sqlite3_close(this->db);
    std::cout << "Closed Database Successfully!" << std::endl;
}

int SQLiteCXX::create_table(std::string sql_create_table) {
    int status{0};
    char* messaggeError;
    status = sqlite3_exec(
        this->db, sql_create_table.c_str(), nullptr, 0, &messaggeError
    );
    if (status != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    return status;
}
