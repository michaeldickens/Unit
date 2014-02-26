/* 
 * Reusable unit test framework in C++.
 * 
 * Created by Michael Dickens on 5/15/13.
 */

#ifndef __UNIT_HPP__
#define __UNIT_HPP__

#include <iostream>
#include <string>

/* 
 * Compare expected to found. If they are not equal according to the
 * == function, print the message.
 * 
 * Return (expected == found).
 */
template <class T>
bool verify(T expected, T found, std::string message)
{
    if (!(expected == found)) {
        std::cerr << message << ": (" << expected << ") expected, (" << 
            found << ") found. ####ERROR####" << std::endl;
    }

    return expected == found;
}

/* 
 * Given a predicate, verify that it is true.
 */
bool verify(bool pred, std::string message)
{
    return verify(true, pred, message);
}

/* 
 * Call verify(expr). If the test fails, print an error message
 * including the expression.
 */
#define VERIFY(expr) (verify((expr), #expr))


#endif /* #ifndef __UNIT_HPP__ */
