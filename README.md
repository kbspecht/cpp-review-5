# cpp-review-5

Constants defined to ensure value doesn't change (ex. gravitational acceleration), must be initialized when defined (can't change during assignment)
Named constants are associated with identifier, literal constants aren't
Can define named constant with constant variables, macros, or enums
Constant variable defined using const keyword before object type, must be initialized when defined (can't change during assignment), can change naming convention if wished (ex. all caps)
Can make function parameters constant, used to make sure parameter value doesn't change (don't need for non-reference/pointer parameters)
Can also make function return value constant (generally not needed)
Macro constants use preprocessor to replace macro name with defined value, not preferred (doesn't follow scoping rules)
Type qualifier is keyword that modifies behavior of type, const makes variable constant, volatile tells compiler that object may have value changed at any time
Literal is value inserted directly into code, ex. return 5, can add suffix to specify type ex. 5L is long
String is collection of sequential characters representing text, string literal placed in double quotes (vs. single quote char), ex. "hello world"
Strings can be C-style const char array (ends with null terminator '\0', ex. string literals) or std::string objects
Constant expression contains only compile time constants (value must be known at compile time)/operators & functions that support compile time evaluation, compiler can optimize const expressions more easily at compile time (speeds up program)
Const variables are compile time const if initializer is constant expression, runtime const if not
Constexpr ensures that variable is compile time constant, won't work if expression is non-constant
Const variables have value that can't be changed after initialization (not implicitly const), constexpr variables have value that must be known at compile time (implicitly const), function parameters can be const/not constexpr
Conditional/ternary operator is condition ? expression1 : expression2, if condition if true then expression1 is executed, else expression2 is, expressions 2/3 must have matching types (or types that can be matched), need to watch operators
Functions require performance overhead, CPU must store address of current instruction/registers/jump back to location after function ends, for small functions overhead can be larger than time to execute, can instead write in place using inline expansion, replaces function call with code from function definition, not good for bigger functions/not every function can be expanded, use inline keyword
In modern C++ inline means multiple definitions are allowed
Don't use inline unless you have reason to (defining functions/variables in header file), increases compile time (every code file including header needs to be recompiled instead of just header & its file)
Inline variables added in C++17 (work same way)
Can make constexpr functions as well as variables, return value computed at compile time if return value used where const expression required (replaces function call with return value, parameters must be const), can also be evaluated at runtime if parameters aren't constant (returns non-constexpr result), can't declare parameters as constexpr (can be const), implicitly inline (compiler must see full function definition, need multiple definitions to accomodate each file that calls it)
Consteval (in C++20) indicates that function must evaluate at compile time or else compile error will result (immediate function), parameters not constexpr, can't evaluate at runtime, can use to make constexpr functions compile at runtime
Constexpr/consteval functions can use non-const local variables, can use function parameters/local variables as arguments in further constexpr function calls, can call non-constexpr function if main function is being evaluated in non-constant context
Constexpr shouldn't be used for every function since it can cause code breaks when changed, makes functions harder to debug since you can't see them at runtime, can use in non-compile-time context to help compiler optimize/if you might make it compile time in the future
Std::string is class type (not basic type)/better to use than C-style string, part of string library, can initialize variables as normal/output with cout, flexible memory allows variables to store strings of different sizes, use length() function to get number of characters (string includes null terminator but doesn't include it in length, returns unsigned integral value of type size_t)
Use std::getline to input full line into string (std::cin stops at whitespace), use std::ws to ignore leading whitespaces/new lines
Std::string expensive to initialize (don't make many copies, don't pass by value), can return by value if return statement resolves to local string variable/string returned by value from function call/string created as part of return statement (special case of returning by value without making copy)
String literals are c-style strings by default, can make std::string by adding s suffix at end
Std:string_view introduced in C++17, provides read-only access to existing string, can access/use value but not modify (use instead of constexpr string), can initialize with C-string/std::string/std::string_view, can't implicitly convert to std::string (need explicit conversion/static_cast), can change assignment to another string, can make literals string_view with sv suffix, supports constexpr
Std::string is owner (can view/modify, expensive to copy, use when you need to modify string/store user input), std::string_view is viewer (can only view, inexpensive to make, use when you only need to view existing string), string_view of string that's been destroyed is dangling view (avoid), use as read only function parameter, preferred over constant string reference, can be used/returned improperly if not careful
Additional functions exist to modify string_view without modifying original string, remove_prefix(i) removes i characters from left side of view, remove_suffix(i) removes i characters from right side of view, can use to view substring of original string, string_view may/may not be null terminated