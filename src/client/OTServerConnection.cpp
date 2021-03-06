/************************************************************
 *
 *  OTServerConnection.cpp
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

#include <opentxs/core/stdafx.hpp>

#include <opentxs/client/OTServerConnection.hpp>
#include <opentxs/client/OTClient.hpp>
#include <opentxs/core/crypto/OTEnvelope.hpp>
#include <opentxs/core/Log.hpp>
#include <opentxs/core/Message.hpp>
#include <opentxs/core/Nym.hpp>
#include <opentxs/core/OTServerContract.hpp>

namespace opentxs
{

// When a certain Nym opens a certain account on a certain server,
// that account is put onto a list of accounts inside the wallet.
// Therefore, a certain Nym's connection to a certain server will
// occasionally require access to those accounts. Therefore the
// server connection object needs to have a pointer to the wallet.
// There might be MORE THAN ONE connection per wallet, or only one,
// but either way the connections need a pointer to the wallet
// they are associated with, so they can access those accounts.
OTServerConnection::OTServerConnection(OTClient* theClient,
                                       const std::string& endpoint)
    : context_zmq(1, 31)
    , socket_zmq(context_zmq, ZMQ_REQ)
    , m_pNym(nullptr)
    , m_pServerContract(nullptr)
    , m_pClient(theClient)
{
    int linger = 1000;
    socket_zmq.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));

    try {
        socket_zmq.connect(endpoint.c_str());
    }
    catch (const std::exception& e) {
        Log::vError("Failed to connect to %s: %s \n", endpoint.c_str(),
                    e.what());
        OT_FAIL;
    }
}

// When the server sends a reply back with our new request number, we
// need to update our records accordingly.
//
// This function is meant to be called when that happens, so that we
// can do just that.
//
void OTServerConnection::OnServerResponseToGetRequestNumber(
    int64_t lNewRequestNumber) const
{
    if (m_pNym && m_pServerContract) {
        otOut << "Received new request number from the server: "
              << lNewRequestNumber << ". Updating Nym records...\n";

        String strNotaryID;
        m_pServerContract->GetIdentifier(strNotaryID);
        m_pNym->OnUpdateRequestNum(*m_pNym, strNotaryID, lNewRequestNumber);
    }
    else {
        otErr << "Expected m_pNym or m_pServerContract to be not null in "
                 "OTServerConnection::OnServerResponseToGetRequestNumber.\n";
    }
}

bool OTServerConnection::GetNotaryID(Identifier& theID) const
{
    if (m_pServerContract) {
        m_pServerContract->GetIdentifier(theID);
        return true;
    }
    return false;
}

void OTServerConnection::send(OTServerContract* pServerContract, Nym* pNym,
                              const Message& theMessage)
{
    OT_ASSERT(nullptr != pServerContract);
    OT_ASSERT(nullptr != pNym)
    const Nym* pServerNym = pServerContract->GetContractPublicNym();
    OT_ASSERT(nullptr != pServerNym);

    OTEnvelope theEnvelope;
    String strEnvelopeContents;
    theMessage.SaveContractRaw(strEnvelopeContents);
    theEnvelope.Seal(*pServerNym, strEnvelopeContents);

    otOut << "\n=====>BEGIN Sending " << theMessage.m_strCommand
          << " message via ZMQ... Request number: "
          << theMessage.m_strRequestNum << "\n";

    m_pServerContract = pServerContract;
    m_pNym = pNym;
    send(theEnvelope);

    otWarn << "<=====END Finished sending " << theMessage.m_strCommand
           << " message (and hopefully receiving "
              "a reply.)\nRequest number: " << theMessage.m_strRequestNum
           << "\n\n";
}

bool OTServerConnection::send(const OTEnvelope& theEnvelope)
{
    OTASCIIArmor ascEnvelope(theEnvelope);

    if (!ascEnvelope.Exists()) {
        return false;
    }

    bool success = socket_zmq.send(ascEnvelope.Get(), ascEnvelope.GetLength());

    if (!success) {
        otErr << __FUNCTION__
              << ": Failed, even with error correction and retries, "
                 "while trying to send message to server.";
        return false;
    }

    std::string rawServerReply;
    bool bSuccessReceiving = receive(rawServerReply);

    if (!bSuccessReceiving) {
        otErr << __FUNCTION__ << ": Failed trying to receive expected reply "
                                 "from server.\n";
        return false;
    }

    String strRawServerReply(rawServerReply);
    OTASCIIArmor ascServerReply;
    const bool bLoaded = strRawServerReply.Exists() &&
                         ascServerReply.LoadFromString(strRawServerReply);
    String strServerReply;
    bool bRetrievedReply = false;
    if (!bLoaded)
        otErr << __FUNCTION__ << ": Failed trying to load OTASCIIArmor "
                                 "object from string:\n\n" << strRawServerReply
              << "\n\n";

    else if (strRawServerReply.Contains("ENVELOPE")) // Server sent this
                                                     // encrypted to my
    // public key, in an armored envelope.
    {
        OTEnvelope theServerEnvelope;
        if (theServerEnvelope.SetAsciiArmoredData(ascServerReply)) {

            bRetrievedReply = theServerEnvelope.Open(*m_pNym, strServerReply);
        }
        else {
            otErr << __FUNCTION__ << ": Failed: while setting "
                                     "OTASCIIArmor'd string into an "
                                     "OTEnvelope.\n";
            return false;
        }
    }
    // NOW ABLE TO HANDLE MESSAGES HERE IN ADDITION TO ENVELOPES!!!!
    // (Sometimes the server HAS to reply with an unencrypted reply,
    // and this is what makes it possible for the client to RECEIVE
    // that reply.)
    //
    // The Server doesn't have to accept both types, but the client
    // does,
    // since technically all clients cannot talk to it without
    // knowing its key first.
    //
    // ===> A CLIENT could POTENTIALLY have sent a message to server
    // when unregistered,
    // leaving server NO WAY to reply! Therefore server HAS to have
    // the OPTION to send
    // an unencrypted message, in that case, and the client HAS to
    // be able to receive it
    // properly!!
    //
    else if (strRawServerReply.Contains("MESSAGE")) // Server sent
                                                    // this NOT
                                                    // encrypted, in
                                                    // an armored
                                                    // message.
    {
        bRetrievedReply = ascServerReply.GetString(strServerReply);
    }
    else {
        otErr << __FUNCTION__ << ": Error: Unknown reply type received from "
                                 "server. (Expected envelope or message.)\n"
                                 "\n\n PERHAPS YOU ARE RUNNING AN OLD VERSION "
                                 "OF THE SERVER ????? \n\n";
        return false;
    }
    // todo: use a unique_ptr  soon as feasible.
    std::shared_ptr<Message> pServerReply(new Message());
    OT_ASSERT(nullptr != pServerReply);

    if (bRetrievedReply && strServerReply.Exists() &&
        pServerReply->LoadContractFromString(strServerReply)) {
        // Now the fully-loaded message object (from the server,
        // this time) can be processed by the OT library...
        // Client takes ownership and will
        m_pClient->processServerReply(pServerReply);
    }
    else {
        otErr << __FUNCTION__ << ": Error loading server reply from string:\n\n"
              << strRawServerReply << "\n\n";
        return false;
    }

    return true;
}

bool OTServerConnection::receive(std::string& serverReply)
{
    zmq::message_t zmq_message;
    if (!socket_zmq.recv(&zmq_message)) {
        return false;
    }
    serverReply.assign(static_cast<const char*>(zmq_message.data()),
                       zmq_message.size());
    return true;
}

} // namespace opentxs
