#include "nlanguage"

#define RUN_TESTS

#include <YSI\y_testing>

enum nLanguageKeys {
    WELCOME,
    SELECTION
};

new const ENGLISH[nLanguageKeys][] = {
    {WELCOME, "Welcome"},
    {SELECTION, "Choose"}
};

new const FRENCH[nLanguageKeys][] = {
    {WELCOME, "Bienvenue"},
    {SELECTION, "Choisissez"}
};

new const GERMAN[nLanguageKeys][] = {
    {SELECTION, "Wähle"},
    {WELCOME, "Willkommen"}
};

main() {
    InitLanguage(ENGLISH);
    InitLanguage(FRENCH);
    InitLanguage(GERMAN);
}

// Behavior before SetPlayerLanguage is undefined

Test:SetCheck() {
    ASSERT(SetPlayerLanguage(0, ENGLISH) == true);

    ASSERT(IsPlayerLanguage(0, ENGLISH) == true);
    ASSERT(IsPlayerLanguage(0, FRENCH) == false);
    ASSERT(IsPlayerLanguage(0, GERMAN) == false);

    ASSERT(SetPlayerLanguage(0, FRENCH) == true);

    ASSERT(IsPlayerLanguage(0, ENGLISH) == false);
    ASSERT(IsPlayerLanguage(0, FRENCH) == true);
    ASSERT(IsPlayerLanguage(0, GERMAN) == false);

    ASSERT(SetPlayerLanguage(0, GERMAN) == true);

    ASSERT(IsPlayerLanguage(0, ENGLISH) == false);
    ASSERT(IsPlayerLanguage(0, FRENCH) == false);
    ASSERT(IsPlayerLanguage(0, GERMAN) == true);
}

Test:GetCheck() {
    new
        english = GetLanguageID(ENGLISH),
        french = GetLanguageID(FRENCH),
        german = GetLanguageID(GERMAN),
        lang
    ;

    ASSERT(SetPlayerLanguage(1, ENGLISH) == true);

    lang = GetPlayerLanguage(1);

    ASSERT(english == lang && french != lang && german != lang);
    ASSERT(SetPlayerLanguage(1, FRENCH) == true);

    lang = GetPlayerLanguage(1);

    ASSERT(english != lang && french == lang && german != lang);
    ASSERT(SetPlayerLanguage(1, GERMAN) == true);

    lang = GetPlayerLanguage(1);

    ASSERT(english != lang && french != lang && german == lang);
}

Test:GetText() {
    ASSERT(SetPlayerLanguage(2, ENGLISH) == true);

    ASSERT(strcmp(GetText(2, WELCOME), ENGLISH[WELCOME]) == 0);
    ASSERT(strcmp(GetText(2, SELECTION), ENGLISH[SELECTION]) == 0);

    ASSERT(SetPlayerLanguage(2, FRENCH) == true);

    ASSERT(strcmp(GetText(2, WELCOME), FRENCH[WELCOME]) == 0);
    ASSERT(strcmp(GetText(2, SELECTION), FRENCH[SELECTION]) == 0);

    ASSERT(SetPlayerLanguage(2, GERMAN) == true);

    ASSERT(strcmp(GetText(2, WELCOME), GERMAN[WELCOME]) == 0);
    ASSERT(strcmp(GetText(2, SELECTION), GERMAN[SELECTION]) == 0);
}