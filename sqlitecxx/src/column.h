/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * column.h
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

#ifndef COLUMN_H
#define COLUMN_H

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include "verbose.h"

#define SQLITECXX_COLUMN "sqlitecxx::column::"

template <class T>
class Column final {

  std::string name{};
  std::string type{};
  bool primary_key{false};
  std::list<T> data;
  
  public:

    Column() = delete;

    explicit Column(std::string name, bool primary_key)
    : name{name}, type{T::get_sql_type()}, primary_key{primary_key} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " user defined cstor " << this << std::endl;
#endif
    }

    Column(Column<T>& source)
    :  name{source.name}, type{source.type}, primary_key{source.primary_key} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__ << " Column<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    Column(const Column<T>& source)
    :  name{source.name}, type{source.type}, primary_key{source.primary_key} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__ << " const Column<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    ~Column() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " default dstor " << this << std::endl;
#endif
    }

    std::string& get_name() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return this->name;
    }

    void set_name(std::string name) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " arg : " << name;
      std::cout << " at " << this << std::endl;
#endif
      this->name = name;
    }

    std::string& get_type() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return this->type;
    }

    void set_type(std::string type) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " arg : " << type;
      std::cout << " at " << this << std::endl;
#endif
      this->type = type;
    }

    bool& get_primary_key() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return this->primary_key;
    }

    void set_primary_key(bool primary_key) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_COLUMN << __func__;
      std::cout << " arg : " << primary_key;
      std::cout << " at " << this << std::endl;
#endif
      this->primary_key = primary_key;
    }

    std::list<T>& get_data() {
      return this->data;
    }

    void insert_data(const T& data) {
      this->data.push_front(data);
    }

    friend std::ostream &
    operator<<(std::ostream &out, const Column<T> &column) {
      out << "Column [" << std::endl;
      out << " name : " << column.name << std::endl;
      out << " type : " << column.type << std::endl;
      out << " primary key : " << column.primary_key << std::endl;
      out << "] at " << &column << std::endl;
      return out;
    }
};

#endif
