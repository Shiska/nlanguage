/** <summary>Another static language system</summary>
  *//** */

// TODO: Automate InitLanguage :? / make it easier to use
// TODO: retry 2d array, maybe with trampoline
// TODO: operator / macro instead of GetText?

enum nLanguageKeys {}
///	<summary>All language key, they need to be defined in the user script</summary>
/// <export/>
/// <example tab="0">enum nLanguageKeys {</example>
/// <example tab="1">    WELCOME,</example>
/// <example tab="1">    SELECTION</example>
/// <example tab="0">};</example>
/// <example tab="0"></example>
/// <example tab="0">new const ENGLISH[nLanguageKeys][] = {</example>
/// <example tab="1">    {WELCOME, "Welcome"},</example>
/// <example tab="1">    {SELECTION, "Choose"}</example>
/// <example tab="0">};</example>
/// <example tab="0"></example>
/// <example tab="0">new const FRENCH[nLanguageKeys][] = {</example>
/// <example tab="1">    {WELCOME, "Bienvenue"},</example>
/// <example tab="1">    {SELECTION, "Choisissez"}</example>
/// <example tab="0">};</example>
/// <example tab="0"></example>
/// <example tab="0">new const GERMAN[nLanguageKeys][] = {</example>
/// <example tab="1">    {SELECTION, "Wähle"},</example>
/// <example tab="1">    {WELCOME, "Willkommen"}</example>
/// <example tab="0">};</example>
/// <remarks>Don't forget to initialize each language (<ref name="InitLanguage"/>)</remarks>

stock static
    ///	<summary>Player language array</summary>
    nLanguage[MAX_PLAYERS]
;

stock static bool: SortLanguage(src[], const src2d[][], tmp[], const size) {
    ///	<summary>Sorts source array by index with the help of an temp array</summary>
    /// <param name="src">Source array 1d</param>
    /// <param name="src2d">Source array 2d</param>
    /// <param name="tmp">Temp array for the new index</param>
    /// <param name="size">Size of temp array</param>
    /// <returns name="true">if successful</returns>
    /// <returns name="false">if duplicate key was found</returns>

    for(new i = 0; i < size; ++i) {
        tmp[i] = 0;
    }
    for(new i = 0, index; i < size; ++i) {
        index = src2d[i][0];

        if(tmp[index] != 0) { // index already taken
            return bool: printf("SortLanguage: Duplicated key on \"%s\" !", src2d[i][1]);
        }
        tmp[index] = src[i] + ((i - index) << 2) + 4; // fix offset
    }
    for(new i = 0; i < size; ++i) {
        src[i] = tmp[i];
    }
    return true;
}

stock bool: InitLanguage(const language[nLanguageKeys][], const size = sizeof language) {
    ///	<summary>Initilize the given language</summary>
    /// <export/>
    /// <param name="language">Language array [<ref name="nLanguageKeys"/>]</param>
    /// <param name="size">Size of language array</param>
    /// <returns name="true">if successful</returns>
    /// <returns name="false">if duplicate key was found</returns>
    /// <example>InitLanguage(ENGLISH)</example>
    /// <example>InitLanguage(FRENCH)</example>
    /// <example>InitLanguage(GERMAN)</example>

    // allocate temp array
    #emit lctrl 4 // stk
    #emit load.s.alt size
    #emit shl.c.alt 2
    #emit sub
    #emit sctrl 4 // set stack
    // call real init function
    #emit push.s size
    #emit push.pri // allocated array
    #emit push.s language
    #emit push.s language
    #emit push.c 16
    #emit call SortLanguage
    // fix stack and return
    #emit move.alt
    #emit lctrl 5
    #emit sctrl 4
    #emit move.pri
    #emit retn
    // return true on success
    return true;
}

