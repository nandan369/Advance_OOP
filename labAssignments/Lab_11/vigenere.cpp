#include "vigenere.h"
#include <cctype> 
#include <algorithm> 

// Constructor
Vigenere::Vigenere(string key) : key(move(key)) {
    // Convert key to uppercase
    transform(this->key.begin(), this->key.end(), this->key.begin(), ::toupper);
}

// Destructor
Vigenere::~Vigenere() {}

/* -----------------------------------------------------------------------------
 * Function: extendKey
 * Usage   : extendKey(msg)
 * -----------------------------------------------------------------------------
 * Generates an extended key by repeating the original key to match the message length.
 * -----------------------------------------------------------------------------*/
string Vigenere::extendKey(string msg) {
    string extendedKey;
    for (size_t i = 0; i < msg.size(); ++i) {
        extendedKey += key[i % key.size()];
    }
    return extendedKey;
}

/* -----------------------------------------------------------------------------
 * Function: encrypt
 * Usage   : encrypt(string_message)
 * -----------------------------------------------------------------------------
 * Encrypts a message using the Vigenère cipher. Alphabetic characters are shifted 
 * based on the corresponding key characters, while non-alphabetic characters remain 
 * unchanged. Handles both uppercase and lowercase letters.
 * -----------------------------------------------------------------------------*/
std::string Vigenere::encrypt(std::string msg) {
    std::string encryptedMsg;
    std::string extendedKey = extendKey(msg);

    for (size_t i = 0; i < msg.size(); ++i) {
        char msgChar = msg[i];
        char keyChar = extendedKey[i];

        if (isalpha(msgChar)) {  // Only encrypt alphabet characters
            int shift = toupper(keyChar) - 'A';  // Calculate shift based on key character

            if (isupper(msgChar)) {
                encryptedMsg += (msgChar - 'A' + shift) % 26 + 'A';  // Encrypt uppercase letters
            } else {
                encryptedMsg += (msgChar - 'a' + shift) % 26 + 'a';  // Encrypt lowercase letters
            }
        } else {
            encryptedMsg += msgChar;  // Leave non-alphabet characters unchanged
        }
    }

    return encryptedMsg;
}

/* -----------------------------------------------------------------------------
 * Function: decrypt
 * Usage   : decrypt(string msg)
 * -----------------------------------------------------------------------------
 * This function decrypts a message using the Vigenère cipher with case-sensitive 
 * handling and preserves non-alphabet characters.
 * ------------------------------------------------------------------------------*/

std::string Vigenere::decrypt(std::string msg) {
    std::string decryptedMsg;
    std::string extendedKey = extendKey(msg);

    for (size_t i = 0; i < msg.size(); ++i) {
        char msgChar = msg[i];
        char keyChar = extendedKey[i];

        if (isalpha(msgChar)) {  // Only decrypt alphabet characters
            int shift = toupper(keyChar) - 'A';  // Calculate shift based on key character

            if (isupper(msgChar)) {
                decryptedMsg += (msgChar - 'A' - shift + 26) % 26 + 'A';  // Decrypt uppercase letters
            } else {
                decryptedMsg += (msgChar - 'a' - shift + 26) % 26 + 'a';  // Decrypt lowercase letters
            }
        } else {
            decryptedMsg += msgChar;  // Leave non-alphabet characters unchanged
        }
    }

    return decryptedMsg;
}

/* -----------------------------------------------------------------------------
 * Function: isEncrypted
 * Usage   : isEncrypted(encryptedMsg, decryptedMessage)
 * -----------------------------------------------------------------------------
 * This function checks if the given decrypted message, when encrypted, matches 
 * the provided encrypted message.
 * ------------------------------------------------------------------------------*/

bool Vigenere::isEncrypted(string encryptedMsg, string decryptedMessage) {
    return encrypt(decryptedMessage) == encryptedMsg;
}

/* -----------------------------------------------------------------------------
 * Function: setKey
 * Usage   : setKey(newKey)
 * -----------------------------------------------------------------------------
 * This function sets a new encryption key and converts it to uppercase.
 * ------------------------------------------------------------------------------*/
void Vigenere::setKey(string newKey) {
    key = move(newKey);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
}
