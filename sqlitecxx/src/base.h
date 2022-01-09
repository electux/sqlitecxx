/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * base.h
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

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <verbose.h>

#define SQLITECXX_BASE "sqlitecxx::base::"

template <class T>
class Base {

  protected:
    /**
     * @brief Payload for Base<T> SQLite data.
     */
    T payload;

  public:
    /**
     * @brief Default Constructor is not allowed.
     */
    Base() = delete;

    /**
     * @brief Construct a new Base<T> object.
     * @param payload value for integral data.
     */
    explicit Base(T payload) : payload{payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BASE << __func__;
      std::cout << " user defined cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Base<T> object.
     * @param source reference to Base <T> object for copy. 
     */
    Base(Base<T>& source) : payload{source.payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BASE << __func__ << " Base<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Base<T> object.
     * @param source const reference to Base<T> object for copy. 
     */
    Base(const Base<T>& source) : payload{source.payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BASE << __func__ << " const Base<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Destructor for Base<T> object.
     */
    ~Base() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BASE << __func__;
      std::cout << " default dstor " << this << std::endl;
#endif
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Getters and setters
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Getter for payload of Base<T> data.
     * @return T represent integral datatype.
     */
    T& get() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BASE << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return this->payload;
    }

    /**
     * @brief Setter for payload of Base<T> data.
     * @param payload represent integral data.
     */
    void set(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BASE << __func__;
      std::cout << " arg : " << payload;
      std::cout << " at " << this << std::endl;
#endif
      this->payload = payload;
    }
};

#endif
