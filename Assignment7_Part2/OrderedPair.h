#pragma once
#ifndef OrderedPair_h
#define OrderedPair_h


/* 
OrderedPair.h
Assignment 7, Part 2
Sangeet Satpathy
CS2B

This class stores a pair of 2 values of any type - as long as they are both the same data type.
The class also guarantees that the values will not be equal to each other; unless they are both
set to the starting value.


precondition for setFirst and setSecond: the argument cannot be such that the values of
first and second will become equal, unless the argument is equal to DEFAULT_VALUE.
*/


namespace cs_pairs {
    template <class T = int>
    class OrderedPair {
    public:
        static const T DEFAULT_VALUE;
        OrderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE);
        void setFirst(T newFirst);
        void setSecond(T newSecond);
        T getFirst() const;
        T getSecond() const;
        OrderedPair operator+(const OrderedPair<T>& right) const;
        bool operator<(const OrderedPair<T>& right) const;
        void print() const;
        class DuplicateMemberError{
        };
    private:
        T first;
        T second;
    };

}
#endif