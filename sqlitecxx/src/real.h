/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * real.h
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

#ifndef REAL_H
#define REAL_H

#include <base.h>

#define SQLITECXX_REAL "sqlitecxx::real::"

/**
 * @brief Real<T>. Floating point value, stored as an 8-byte IEEE
 *        floating point number.
 * @tparam T - float | double.
 */
template <class T>
class Real final : Base<T> {

  public:
    /**
     * @brief Default Constructor is not allowed.
     */
    Real() = delete;

    /**
     * @brief Construct a new Real<T> object.
     * @param payload value for floating data.
     */
    explicit Real(T payload) : Base<T>(payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " user defined cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Real<T> object.
     * @param source reference to Real<T> object for copy. 
     */
    Real(Real<T>& source) : Base<T>(source.payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " Real<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Copy Constructor for a new Real<T> object.
     * @param source const reference to Real<T> object for copy. 
     */
    Real(const Real<T>& source) : Base<T>(source.payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " const Real<T>";
      std::cout << " copy cstor " << this << std::endl;
#endif
    }

    /**
     * @brief Destructor for Real<T> object.
     */
    ~Real() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " default dstor " << this << std::endl;
#endif
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Getters and setters
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Get the sql type object
     * @return std::string SQL type in string form.
     */
    static std::string get_sql_type() {
      return "Real";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Assignment operators
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
     * @brief Assignment operator (fundamental data to Real<T>).
     * @param payload payload for floating data.
     */
    void operator=(T payload) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " floating";
      std::cout << " arg : " << payload;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = payload;
    }

    /**
     * @brief Assignment operator (Real<T> to Real<T>).
     * @param source reference to Real<T> object.
     */
    void operator=(Real<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " Real<T>";
      std::cout << " arg : " << source.payload;
      std::cout << " at " << &source;
      std::cout << " to " << this << std::endl;
#endif
      this->payload = source.payload;
    }

    /**
     * @brief Assignment operator (Real<T> to Real<T>).
     * @param source const reference to Real<T> object.
     */
    void operator=(const Real<T>& source) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " const Real<T>";
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
     * @return Real<T> & represent reference to Real<T>.
     */
    Real<T>& operator++() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " prefix";
      std::cout << " at " << this << std::endl;
#endif
      ++(this->payload);
      return *this;
    }

    /**
     * @brief Prefix decrement operator.
     * @return Real<T> & represent reference to Real<T>.
     */
    Real<T>& operator--() {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " prefix";
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
     * @return Real<T> represent dummy Real<T> object with old value.
     */
    Real<T> operator++(int) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " postfix";
      std::cout << " at " << this << std::endl;
#endif
      Real<T> temp{*this};
      ++*this; /* Invoke prefix operator */
      return temp;
    }

    /**
     * @brief Postfix decrement operator.
     * @return Real<T> represent dummy Real<T> object with old value.
     */
    Real<T> operator--(int) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__ << " postfix";
      std::cout << " at " << this << std::endl;
#endif
      Real<T> temp{*this};
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
     * @param source const reference to right operand Real<T> object.
     * @return Real<T> represent result Real<T> object.
     */
    Real<T> operator+(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Real<T> temp{0};
      temp.payload = (
          (this->payload) + (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary - operator.
     * @param source const reference to right operand Real<T> object.
     * @return Real<T> represent result Real<T> object.
     */
    Real<T> operator-(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Real<T> temp{0};
      temp.payload = (
          (this->payload) - (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary * operator.
     * @param source const reference to right operand Real<T> object.
     * @return Real<T> represent result Real<T> object.
     */
    Real<T> operator*(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Real<T> temp{0};
      temp.payload = (
          (this->payload) * (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary / operator.
     * @param source const reference to right operand Real<T> object.
     * @return Real<T> represent result Real<T> object.
     */
    Real<T> operator/(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      Real<T> temp{0};
      temp.payload = (
          (this->payload) / (other.payload)
      );
      return temp;
    }

    /**
     * @brief Binary != operator.
     * @param source const reference to right operand Real<T> object.
     * @return bool true for not equal else false.
     */
    bool operator!=(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) != (other.payload);
    }

    /**
     * @brief Binary == operator.
     * @param source const reference to right operand Real<T> object.
     * @return bool true for equal else false.
     */
    bool operator==(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) == (other.payload);
    }

    /**
     * @brief Binary >= operator.
     * @param source const reference to right operand Real<T> object.
     * @return bool true for greater or equal else false.
     */
    bool operator>=(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) >= (other.payload);
    }

    /**
     * @brief Binary <= operator.
     * @param source const reference to right operand Real<T> object.
     * @return bool true for less or equal else false.
     */
    bool operator<=(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) <= (other.payload);
    }

    /**
     * @brief Binary > operator.
     * @param source const reference to right operand Real<T> object.
     * @return bool true for greater else false.
     */
    bool operator>(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
      std::cout << " at " << this << std::endl;
#endif
      return (this->payload) > (other.payload);
    }

    /**
     * @brief Binary < operator.
     * @param source const reference to right operand Real<T> object.
     * @return bool true for less else false.
     */
    bool operator<(const Real<T>& other) {
#if SQLITECXX_VERBOSE == SQLITECXX_VERBOSE_ENABLED
      std::cout << SQLITECXX_REAL << __func__;
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
     * @brief Add Real<T> object to output stream.
     * @param out represent stream which will be updated.
     * @return std::ostream & represent outout stream.
     */
    friend std::ostream &
    operator<<(std::ostream &out, const Real<T> &real) {
	out << "Real [" << std::endl;
      out << " payload : " << real.payload << std::endl;
      out << "] at " << &real << std::endl;
	return out;
    }
};

#endif
