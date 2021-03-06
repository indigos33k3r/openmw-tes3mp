#ifndef OPENMW_SERVERAPI_HPP
#define OPENMW_SERVERAPI_HPP

#include "../Types.hpp"

#define SERVERAPI \
    {"StopServer",                  ServerFunctions::StopServer},\
    \
    {"Kick",                        ServerFunctions::Kick},\
    {"BanAddress",                  ServerFunctions::BanAddress},\
    {"UnbanAddress",                ServerFunctions::UnbanAddress},\
    \
    {"GetOperatingSystemType",      ServerFunctions::GetOperatingSystemType},\
    {"GetArchitectureType",         ServerFunctions::GetArchitectureType},\
    {"GetServerVersion",            ServerFunctions::GetServerVersion},\
    {"GetProtocolVersion",          ServerFunctions::GetProtocolVersion},\
    {"GetAvgPing",                  ServerFunctions::GetAvgPing},\
    {"GetIP",                       ServerFunctions::GetIP},\
    {"GetMaxPlayers",               ServerFunctions::GetMaxPlayers},\
    {"GetPort",                     ServerFunctions::GetPort},\
    {"HasPassword",                 ServerFunctions::HasPassword},\
    {"GetPluginEnforcementState",   ServerFunctions::GetPluginEnforcementState},\
    {"GetScriptErrorIgnoringState", ServerFunctions::GetScriptErrorIgnoringState},\
    \
    {"SetGameMode",                 ServerFunctions::SetGameMode},\
    {"SetHostname",                 ServerFunctions::SetHostname},\
    {"SetServerPassword",           ServerFunctions::SetServerPassword},\
    {"SetPluginEnforcementState",   ServerFunctions::SetPluginEnforcementState},\
    {"SetScriptErrorIgnoringState", ServerFunctions::SetScriptErrorIgnoringState},\
    {"SetRuleString",               ServerFunctions::SetRuleString},\
    {"SetRuleValue",                ServerFunctions::SetRuleValue},\
    {"AddPluginHash",               ServerFunctions::AddPluginHash},\
    {"GetModDir",                   ServerFunctions::GetModDir}

class ServerFunctions
{
public:

    /**
    * \brief Shut down the server.
    *
    * \param code The shutdown code.
    * \return void
    */
    static void StopServer(int code) noexcept;

    /**
    * \brief Kick a certain player from the server.
    *
    * \param pid The player ID.
    * \return void
    */
    static void Kick(unsigned short pid) noexcept;

    /**
    * \brief Ban a certain IP address from the server.
    *
    * \param ipAddress The IP address.
    * \return void
    */
    static void BanAddress(const char *ipAddress) noexcept;

    /**
    * \brief Unban a certain IP address from the server.
    *
    * \param ipAddress The IP address.
    * \return void
    */
    static void UnbanAddress(const char *ipAddress) noexcept;

    /**
    * \brief Get the type of the operating system used by the server.
    *
    * Note: Currently, the type can be "Windows", "Linux", "OS X" or "Unknown OS".
    *
    * \return The type of the operating system.
    */
    static const char *GetOperatingSystemType() noexcept;

    /**
    * \brief Get the architecture type used by the server.
    *
    * Note: Currently, the type can be "64-bit", "32-bit", "ARMv#" or "Unknown architecture".
    *
    * \return The architecture type.
    */
    static const char *GetArchitectureType() noexcept;

    /**
    * \brief Get the TES3MP version of the server.
    *
    * \return The server version.
    */
    static const char *GetServerVersion() noexcept;

    /**
    * \brief Get the protocol version of the server.
    *
    * \return The protocol version.
    */
    static const char *GetProtocolVersion() noexcept;

    /**
    * \brief Get the average ping of a certain player.
    *
    * \param pid The player ID.
    * \return The average ping.
    */
    static int GetAvgPing(unsigned short pid) noexcept;

    /**
    * \brief Get the IP address of a certain player.
    *
    * \param pid The player ID.
    * \return The IP address.
    */
    static const char* GetIP(unsigned short pid) noexcept;

    /**
     * \brief Get the port used by the server.
     *
     * \return Port
     */
    static unsigned short GetPort() noexcept;

    /**
     * \brief Get the maximum number of players.
     *
     * \return Max players
     */
    static unsigned int GetMaxPlayers() noexcept;

    /**
     * \brief Checking if the server requires a password to connect.
     *
     * @return
     */
    static bool HasPassword() noexcept;

    /**
    * \brief Get the plugin enforcement state of the server.
    *
    * If true, clients are required to use the same plugins as set for the server.
    *
    * \return The enforcement state.
    */
    static bool GetPluginEnforcementState() noexcept;

    /**
    * \brief Get the script error ignoring state of the server.
    *
    * If true, script errors will not crash the server.
    *
    * \return The script error ignoring state.
    */
    static bool GetScriptErrorIgnoringState() noexcept;

    /**
    * \brief Set the game mode of the server, as displayed in the server browser.
    *
    * \param name The new game mode.
    * \return void
    */
    static void SetGameMode(const char* gameMode) noexcept;

    /**
    * \brief Set the name of the server, as displayed in the server browser.
    *
    * \param name The new name.
    * \return void
    */
    static void SetHostname(const char* name) noexcept;

    /**
    * \brief Set the password required to join the server.
    *
    * \param password The password.
    * \return void
    */
    static void SetServerPassword(const char *password) noexcept;

    /**
    * \brief Set the plugin enforcement state of the server.
    *
    * If true, clients are required to use the same plugins as set for the server.
    *
    * \param state The new enforcement state.
    * \return void
    */
    static void SetPluginEnforcementState(bool state) noexcept;

    /**
    * \brief Set whether script errors should be ignored or not.
    *
    * If true, script errors will not crash the server, but could have any number
    * of unforeseen consequences, which is why this is a highly experimental
    * setting.
    *
    * \param state The new script error ignoring state.
    * \return void
    */
    static void SetScriptErrorIgnoringState(bool state) noexcept;

    /**
    * \brief Set a rule string for the server details displayed in the server browser.
    *
    * \param key The name of the rule.
    * \param value The string value of the rule.
    * \return void
    */
    static void SetRuleString(const char *key, const char *value) noexcept;

    /**
    * \brief Set a rule value for the server details displayed in the server browser.
    *
    * \param key The name of the rule.
    * \param value The numerical value of the rule.
    * \return void
    */
    static void SetRuleValue(const char *key, double value) noexcept;

    /**
     * \brief Adds plugins to the internal server structure to validate players.
     * @param pluginName Name with extension of the plugin or master file.
     * @param hash Hash string
     */
    static void AddPluginHash(const char *pluginName, const char *hash) noexcept;

    static const char *GetModDir() noexcept;
};

#endif //OPENMW_SERVERAPI_HPP
