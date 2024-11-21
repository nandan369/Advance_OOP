#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
using namespace std;


 //!A class that provides encryption and decryption using the Vigenère cipher.
 /**
 * The Vigenere class allows users to encrypt and decrypt messages using a 
 * key-based Vigenère cipher. The cipher shifts each letter in the message 
 * forward or backward based on corresponding letters in a repeating key.
 */
class Vigenere {
public:
    //! Constructs a Vigenere object with a specified key.
    /**
     * @param key The encryption key consisting of uppercase letters only.
     */
    Vigenere(string key);

    //! Destructor for the Vigenere object.
    /**
     * Frees up any resources if needed when the object goes out of scope.
     */
    ~Vigenere();

    //! Encrypts a message using the Vigenère cipher.
    /**
     * @param msg The message to be encrypted, provided in uppercase letters.
     * @return A string representing the encrypted message in uppercase.
     */
    string encrypt(string msg);

    //! Decrypts a previously encrypted message.
    /**
     * @param msg The encrypted message to decrypt, provided in uppercase letters.
     * @return A string representing the decrypted message in uppercase.
     */
    string decrypt(string msg);

    //! Checks if an encrypted message matches the encrypted version of a given decrypted message.
    /**
     * @param encryptedMsg The encrypted message to check.
     * @param decryptedMessage The decrypted message to encrypt and compare with `encryptedMsg`.
     * @return True if the encrypted message matches the encryption of the decrypted message; otherwise, false.
     */
    bool isEncrypted(string encryptedMsg, string decryptedMessage);

    //! Sets a new key for the Vigenère cipher.
    /**
     * @param key The new key to use for encryption and decryption.
     */
    void setKey(string key);

private:
    //! Extends the key to match the length of a given message.
    /**
     * @param msg The message whose length is used to extend the key.
     * @return A string with the extended key that matches the message length.
     */
    string extendKey(string msg);

    //! The encryption key used for the Vigenère cipher.
    string key;
};

#endif
