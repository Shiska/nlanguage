// Languages take from https://en.wikipedia.org/wiki/List_of_languages_by_total_number_of_speakers

#if !defined LANGUAGE_MODE
    #endinput
#endif

#if defined _inc_languages
    #undef _inc_languages
#endif

#if LANGUAGE_MODE == 1
    #define ENTRY: ENTRY1:ENTRY2:
    #define ENTRY1:%0\10
    #define ENTRY2:%1"%2" LANGUAGE<LANGUAGE_...>,
#elseif LANGUAGE_MODE == 2 // switches to LANGUAGE_MODE 3 after first entry
    #define ENTRY:%3<%0>%1"%2" LANGUAGE_KEY_%0,
#elseif LANGUAGE_MODE == 4 // switches to LANGUAGE_MODE 5 after first entry
    #define ENTRY: ENTRY1:ENTRY2:
    #define ENTRY1:%3<%0>%1"%2" {_:%3LANGUAGE_KEY_%0,#%2}
    #define ENTRY2:%0\10 %0,
#endif

#define LANGUAGE<%0...%1> %0ENGLISH%1

#if defined LANGUAGE_ENGLISH
    #include "languages_pre"
    #include "language\english"
    #include "languages_post"
#else
    #tryinclude "language\english"
#endif

#if defined _inc_english
    #undef _inc_english
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0MANDARIN%1

#if defined LANGUAGE_MANDARIN
    #include "languages_pre"
    #include "language\mandarin"
    #include "languages_post"
#else
    #tryinclude "language\mandarin"
#endif

#if defined _inc_mandarin
    #undef _inc_mandarin
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0HINDI%1

#if defined LANGUAGE_HINDI
    #include "languages_pre"
    #include "language\hindi"
    #include "languages_post"
#else
    #tryinclude "language\hindi"
#endif

#if defined _inc_hindi
    #undef _inc_hindi
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0SPANISH%1

#if defined LANGUAGE_SPANISH
    #include "languages_pre"
    #include "language\spanish"
    #include "languages_post"
#else
    #tryinclude "language\spanish"
#endif

#if defined _inc_spanish
    #undef _inc_spanish
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0FRENCH%1

#if defined LANGUAGE_FRENCH
    #include "languages_pre"
    #include "language\french"
    #include "languages_post"
#else
    #tryinclude "language\french"
#endif

#if defined _inc_french
    #undef _inc_french
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0ARABIC%1

#if defined LANGUAGE_ARABIC
    #include "languages_pre"
    #include "language\arabic"
    #include "languages_post"
#else
    #tryinclude "language\arabic"
#endif

#if defined _inc_arabic
    #undef _inc_arabic
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0BENGALI%1

#if defined LANGUAGE_BENGALI
    #include "languages_pre"
    #include "language\bengali"
    #include "languages_post"
#else
    #tryinclude "language\bengali"
#endif

#if defined _inc_bengali
    #undef _inc_bengali
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0RUSSIAN%1

#if defined LANGUAGE_RUSSIAN
    #include "languages_pre"
    #include "language\russian"
    #include "languages_post"
#else
    #tryinclude "language\russian"
#endif

#if defined _inc_russian
    #undef _inc_russian
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0PORTUGUESE%1

#if defined LANGUAGE_PORTUGUESE
    #include "languages_pre"
    #include "language\portuguese"
    #include "languages_post"
#else
    #tryinclude "language\portuguese"
#endif

#if defined _inc_portuguese
    #undef _inc_portuguese
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0INDONESIAN%1

#if defined LANGUAGE_INDONESIAN
    #include "languages_pre"
    #include "language\indonesian"
    #include "languages_post"
#else
    #tryinclude "language\indonesian"
#endif

#if defined _inc_indonesian
    #undef _inc_indonesian
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0URDU%1

#if defined LANGUAGE_URDU
    #include "languages_pre"
    #include "language\urdu"
    #include "languages_post"
#else
    #tryinclude "language\urdu"
#endif

#if defined _inc_urdu
    #undef _inc_urdu
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0GERMAN%1

#if defined LANGUAGE_GERMAN
    #include "languages_pre"
    #include "language\german"
    #include "languages_post"
#else
    #tryinclude "language\german"
#endif

#if defined _inc_german
    #undef _inc_german
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0JAPANESE%1

#if defined LANGUAGE_JAPANESE
    #include "languages_pre"
    #include "language\japanese"
    #include "languages_post"
#else
    #tryinclude "language\japanese"
#endif

#if defined _inc_japanese
    #undef _inc_japanese
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0SWAHILI%1

#if defined LANGUAGE_SWAHILI
    #include "languages_pre"
    #include "language\swahili"
    #include "languages_post"
#else
    #tryinclude "language\swahili"
#endif

#if defined _inc_swahili
    #undef _inc_swahili
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0MARATHI%1

#if defined LANGUAGE_MARATHI
    #include "languages_pre"
    #include "language\marathi"
    #include "languages_post"
#else
    #tryinclude "language\marathi"
