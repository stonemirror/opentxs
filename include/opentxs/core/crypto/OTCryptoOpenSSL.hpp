/************************************************************
 *
 *  OTCryptoOpenSSL.hpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#ifndef OPENTXS_CORE_CRYPTO_OTCRYPTOOPENSSL_HPP
#define OPENTXS_CORE_CRYPTO_OTCRYPTOOPENSSL_HPP

#include "OTCrypto.hpp"
#include <opentxs/core/OTData.hpp>
#include <opentxs/core/String.hpp>
#include <opentxs/core/util/Assert.hpp>

#include <mutex>

#include <set>

namespace opentxs
{

class OTAsymmetricKey;
class OTData;
class Identifier;
class OTPassword;
class OTPasswordData;
class OTData;
class Nym;
class OTSettings;
class OTSignature;

// OTCrypto (OTCrypto.hpp) is the abstract base class which is used as an
// interface by the rest of OT.
//
// Whereas OTCrypto_OpenSSL (below) is the actual implementation, written using
// the OpenSSL library. Theoretically, a new implementation could someday be
// "swapped in" -- for example, using GPG or NaCl or Crypto++, etc.

#if defined(OT_CRYPTO_USING_GPG)

// Someday    }:-)        OTCrypto_GPG

#elif defined(OT_CRYPTO_USING_OPENSSL)

class OTCrypto_OpenSSL : public OTCrypto
{
    friend class OTCrypto;

protected:
    OTCrypto_OpenSSL();
    virtual void Init_Override() const;
    virtual void Cleanup_Override() const;

    class OTCrypto_OpenSSLdp;
    OTCrypto_OpenSSLdp* dp;

public:
    static std::mutex* s_arrayMutex;
    // (To instantiate a text secret, just do this: OTPassword thePass;)
    virtual OTPassword* InstantiateBinarySecret() const;

    virtual bool GetPasswordFromConsoleLowLevel(OTPassword& theOutput,
                                                const char* szPrompt) const;

    // RANDOM NUMBERS
    virtual bool RandomizeMemory(uint8_t* szDestination,
                                 uint32_t nNewSize) const;

    // BASE 62 ENCODING  (for IDs)
    virtual void SetIDFromEncoded(const String& strInput,
                                  Identifier& theOutput) const;
    virtual void EncodeID(const Identifier& theInput, String& strOutput) const;
    // BASE 64 ENCODING
    // Lower-level version:
    // Caller is responsible to delete. Todo: return a unqiue pointer.
    virtual char* Base64Encode(const uint8_t* input, int32_t in_len,
                               bool bLineBreaks) const; // todo security
                                                        // ('int32_t')
    virtual uint8_t* Base64Decode(const char* input, size_t* out_len,
                                  bool bLineBreaks) const;

    virtual OTPassword* DeriveNewKey(const OTPassword& userPassword,
                                     const OTData& dataSalt,
                                     uint32_t uIterations,
                                     OTData& dataCheckHash) const;
    // ENCRYPT / DECRYPT
    // Symmetric (secret key) encryption / decryption
    virtual bool Encrypt(
        const OTPassword& theRawSymmetricKey, // The symmetric key, in clear
                                              // form.
        const char* szInput,                  // This is the Plaintext.
        uint32_t lInputLength,
        const OTData& theIV, // (We assume this IV is already generated and
                             // passed in.)
        OTData& theEncryptedOutput) const; // OUTPUT. (Ciphertext.)

    virtual bool Decrypt(const OTPassword& theRawSymmetricKey, // The symmetric
                                                               // key, in clear
                                                               // form.
                         const char* szInput, // This is the Ciphertext.
                         uint32_t lInputLength,
                         const OTData& theIV, // (We assume this IV is
                                              // already generated and passed
                                              // in.)
                         OTCrypto_Decrypt_Output theDecryptedOutput)
        const; // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR
               // OTData& here (either will work.)
    // SEAL / OPEN
    // Asymmetric (public key) encryption / decryption
    virtual bool Seal(mapOfAsymmetricKeys& RecipPubKeys, const String& theInput,
                      OTData& dataOutput) const;

    virtual bool Open(OTData& dataInput, const Nym& theRecipient,
                      String& theOutput,
                      const OTPasswordData* pPWData = nullptr) const;
    // SIGN / VERIFY
    // Sign or verify using the Asymmetric Key itself.
    virtual bool SignContract(const String& strContractUnsigned,
                              const OTAsymmetricKey& theKey,
                              OTSignature& theSignature, // output
                              const String& strHashType,
                              const OTPasswordData* pPWData = nullptr);

    virtual bool VerifySignature(const String& strContractToVerify,
                                 const OTAsymmetricKey& theKey,
                                 const OTSignature& theSignature,
                                 const String& strHashType,
                                 const OTPasswordData* pPWData = nullptr) const;
    // Sign or verify using the contents of a Certfile.
    virtual bool SignContract(const String& strContractUnsigned,
                              const String& strSigHashType,
                              const std::string& strCertFileContents,
                              OTSignature& theSignature, // output
                              const OTPasswordData* pPWData = nullptr);

    virtual bool VerifySignature(const String& strContractToVerify,
                                 const String& strSigHashType,
                                 const std::string& strCertFileContents,
                                 const OTSignature& theSignature,
                                 const OTPasswordData* pPWData = nullptr) const;
    void thread_setup() const;
    void thread_cleanup() const;

    virtual ~OTCrypto_OpenSSL();
};

#else // Apparently NO crypto engine is defined!

// Perhaps error out here...

#endif // if defined (OT_CRYPTO_USING_OPENSSL), elif defined
       // (OT_CRYPTO_USING_GPG), else, endif.

} // namespace opentxs

#endif // OPENTXS_CORE_CRYPTO_OTCRYPTO_HPP
