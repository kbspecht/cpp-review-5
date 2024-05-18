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