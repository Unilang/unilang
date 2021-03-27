#include "lib.hpp"

//header related data:
const wchar_t HEADER_INCLUDE_START        = L'❪';
const wchar_t HEADER_INCLUDE_END          = L'❫';
const wchar_t HEADER_SEPERATOR            = L'⚯';
const wchar_t HEADER_END                  = L'➖';

//class only:
const wchar_t INHERITENCE_START           = L'⚞';
const wchar_t INHERITENCE_END             = L'⚟';
const wchar_t CLASS_SCOPE                 = L'☀';
const wchar_t CLASS_NAME_CODE_FORM        = L'◈';
const wchar_t CLASS_NAME_PRINT_FORM       = L'ɵ';
const wchar_t PUBLIC_CLASS_SPECIFIER      = L'✚';
const wchar_t PROTECTED_CLASS_SPECIFIER   = L'✱';
const wchar_t PRIVATE_CLASS_SPECIFIER     = L'✖';
const wchar_t DATA_MEMBER_NAME_WRAPPER    = L'፠';

//class or global:
const wchar_t HEADER_ONLY_INCLUDE_START   = L'◀';
const wchar_t HEADER_ONLY_INCLUDE_END     = L'▶';
const wchar_t SOURCE_ONLY_INCLUDE_START   = L'◖';
const wchar_t SOURCE_ONLY_INCLUDE_END     = L'◗';
const wchar_t EXECUTE_SHELL_COMMAND_START = L'ͼ';
const wchar_t EXECUTE_SHELL_COMMAND_END   = L'ͽ';
const wchar_t COMMENT_START               = L'⊰';
const wchar_t COMMENT_END                 = L'⊱';
const wchar_t UNICODE_ESCAPE_CHARACTER    = L'ļ';

//function related:
const wchar_t FUNCTION_RETURN_TYPE_START  = L'ᛞ';
const wchar_t FUNCTION_RETURN_TYPE_END    = L'↱';
const wchar_t FUNCTION_NAME_WRAPPER       = L'↰';
const wchar_t FUNCTION_BODY_START         = L'❰';
const wchar_t FUNCTION_BODY_END           = L'❱';
const std::vector<wchar_t> ALL_UNICODE_PARSER_SYMBOLS =
    {HEADER_INCLUDE_START
    ,HEADER_INCLUDE_END
    ,HEADER_SEPERATOR
    ,HEADER_END
    ,INHERITENCE_START
    ,INHERITENCE_END
    ,CLASS_SCOPE
    ,CLASS_NAME_CODE_FORM
    ,CLASS_NAME_PRINT_FORM
    ,PUBLIC_CLASS_SPECIFIER
    ,PROTECTED_CLASS_SPECIFIER
    ,PRIVATE_CLASS_SPECIFIER
    ,DATA_MEMBER_NAME_WRAPPER
    ,HEADER_ONLY_INCLUDE_START
    ,HEADER_ONLY_INCLUDE_END
    ,SOURCE_ONLY_INCLUDE_START
    ,SOURCE_ONLY_INCLUDE_END
    ,EXECUTE_SHELL_COMMAND_START
    ,EXECUTE_SHELL_COMMAND_END
    ,COMMENT_START
    ,COMMENT_END
    ,UNICODE_ESCAPE_CHARACTER
    ,FUNCTION_RETURN_TYPE_START
    ,FUNCTION_RETURN_TYPE_END
    ,FUNCTION_NAME_WRAPPER
    ,FUNCTION_BODY_START
    ,FUNCTION_BODY_END
};
