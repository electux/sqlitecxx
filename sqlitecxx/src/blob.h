/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * blob.h
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

#ifndef BLOB_H
#define BLOB_H

#include <iostream>
#include "verbose.h" 

#define SQLITECXX_BLOB "sqlitecxx::blob::"

/**
 * @brief Blob<T>. Value is a blob of data, stored exactly as it was input.
 * @tparam T - int8_t | char.
 */
template <class T>
class Blob final {

    /**
     * @brief Payload for Blob<T> SQLite data.
     */
    T payload;

  public:
    /**
     * @brief Default Constructor is not allowed.
     */
    Blob() = delete;

    /**
     * @brief Construct a new Blob<T> object.
     * @param payload value for BLOB data.
     */
    explicit Blob(T payload) : payload{payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " user defined cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Blob<T> object.
     * @param source reference to Blob<T> object for copy. 
     */
    Blob(Blob<T>& source) : payload{source.payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__ << " Blob<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Blob<T> object.
     * @param source const reference to Blob<T> object for copy. 
     */
    Blob(const Blob<T>& source) : payload{source.payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__ << " const Blob<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Destructor for Blob<T> object.
     */
    ~Blob() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " default dstor " << this << std::endl;
#endif
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Getters and setters
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Getter for payload of Blob<T> data.
     * @return T represent BLOB datatype.
     */
    T& get() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return this->payload;
    }

    /**
     * @brief Setter for payload of Blob<T> data.
     * @param payload represent BLOB data.
     */
    void set(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " arg : " << payload;
      std::cout << " at " << this << std::endl;
#endif
      this->payload = payload;
    }

    /**
     * @brief Get the sql type object
     * @return std::string SQL type in string form.
     */
    static std::string get_sql_type() {
      return "Blob";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Assignment operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Assignment operator (std::string to Blob<T>).
     * @param payload payload for BLOB data.
     */
    void operator=(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__ << " BLOB";
      std::cout << " arg : " << payload;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = payload;
    }

    /**
     * @brief Assignment operator (Blob<T> to Blob<T>).
     * @param source reference to Blob<T> object.
     */
    void operator=(Blob<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__ << " Blob<T>";
      std::cout << " arg : " << source.payload;
      std::cout << " at " << &source;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = source.payload;
    }

    /**
     * @brief Assignment operator (Blob<T> to Blob<T>).
     * @param source const reference to Blob<T> object.
     */
    void operator=(const Blob<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__ << " const Blob<T>";
      std::cout << " arg : " << source.payload;
      std::cout << " at " << &source;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = source.payload;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Binary Binary + != == >= <= > < operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Binary + operator. 
     * @param source const reference to right operand Blob<T> object.
     * @return Blob<T> represent result Blob<T> object.
     */
    Blob<T> operator+(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Blob<T> temp{0};
      temp.payload = (
          (this->payload) + (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary != operator.
     * @param source const reference to right operand Blob<T> object.
     * @return bool true for not equal else false.
     */
    bool operator!=(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) != (other.payload);
    }

    /**
     * @brief Binary == operator.
     * @param source const reference to right operand Blob<T> object.
     * @return bool true for equal else false.
     */
    bool operator==(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) == (other.payload);
    }

    /**
     * @brief Binary >= operator.
     * @param source const reference to right operand Blob<T> object.
     * @return bool true for greater or equal else false.
     */
    bool operator>=(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) >= (other.payload);
    }

    /**
     * @brief Binary <= operator.
     * @param source const reference to right operand Blob<T> object.
     * @return bool true for less or equal else false.
     */
    bool operator<=(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) <= (other.payload);
    }

    /**
     * @brief Binary > operator.
     * @param source const reference to right operand Blob<T> object.
     * @return bool true for greater else false.
     */
    bool operator>(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) > (other.payload);
    }

    /**
     * @brief Binary < operator.
     * @param source const reference to right operand Blob<T> object.
     * @return bool true for less else false.
     */
    bool operator<(const Blob<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_BLOB << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) < (other.payload);
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // IO stream operations
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Add Blob<T> object to output stream.
     * @param out represent stream which will be updated.
     * @return std::ostream & represent outout stream.
     */
    friend std::ostream &
    operator<<(std::ostream &out, const Blob<T> &blob) {
	out << "Blob [" << std::endl;
      out << " payload : " << blob.payload << std::endl;
      out << "] at " << &blob << std::endl;
	return out;
    }
};

#endif
