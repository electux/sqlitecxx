/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * text.h
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

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include "verbose.h" 

#define SQLITECXX_TEXT "sqlitecxx::text::"

/**
 * @brief Text<T>. Text string, stored using the database encoding (UTF-8).
 * @tparam T - std::string | std::string_view.
 */
template <class T>
class Text final {

    /**
     * @brief Payload for Text<T> SQLite data.
     */
    T payload;

  public:
    /**
     * @brief Default Constructor is not allowed.
     */
    Text() = delete;

    /**
     * @brief Construct a new Text<T> object.
     * @param payload value for text data.
     */
    explicit Text(T payload) : payload{payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " user defined cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Text<T> object.
     * @param source reference to Text<T> object for copy. 
     */
    Text(Text<T>& source) : payload{source.payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__ << " Text<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor a new Text<T> object.
     * @param source const reference to Text<T> object for copy. 
     */
    Text(const Text<T>& source) : payload{source.payload} {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__ << " const Text<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Destructor for Text<T> object.
     */
    ~Text() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " default dstor " << this << std::endl;
#endif
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Getters and setters
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Getter for payload of Text<T> data.
     * @return T represent reference to text data.
     */
    T& get() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return this->payload;
    }

    /**
     * @brief Setter for payload of Text<T> data.
     * @param payload represent text data.
     */
    void set(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " arg : " << payload;
      std::cout << " at " << this << std::endl;
#endif
      this->payload = payload;
    }

    /**
     * @brief Get the sql type object.
     * @return std::string SQL type in string form.
     */
    static std::string get_sql_type() {
      return "Text";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Assignment operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Assignment operator (string(s) to Text<T>).
     * @param payload payload for text data.
     */
    void operator=(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__ << " string(s)";
      std::cout << " arg : " << payload;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = payload;
    }

    /**
     * @brief Assignment operator (Text<T> to Text<T>).
     * @param source reference to Text<T> object.
     */
    void operator=(Text<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__ << " Text<T>";
      std::cout << " arg : " << source.payload;
      std::cout << " at " << &source;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = source.payload;
    }

    /**
     * @brief Assignment operator (Text<T> to Text<T>).
     * @param source Reference to Text<T> object.
     */
    void operator=(const Text<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__ << "Text<T>";
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
     * @param source right operand Text<T> object.
     * @return Text<T> result Text<T> object.
     */
    Text<T> operator+(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Text<T> temp{"None"};
      temp.payload = (
          (this->payload) + (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary != operator.
     * @param source right operand Text<T> object.
     * @return bool true for not equal else false.
     */
    bool operator!=(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) != (other.payload);
    }

    /**
     * @brief Binary == operator.
     * @param source right operand Text<T> object.
     * @return bool true for equal else false.
     */
    bool operator==(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) == (other.payload);
    }

    /**
     * @brief Binary >= operator.
     * @param source right operand Text<T> object.
     * @return bool true for greater or equal else false.
     */
    bool operator>=(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) >= (other.payload);
    }

    /**
     * @brief Binary <= operator.
     * @param source right operand Text<T> object.
     * @return bool true for less or equal else false.
     */
    bool operator<=(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) <= (other.payload);
    }

    /**
     * @brief Binary > operator.
     * @param source right operand Text<T> object.
     * @return bool true for greater else false.
     */
    bool operator>(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) > (other.payload);
    }

    /**
     * @brief Binary < operator.
     * @param source right operand Text<T> object.
     * @return bool true for less else false.
     */
    bool operator<(const Text<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_TEXT << __func__;
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
     * @brief Add Text<T> object to output stream.
     * @param out represent stream which will be updated.
     * @return std::ostream & represent outout stream.
     */
    friend std::ostream &
    operator<<(std::ostream &out, const Text<T> &text) {
      out << "Text [" << std::endl;
      out << " payload : " << text.payload << std::endl;
      out << "] at " << &text << std::endl;
      return out;
    }
};

#endif
