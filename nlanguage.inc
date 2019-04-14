/**
  * <summary>
  *   Another static language system
  * </summary>
  *
  * <section>Macros</section>
  * <ul>
  *   <li>SetPlayerLanguage(playerid, &lt;LANGUAGE: language&gt;);</li>
  *   <li>bool: IsPlayerLanguage(playerid, &lt;LANGUAGE: language&gt;);</li>
  *   <li>GetLanguageEntry(&lt;LANGUAGE: language&gt;, &lt;LANGUAGE_KEY: key&gt;);</li>
  *   <li>GetPlayerLanguageEntry(playerid, &lt;LANGUAGE_KEY: key&gt;);</li>
  * </ul>
  *//** */

#define LANGUAGE_MODE 1

/** <summary>All found languages</summary>
  * <remarks>
  *   Only the three languages from the test script are listed here but there are
  *   <ul>
  *     <li>English</li>
  *     <li>Mandarin Chinese</li>
  *     <li>Hindi</li>
  *     <li>Spanish</li>
  *     <li>French</li>
  *     <li>Arabic</li>
  *     <li>Bengali</li>
  *     <li>Russian</li>
  *     <li>Portuguese</li>
  *     <li>Indonesian</li>
  *     <li>Urdu</li>
  *     <li>German</li>
  *     <li>Japanese</li>
  *     <li>Swahili</li>
  *     <li>Marathi</li>
  *     <li>Telugu</li>
  *     <li>Lahnda</li>
  *     <li>Wu</li>
  *     <li>Tamil</li>
  *     <li>Turkish</li>
  *     <li>Korean</li>
  *     <li>Vietnamese</li>
  *     <li>Yue</li>
  *     <li>Javanese</li>
  *     <li>Italian</li>
  *     <li>Hausa</li>
  *     <li>Masri</li>
  *     <li>Thai</li>
  *     <li>Gujarati</li>
  *     <li>Persian</li>
  *     <li>Bhojpuri</li>
  *     <li>Minnan</li>
  *   </ul>
  *   Create a language folder and create a language_name.inc file (language_name in lowercase)
  * </remarks>
  * <example>// english.inc - ENTRY: &lt;keyword&gt; "Translation"</example>
  * <example>ENTRY: &lt;WELCOME&gt; "Welcome"</example>
  * <example>ENTRY: &lt;SELECTION&gt; "Choose"</example>
  * <export/>
  */
enum LANGUAGE {
    #include "languages\languages"
};

#define LANGUAGE_MODE 2

/** <summary>All found language keys</summary>
  * <remarks>Only keys from test script are listed here</remarks>
  * <export/>
  */
#include "languages\languages" // LANGUAGE_KEY

#define LANGUAGE_MODE 4

/** <summary>The language data array which stores all translations</summary>
  * <example>// GetLanguageEntry(&lt;LANGUAGE: language&gt;, &lt;LANGUAGE_KEY: key&gt;)</example>
  * <example>// Get be accessed directly with GetLanguageEntry</example>
  * <example>GetLanguageEntry(&lt;ENGLISH&gt;, &lt;WELCOME&gt;);</example>
  * <export/>
  */
stock const LANGUAGE_DATA[LANGUAGE][LANGUAGE_KEY][] = {
    #include "languages\languages"
};

/** <summary>The language player array which stores the player language</summary>
  * <example>// SetPlayerLanguage(playerid, &lt;LANGUAGE: language&gt;)</example>
  * <example>// Set the player language with</example>
  * <example>SetPlayerLanguage(playerid, &lt;ENGLISH&gt;);</example>
  * <example>// bool: IsPlayerLanguage(playerid, &lt;LANGUAGE: language&gt;)</example>
  * <example>// Checks if the player language is the given language</example>
  * <example>if(IsPlayerLanguage(playerid, &lt;ENGLISH&gt;)) {}</example>
  * <example>// GetPlayerLanguageEntry(playerid, &lt;LANGUAGE_KEY: key&gt;)</example>
  * <example>// Get the language data corresponding to the player language</example>
  * <example>GetPlayerLanguageEntry(playerid, &lt;WELCOME&gt;);</example>
  * <export/>
  */
stock LANGUAGE: LANGUAGE_PLAYER[MAX_PLAYERS char];

// native SetPlayerLanguage(playerid, <LANGUAGE: language>);
#define SetPlayerLanguage(%0,%2<%1>%2) (LANGUAGE_PLAYER{%0} = LANGUAGE_%1)
// native bool: IsPlayerLanguage(playerid, <LANGUAGE: language>);
#define IsPlayerLanguage(%0,%2<%1>%2) (LANGUAGE_PLAYER{%0} == LANGUAGE_%1)
// native GetLanguageEntry(<LANGUAGE: language>, <LANGUAGE_KEY: key>);
#define GetLanguageEntry(%2<%0>%2,%2<%1>%2) LANGUAGE_DATA[LANGUAGE_%0][LANGUAGE_KEY_%1]
// native GetPlayerLanguageEntry(playerid, <LANGUAGE_KEY: key>);
#define GetPlayerLanguageEntry(%0,%2<%1>%2) LANGUAGE_DATA[LANGUAGE_PLAYER{%0}][LANGUAGE_KEY_%1]