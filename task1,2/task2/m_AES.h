#ifndef HMAES_H
#define HMAES_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "key_exp.h"

class AES_CBC
{
public:
    std::string PKCS7Padding(const std::string &data)
    {
        std::string bytes = data;
        unsigned char pad_len = 16 - (bytes.size() % 16);
        bytes.append(pad_len, static_cast<char>(pad_len));
        return bytes;
    }

    std::string PKCS7Unpadding(std::string data)
    {
        unsigned char pad_len = data.back();
        data.erase(data.end() - pad_len, data.end());
        return data;
    }

    std::string to_hex(const std::vector<unsigned char> &data)
    {
        std::stringstream ss;
        for (const auto &byte : data)
        {
            ss << std::hex << std::setw(2) << std::setfill('0') << (byte & 0xff);
        }
        return ss.str();
    }

    std::string cbc_encrypt(std::string plaintext, std::string key, std::string iv)
    {
        // Convert key and iv to ASCII
        std::vector<unsigned char> ivInts;
        for (char &c : iv)
        {
            ivInts.push_back(static_cast<unsigned char>(c));
        }
        // Apply padding
        AES aes;
        std::string padded_data = PKCS7Padding(plaintext);
        // Encrypt each block
        std::vector<std::vector<unsigned char>> encrypted_blocks;
        
        std::vector<unsigned char> previous_block = ivInts;
        for (std::string::size_type i = 0; i < padded_data.size(); i += 16)
        {
            std::string block = padded_data.substr(i, 16);
            // XOR with the previous ciphertext block
            for (unsigned char j = 0; j < 16; ++j)
            {
                block[j] ^= previous_block[j];
            }
            std::vector<unsigned char> encrypted_block = aes.encrypt(std::vector<unsigned char>(block.begin(), block.end()), key);
            
            encrypted_blocks.push_back(encrypted_block);
            previous_block = encrypted_block;
        }

        // The IV is prepended to the ciphertext for use in decryption
        std::vector<unsigned char> result;
        for (auto &block : encrypted_blocks)
        {
            result.insert(result.end(), block.begin(), block.end());
        }

        // Convert the result to hexstring
        std::string hex_result = to_hex(result);

        return hex_result;
    }

    std::string from_hex(const std::string &hex)
    {
        std::string bytes;

        for (unsigned char i = 0; i < hex.length(); i += 2)
        {
            std::string byteString = hex.substr(i, 2);
            char byte = (char)strtol(byteString.c_str(), NULL, 16);
            bytes.push_back(byte);
        }

        // Pad the bytes string if its length is not a multiple of 16
        unsigned char remainder = bytes.size() % 16;
        if (remainder != 0)
        {
            unsigned char padding_needed = 16 - remainder;
            for (unsigned char i = 0; i < padding_needed; ++i)
            {
                bytes.push_back(static_cast<char>(padding_needed));
            }
        }

        return bytes;
    }

    std::string cbc_decrypt(std::string ciphertext_hex, std::string key, std::string iv)
    {
        // Hex decode
        AES aes;
        std::string ciphertext = from_hex(ciphertext_hex);
        if (ciphertext.size() % 16 != 0)
        {
            throw std::invalid_argument("Ciphertext length must be a multiple of 16 bytes for CBC mode.");
        }

        // // Extract the IV from the ciphertext
        // iv = std::string(ciphertext.begin(), ciphertext.begin() + 16);
        // ciphertext.erase(ciphertext.begin(), ciphertext.begin() + 16);

        std::string decrypted_blocks;
        std::vector<unsigned char> previous_block(iv.begin(), iv.end());

        for (size_t i = 0; i < ciphertext.size(); i += 16)
        {
            std::vector<unsigned char> block(ciphertext.begin() + i, ciphertext.begin() + i + 16);
            std::vector<unsigned char> decrypted_block = aes.decrypt(block, key);

            // XOR with the previous ciphertext block
            for (size_t j = 0; j < 16; ++j)
            {
                decrypted_block[j] ^= previous_block[j];
            }

            decrypted_blocks += std::string(decrypted_block.begin(), decrypted_block.end());
            previous_block = block;
        }

        // Remove padding
        std::string decrypted_data = PKCS7Unpadding(decrypted_blocks);
        return decrypted_data;
    }
};

#endif
