// -*- C++ -*-
// $Id: Base_Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef CS36300_SPRING2018_COMPOSITION_BASE_ARRAY_H
#define CS36300_SPRING2018_COMPOSITION_BASE_ARRAY_H

#include <glob.h>
#include <cstring>          // for size_t definition
#include <iostream>
#include <stdexcept>
#include "Array_Iterator.h"


template <typename T>
class Base_Array {
    /*This is the base array class from which Fixed array and array inherit from*/
    friend class Array_Iterator<T>;

public:
    /*Base class default constructor*/
    Base_Array(void);

    /*Base class Init constructor for length*/
    Base_Array(size_t length);

    /*Initializing constructor*/
    Base_Array(size_t length,T fill);

    /*Copy Constructor*/
    Base_Array(const Base_Array & arr);

    ~Base_Array();

    /*fill the array*/
    void fill(T fill);

    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    const Base_Array & operator = (const Base_Array & rhs);

    /**
   * Get the character at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   * @exception       std::out_of_range     Invalid index value
   */

    /**
   * Get the character at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
   */
    T & operator [] (size_t index);

    /**
     * @overload
     *
     * The returned character is not modifiable.
     */
    const T & operator [] (size_t index) const;

    /**
   * Get the character at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   * @exception       std::out_of_range     Invalid index value
   */
    T get (size_t index) const;

    /**
   * Set the character at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   * @exception       std::out_of_range     Invalid \a index value
   */
    void set (size_t index, T value);

    /**
     * Locate the specified character in the array. The index of the first
     * occurrence of the character is returned. If the character is not
     * found in the array, then -1 is returned.
     *
     * @param[in]        ch        Character to search for
     * @return           Index value of the character
     * @retval           -1        Character not found
     */
    int find (T item) const;

    /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       ch                   Character to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Character not found
   * @exception       std::out_of_range    Invalid index
   */
    int find (T item, size_t start) const;

    /// Reverse the contents of the array such that the first element is now
    /// the last element and the last element is the first element.
    void reverse ();

    /**
     * Test the array for equality.
     *
     * @param[in]       rhs                  Right hand side of equal to sign
     * @retval          true                 Left side is equal to right side
     * @retval          false                Left side is not equal to right side
     */
    bool operator == (const Base_Array & rhs) const;

    /**
     * Test the array for inequality.
     *
     * @param[in]       rhs                  Right-hand size of not equal to sign
     * @retval          true                 Left side is not equal to right side
     * @retval          false                Left size is equal to right side
     */
    bool operator != (const Base_Array & rhs) const;

    /**
    * Retrieve the current size of the array.
    *
    * @return          The current size
    */
    size_t size (void) const;


    void print();


protected:
    T * data_;
    size_t size_;
    //size_t max_size_;

};

#include "Base_Array.inl"
#include "Base_Array.cpp"

#endif //CS36300_SPRING2018_COMPOSITION_BASE_ARRAY_H
