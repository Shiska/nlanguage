#include "..\nlanguage"

#define RUN_TESTS

#include <YSI\y_testing>

// Behavior before SetPlayerLanguage is undefined

Test:SetGetCheck() {
    SetPlayerLanguage(0, <ENGLISH>);

    ASSERT(IsPlayerLanguage(0, <ENGLISH>) == true);
    ASSERT(IsPlayerLanguage(0, <FRENCH>) == false);
    ASSERT(IsPlayerLanguage(0, <GERMAN>) == false);

    SetPlayerLanguage(0, <FRENCH>);

    ASSERT(IsPlayerLanguage(0, <ENGLISH>) == false);
    ASSERT(IsPlayerLanguage(0, <FRENCH>) == true);
    ASSERT(IsPlayerLanguage(0, <GERMAN>) == false);

    SetPlayerLanguage(0, <GERMAN>);

    ASSERT(IsPlayerLanguage(0, <ENGLISH>) == false);
    ASSERT(IsPlayerLanguage(0, <FRENCH>) == false);
    ASSERT(IsPlayerLanguage(0, <GERMAN>) == true);
}

Test:GetLanguageEntry() {
    SetPlayerLanguage(1, <ENGLISH>);

    ASSERT(strcmp(GetPlayerLanguageEntry(1, <WELCOME>), GetLanguageEntry(<ENGLISH>, <WELCOME>)) == 0);
    ASSERT(strcmp(GetPlayerLanguageEntry(1, <SELECTION>), GetLanguageEntry(<ENGLISH>, <SELECTION>)) == 0);

    SetPlayerLanguage(1, <FRENCH>);

    ASSERT(strcmp(GetPlayerLanguageEntry(1, <WELCOME>), GetLanguageEntry(<FRENCH>, <WELCOME>)) == 0);
    ASSERT(strcmp(GetPlayerLanguageEntry(1, <SELECTION>), GetLanguageEntry(<FRENCH>, <SELECTION>)) == 0);

    SetPlayerLanguage(1, <GERMAN>);

    ASSERT(strcmp(GetPlayerLanguageEntry(1, <WELCOME>), GetLanguageEntry(<GERMAN>, <WELCOME>)) == 0);
    ASSERT(strcmp(GetPlayerLanguageEntry(1, <SELECTION>), GetLanguageEntry(<GERMAN>, <SELECTION>)) == 0);
}