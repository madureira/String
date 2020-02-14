# String
A lightweight, dependency-free and header only C++ custom string.

[![language](https://img.shields.io/badge/language-c++-blue.svg)](https://isocpp.org)

## Install

Just add the `String.h` to your project or include path.

## How to use

```c++
#include "String.h"

String text("Hello, world!");
```

## Features

| Methods                                              | Return             | Description                                                                                                                  |
| ---------------------------------------------------- | ------------------ | ---------------------------------------------------------------------------------------------------------------------------- |
| String()                                             | Instance of String | (Constructor) Create an empty new instance of the String class.                                                              |
| String(String& string)                               | Instance of String | (Constructor) Create a new instance of the String class based on an existent String reference.                               |
| String(const char* cString)                          | Instance of String | (Constructor) Create a new instance of the String class based on an existent C string pointer.                               |
| Size()                                               | int                | Returns the String length.                                                                                                   |
| c_str()                                              | const char*        | Returns the C string pointer.                                                                                                |
| Equals(String& other)                                | bool               | Compare the current String with another and return true if they are the same or false, otherwise.                            |
| Equals(const char* other)                            | bool               | Compare the current String with a C string and return true if they are the same or false, otherwise.                         |
| Index(char c)                                        | int                | Returns the position of the first occurrence of a specified value in a string or -1 if the value to search for never occurs. |
| Concat(const String& string)                         | String&            | Join the current String with another String value and returns its reference.                                                 |
| Concat(const char* string)                           | String&            | Join the current String with another C string value and returns its reference.                                               |
| ToUpperCase()                                        | String&            | Converts a string to uppercase letters and returns its reference.                                                            |
| ToLowerCase()                                        | String&            | Converts a string to lowercase letters and returns its reference.                                                            |
| Find(String& string)                                 | int                | Searches a string for a specified value, and returns the position of the match.                                              |
| Find(const char* cString)                            | int                | Searches a string for a specified value, and returns the position of the match.                                              |
| Replace(String& target, String& replacement)         | String&            | Searches a string for a specified value, and replace it by another given string and returns its reference.                   |
| Replace(String& target, const char* replacement)     | String&            | Searches a string for a specified value, and replace it by another given string and returns its reference.                   |
| Replace(const char* target, String& replacement)     | String&            | Searches a string for a specified value, and replace it by another given string and returns its reference.                   |
| Replace(const char* target, const char* replacement) | String&            | Searches a string for a specified value, and replace it by another given string and returns its reference.                   |

## Examples

### Creating a empty String:

```cpp
String emptyString;
```

### Creating a new String:

```cpp
String text("foo");
```

### Copy existent String value by constructor:

```cpp
String text("foo");

String anotherText(text);
```

### Get the length of a String:

```cpp
String text("foo");

text.Size(); // 3
```

### Print the String:

```cpp
String text("foo");

std::cout << text.c_str() << std::endl; // foo

printf("%s", text.c_str()); // foo
```

### Comparing Strings:

```cpp
String foo("foo");

String bar("bar");

bool isEquals = foo.Equals(bar); // false

isEquals = foo.Equals("bar"); // false

isEquals = (foo == bar); // false

isEquals = (foo == "bar"); // false

isEquals = (foo.Equals("foo")); // true

isEquals = (bar == "bar"); // true
```

### Retrieving the position of the first occurrence char:

```cpp
String text("Hello, world!");

int index = text.Index(','); // 5

int notfound = text.Index('$'); // -1
```

### Concatenate Strings:

```cpp
String foo("foo");
String bar(" bar");

foo.Concat(bar).Concat("!!!");

printf("%s", foo); // foo bar!!!
```

### Converts a String to uppercase letters:

```cpp
String text("foo");
text.ToUpperCase(); // FOO
```

### Converts a String to lowercase letters:

```cpp
String text("BAR");
text.ToUpperCase(); // bar
```

### Finds the position of the first occurrence of a value in a String:

```cpp
String text("Some amazing text");

int index = text.Find("amazing"); // 5

String another("Some");
int position = text.Find(another); // 0

int notfound = text.Find("xyz"); // -1
```

### Replace the position of the first occurrence of value by another one:

```cpp
String text("Some amazing text");

text.Replace("amazing", "silly"); // Some silly text
```
