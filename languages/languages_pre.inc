#if !defined LANGUAGE_MODE
    #endinput
#endif

#if defined _inc_languages_pre
    #undef _inc_languages_pre
#endif

#if LANGUAGE_MODE == 1
#elseif LANGUAGE_MODE == 2
    enum LANGUAGE_KEY { // first language for default enum
#elseif LANGUAGE_MODE == 3
    enum LANGUAGE<LANGUAGE_..._KEY> { // all other enums just to check for duplicates
#elseif LANGUAGE_MODE == 4
    { // first language in LANGUAGE_DATA
#elseif LANGUAGE_MODE == 5
    ,{ // all other languages in LANGUAGE_DATA
#endif