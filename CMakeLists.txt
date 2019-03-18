cmake_minimum_required(VERSION 3.9)
project(cs36300_spring2018_calculator1)

set(CMAKE_CXX_STANDARD 11)

add_executable(cs36300_spring2018_calculator1
        Base_Array.h
        Base_Array.inl
        Array.h
        Array.inl
        Stack.h
        Stack.inl
        driver.cpp
        auto_ptr.h array_auto_ptr.h Array_Iterator.h Expr_Command.h Num_Command.h Binary_Op_Command.h Expr_Command_Factory.h Stack_Expr_Command_Factory.cpp Stack_Expr_Command_Factory.h Parentheses_Command.h Modulus_Command.h Calculator.cpp Calculator.h Expr_Command_Factory.cpp)