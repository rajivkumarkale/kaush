#pragma once

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef char b8;
typedef int b32;

// Clang assertions:
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Assertions to check, all types are of correct size.
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u8 to be 2 byte.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u8 to be 4 byte.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u8 to be 8 byte.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected u8 to be 2 byte.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected u8 to be 4 byte.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected u8 to be 8 byte.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected u8 to be 4 byte.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected u8 to be 8 byte.");

STATIC_ASSERT(sizeof(b8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(b32) == 4, "Expected u8 to be 4 byte.");

#define TRUE 1
#define FALSE 0

// Plaform Detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define KPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define KPLATFORM_LINUX 1
#else
#error "Unkown platform!"
#endif

#ifdef KEXPORT
// Exports
#ifdef _MSC_VER
#define KAPI _declspec(dllexport)
#else
#define KAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define KAPI __declspec(dllimport)
#else
#define KAPI
#endif
#endif