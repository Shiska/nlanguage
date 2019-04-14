#if !defined LANGUAGE_MODE
    #endinput
#endif

#if defined _inc_languages_post
    #undef _inc_languages_post
#endif

#if LANGUAGE_MODE == 1
#elseif LANGUAGE_MODE == 2
    };
    #undef ENTRY
    #undef LANGUAGE_MODE
    #define LANGUAGE_MODE 3
    #define ENTRY:%3<%0>%1"%2" LANGUAGE<LANGUAGE_..._%0>,
#elseif LANGUAGE_MODE == 3
    };
#elseif LANGUAGE_MODE == 4
    }
    #undef LANGUAGE_MODE
    #define LANGUAGE_MODE 5
#elseif LANGUAGE_MODE == 5
    }
#endif