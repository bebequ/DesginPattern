/**
 * @file  example.cpp
 * Write description of source file here for doxygen
 * 
 * @brief Can use "brief" tag to explicitly generate comments for file documentation.
 * @author Jpark (jin.park@raon-tech.com)
 * @date September, 2015
 * @version 0.0
 */

/**
 * @class Animal
 * @brief parent class
 * @details This parent class 
 *
 * This API provides certain actions as an example.
 *
 * Example Usage:
 * @code 
 * @endcode
 */
class Animal
{
    public:
        void die();
        string name;
        int age;
};

/**
 * @brief child class 1
 *
 */
class Dog : public Animal
{
    public:
        void bark();
};

/**
 * @brief child class 2
 *
 */
class Cat : public Animal
{
    public:
        void meow();
};


