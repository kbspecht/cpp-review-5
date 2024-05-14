# cpp-review-5

Constants defined to ensure value doesn't change (ex. gravitational acceleration), must be initialized when defined (can't change during assignment)
Named constants are associated with identifier, literal constants aren't
Can define named constant with constant variables, macros, or enums
Constant variable defined using const keyword before object type, must be initialized when defined (can't change during assignment), can change naming convention if wished (ex. all caps)
Can make function parameters constant, used to make sure parameter value doesn't change (don't need for non-reference/pointer parameters)
Can also make function return value constant (generally not needed)
Macro constants use preprocessor to replace macro name with defined value, not preferred (doesn't follow scoping rules)
Type qualifier is keyword that modifies behavior of type, const makes variable constant, volatile tells compiler that object may have value changed at any time