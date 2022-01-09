/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * integer.h
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

#ifndef INTEGER_H
#define INTEGER_H

#include <cstdint>
#include <base.h>

#define SQLITECXX_INTEGER "sqlitecxx::integer::"

/**
 * @brief Integer<T>. Signed integer, stored in: 1, 2, 3, 4, 6, or 8 bytes
 *        depending on the magnitude of the value.
 * @tparam T - int8_t | int16_t | int32_t | int64_t | short | int | long.
 */
template <class T>
class Integer final : Base<T> {

  public:
    /**
     * @brief Default Constructor is not allowed.
     */
    Integer() = delete;

    /**
     * @brief Construct a new Integer<T> object.
     * @param payload value for integral data.
     */
    explicit Integer(T payload) : Base<T>(payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " user defined cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Integer<T> object.
     * @param source reference to Integer <T> object for copy. 
     */
    Integer(Integer<T>& source) : Base<T>(source.payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " Integer<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Integer<T> object.
     * @param source const reference to Integer<T> object for copy. 
     */
    Integer(const Integer<T>& source) : Base<T>(source.payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " const Integer<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Destructor for Integer<T> object.
     */
    ~Integer() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " default dstor " << this << std::endl;
#endif
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Getters and setters
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Get the sql type object.
     * @return std::string SQL type in string form.
     */
    static std::string get_sql_type() {
      return "Integer";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Assignment operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Assignment operator (fundamental data to Integer<T>).
     * @param payload payload for integral data.
     */
    void operator=(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " integral";
      std::cout << " arg : " << payload;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = payload;
    }

    /**
     * @brief Assignment operator (Integer<T> to Integer<T>).
     * @param source reference to Integer<T> object.
     */
    void operator=(Integer<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " Integer<T>";
      std::cout << " arg : " << source.payload;
      std::cout << " at " << &source;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = source.payload;
    }

    /**
     * @brief Assignment operator (Integer<T> to Integer<T>).
     * @param source const reference to Integer<T> object.
     */
    void operator=(const Integer<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " const Integer<T>";
      std::cout << " arg : " << source.payload;
      std::cout << " at " << &source;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = source.payload;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Prefix incrementer/decrementer operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Prefix increment operator.
     * @return Integer<T> & represent reference to Integer<T>.
     */
    Integer<T>& operator++() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " prefix";
      std::cout << " at " << this << std::endl;
#endif
      ++(this->payload);
      return *this;
    }

    /**
     * @brief Prefix decrement operator.
     * @return Integer<T> & represent reference to Integer<T>.
     */
    Integer<T>& operator--() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " prefix";
      std::cout << " at " << this << std::endl;
#endif
      --(this->payload);
      return *this;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Postfix incrementer/decrementer operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Postfix increment operator.
     * @return Integer<T> represent dummy Integer<T> object with old value.
     */
    Integer<T> operator++(int) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " postfix";
      std::cout << " at " << this << std::endl;
#endif
      Integer<T> temp{*this};
      ++*this; /* Invoke prefix operator */
      return temp;
    }

    /**
     * @brief Postfix decrement operator.
     * @return Integer<T> represent dummy Integer<T> object with old value.
     */
    Integer<T> operator--(int) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__ << " postfix";
      std::cout << " at " << this << std::endl;
#endif
      Integer<T> temp{*this};
      --*this; /* Invoke prefix operator */
      return temp;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Binary + - * / != == >= <= > < operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Binary + operator. 
     * @param source const reference to right operand Integer<T> object.
     * @return Integer<T> represent result Integer<T> object.
     */
    Integer<T> operator+(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Integer<T> temp{0};
      temp.payload = (
          (this->payload) + (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary - operator.
     * @param source const reference to right operand Integer<T> object.
     * @return Integer<T> represent result Integer<T> object.
     */
    Integer<T> operator-(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Integer<T> temp{0};
      temp.payload = (
          (this->payload) - (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary * operator.
     * @param source const reference to right operand Integer<T> object.
     * @return Integer<T> represent result Integer<T> object.
     */
    Integer<T> operator*(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Integer<T> temp{0};
      temp.payload = (
          (this->payload) * (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary / operator.
     * @param source const reference to right operand Integer<T> object.
     * @return Integer<T> represent result Integer<T> object.
     */
    Integer<T> operator/(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Integer<T> temp{0};
      temp.payload = (
          (this->payload) / (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary != operator.
     * @param source const reference to right operand Integer<T> object.
     * @return bool true for not equal else false.
     */
    bool operator!=(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) != (other.payload);
    }

    /**
     * @brief Binary == operator.
     * @param source const reference to right operand Integer<T> object.
     * @return bool true for equal else false.
     */
    bool operator==(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) == (other.payload);
    }

    /**
     * @brief Binary >= operator.
     * @param source const reference to right operand Integer<T> object.
     * @return bool true for greater or equal else false.
     */
    bool operator>=(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) >= (other.payload);
    }

    /**
     * @brief Binary <= operator.
     * @param source const reference to right operand Integer<T> object.
     * @return bool true for less or equal else false.
     */
    bool operator<=(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) <= (other.payload);
    }

    /**
     * @brief Binary > operator.
     * @param source const reference to right operand Integer<T> object.
     * @return bool true for greater else false.
     */
    bool operator>(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) > (other.payload);
    }

    /**
     * @brief Binary < operator.
     * @param source const reference to right operand Integer<T> object.
     * @return bool true for less else false.
     */
    bool operator<(const Integer<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_INTEGER << __func__;
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
     * @brief Add Integer<T> object to output stream.
     * @param out represent stream which will be updated.
     * @return std::ostream & represent reference to outout stream.
     */
    friend std::ostream &
    operator<<(std::ostream &out, const Integer<T> &integer) {
      out << "Integer [" << std::endl;
      out << " payload : " << integer.payload << std::endl;
      out << "] at " << &integer << std::endl;
      return out;
    }
};

#endif
