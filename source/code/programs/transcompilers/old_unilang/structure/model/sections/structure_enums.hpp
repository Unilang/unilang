#pragma once

//enums to use in place of strings to make code more strongly typed
//enum class Class_Access   { PUBLIC, PROTECTED, PRIVATE };
enum class Value_Overload { LVALUE, RVALUE, NONE };
enum class Storage_Specifier {STATIC, EXTERN, NONE };

enum class Implicit_Method_Modifier {DEFAULT, DELETED, NONE};
enum class Method_Virtuality {UNPURE_VIRTUAL, PURE_VIRTUAL, NONE};

//concepts not keywords.
//they are applicable, but not a part of the c language.
//derivable characteristic based on function body
enum class Function_Category {OBSERVE,TRANSFORM};