#endif

#if defined _inc_marathi
    #undef _inc_marathi
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0TELUGU%1

#if defined LANGUAGE_TELUGU
    #include "languages_pre"
    #include "language\telugu"
    #include "languages_post"
#else
    #tryinclude "language\telugu"
#endif

#if defined _inc_telugu
    #undef _inc_telugu
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0LAHNDA%1

#if defined LANGUAGE_LAHNDA
    #include "languages_pre"
    #include "language\lahnda"
    #include "languages_post"
#else
    #tryinclude "language\lahnda"
#endif

#if defined _inc_lahnda
    #undef _inc_lahnda
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0WU%1

#if defined LANGUAGE_WU
    #include "languages_pre"
    #include "language\wu"
    #include "languages_post"
#else
    #tryinclude "language\wu"
#endif

#if defined _inc_wu
    #undef _inc_wu
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0TAMIL%1

#if defined LANGUAGE_TAMIL
    #include "languages_pre"
    #include "language\tamil"
    #include "languages_post"
#else
    #tryinclude "language\tamil"
#endif

#if defined _inc_tamil
    #undef _inc_tamil
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0TURKISH%1

#if defined LANGUAGE_TURKISH
    #include "languages_pre"
    #include "language\turkish"
    #include "languages_post"
#else
    #tryinclude "language\turkish"
#endif

#if defined _inc_turkish
    #undef _inc_turkish
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0KOREAN%1

#if defined LANGUAGE_KOREAN
    #include "languages_pre"
    #include "language\korean"
    #include "languages_post"
#else
    #tryinclude "language\korean"
#endif

#if defined _inc_korean
    #undef _inc_korean
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0VIETNAMESE%1

#if defined LANGUAGE_VIETNAMESE
    #include "languages_pre"
    #include "language\vietnamese"
    #include "languages_post"
#else
    #tryinclude "language\vietnamese"
#endif

#if defined _inc_vietnamese
    #undef _inc_vietnamese
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0YUE%1

#if defined LANGUAGE_YUE
    #include "languages_pre"
    #include "language\yue"
    #include "languages_post"
#else
    #tryinclude "language\yue"
#endif

#if defined _inc_yue
    #undef _inc_yue
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0JAVANESE%1

#if defined LANGUAGE_JAVANESE
    #include "languages_pre"
    #include "language\javanese"
    #include "languages_post"
#else
    #tryinclude "language\javanese"
#endif

#if defined _inc_javanese
    #undef _inc_javanese
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0ITALIAN%1

#if defined LANGUAGE_ITALIAN
    #include "languages_pre"
    #include "language\italian"
    #include "languages_post"
#else
    #tryinclude "language\italian"
#endif

#if defined _inc_italian
    #undef _inc_italian
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0HAUSA%1

#if defined LANGUAGE_HAUSA
    #include "languages_pre"
    #include "language\hausa"
    #include "languages_post"
#else
    #tryinclude "language\hausa"
#endif

#if defined _inc_hausa
    #undef _inc_hausa
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0MASRI%1

#if defined LANGUAGE_MASRI
    #include "languages_pre"
    #include "language\masri"
    #include "languages_post"
#else
    #tryinclude "language\masri"
#endif

#if defined _inc_masri
    #undef _inc_masri
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0THAI%1

#if defined LANGUAGE_THAI
    #include "languages_pre"
    #include "language\thai"
    #include "languages_post"
#else
    #tryinclude "language\thai"
#endif

#if defined _inc_thai
    #undef _inc_thai
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0GUJARATI%1

#if defined LANGUAGE_GUJARATI
    #include "languages_pre"
    #include "language\gujarati"
    #include "languages_post"
#else
    #tryinclude "language\gujarati"
#endif

#if defined _inc_gujarati
    #undef _inc_gujarati
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0PERSIAN%1

#if defined LANGUAGE_PERSIAN
    #include "languages_pre"
    #include "language\persian"
    #include "languages_post"
#else
    #tryinclude "language\persian"
#endif

#if defined _inc_persian
    #undef _inc_persian
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0BHOJPURI%1

#if defined LANGUAGE_BHOJPURI
    #include "languages_pre"
    #include "language\bhojpuri"
    #include "languages_post"
#else
    #tryinclude "language\bhojpuri"
#endif

#if defined _inc_bhojpuri
    #undef _inc_bhojpuri
#endif

#undef LANGUAGE
#define LANGUAGE<%0...%1> %0MINNAN%1

#if defined LANGUAGE_MINNAN
    #include "languages_pre"
    #include "language\minnan"
    #include "languages_post"
#else
    #tryinclude "language\minnan"
#endif

#if defined _inc_minnan
    #undef _inc_minnan
#endif

#undef LANGUAGE
#undef LANGUAGE_MODE

#if defined ENTRY
    #undef ENTRY
#endif
#if defined ENTRY1
    #undef ENTRY1
#endif
#if defined ENTRY2
    #undef ENTRY2
#endif
#if defined ENTRY3
    #undef ENTRY3
#endif