stock bool: SetPlayerLanguage(playerid, const language[nLanguageKeys][]) {
    ///	<summary>Sets the player language to "language"</summary>
    /// <export/>
    /// <param name="playerid">The playerid</param>
    /// <param name="language">Language array [<ref name="nLanguageKeys"/>]</param>
    /// <returns name="true">if playerid is valid</returns>
    /// <returns name="false">otherwise</returns>
    /// <example>SetPlayerLanguage(playerid, ENGLISH)</example>
    /// <example>SetPlayerLanguage(playerid, FRENCH)</example>
    /// <example>SetPlayerLanguage(playerid, GERMAN)</example>

    if(0 <= playerid < sizeof nLanguage) {
        #emit const.alt nLanguage
        #emit load.s.pri playerid
        #emit idxaddr
        #emit move.alt
        #emit load.s.pri language
        // #emit sub // stores as offset
        #emit stor.i

        return true;
    }
    return false;
}

stock GetPlayerLanguage(playerid) {
    ///	<summary>Get the player language address</summary>
    /// <export/>
    /// <param name="playerid">The playerid</param>
    /// <returns name="address">the player language address</returns>
    /// <returns name="0">if playerid isn't valid</returns>
    /// <example>GetPlayerLanguage(playerid)</example>
    /// <seealso name="GetLanguageID"/>
    /// <seealso name="IsPlayerLanguage"/>

    if(0 <= playerid < sizeof nLanguage) {
        return nLanguage[playerid];
        // load as offset :/
        #emit const.alt nLanguage
        #emit load.s.pri playerid
        #emit idxaddr
        #emit move.alt
        #emit load.i
        #emit add
        #emit retn
    }
    return 0;
}

stock GetLanguageID(const language[nLanguageKeys][]) {
    ///	<summary>Get the language address</summary>
    /// <export/>
    /// <param name="language">Language array [<ref name="nLanguageKeys"/>]</param>
    /// <returns name="address">the language address</returns>
    /// <example>if(GetPlayerLanguage(playerid) == GetLanguageID(ENGLISH)) {}</example>
    /// <example>if(GetPlayerLanguage(playerid) == GetLanguageID(FRENCH)) {}</example>
    /// <example>if(GetPlayerLanguage(playerid) == GetLanguageID(GERMAN)) {}</example>
    /// <seealso name="GetPlayerLanguage"/>
    /// <seealso name="IsPlayerLanguage"/>

    #emit load.s.pri language
    #emit retn

    return 0;
}

stock bool: IsPlayerLanguage(playerid, const language[nLanguageKeys][]) {
    ///	<summary>Checks if player language is the given language</summary>
    /// <export/>
    /// <param name="playerid">The playerid</param>
    /// <param name="language">Language array [<ref name="nLanguageKeys"/>]</param>
    /// <returns name="true">if player language address (<ref name="GetPlayerLanguage"/>) is equal to language address (<ref name="GetLanguageID"/>)</returns>
    /// <returns name="false">otherwise</returns>
    /// <example>if(IsPlayerLanguage(playerid, ENGLISH)) {}</example>
    /// <example>if(IsPlayerLanguage(playerid, FRENCH)) {}</example>
    /// <example>if(IsPlayerLanguage(playerid, GERMAN)) {}</example>

    return GetPlayerLanguage(playerid) == GetLanguageID(language);
}

stock GetText(playerid, nLanguageKeys: key) {
    ///	<summary>Get the corresponding text for the given language key</summary>
    /// <export/>
    /// <param name="playerid">The playerid</param>
    /// <param name="key">Language key</param>
    /// <returns name="text">The text for the given language key</returns>
    /// <example>GetText(playerid, WELCOME)</example>
    /// <example>GetText(playerid, SELECTION)</example>

    GetPlayerLanguage(playerid);

    #emit move.alt
    #emit load.s.pri key
    #emit idxaddr
    #emit move.alt
    #emit load.i
    #emit add
    #emit stor.s.pri 20
    #emit retn

    new retn[1];

    return retn;
}