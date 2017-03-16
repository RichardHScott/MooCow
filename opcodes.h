#pragma once


namespace MooCow {

constexpr int NOP = 0;

constexpr int INTEGER_ADD = 1;
constexpr int INTEGER_SUB = 2;
constexpr int INTEGER_MUL = 3;
constexpr int INTEGER_DIV = 4;

constexpr int LOAD_CONST = 0x10;
constexpr int STORE_CONST = 0x11;

constexpr int RETURN = 0x20;

constexpr int PRINT = 0xFF;

}
