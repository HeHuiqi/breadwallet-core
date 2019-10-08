//
//  BRGeneric.h
//  Core
//
//  Created by Ed Gamble on 6/19/19.
//  Copyright © 2019 Breadwinner AG. All rights reserved.
//
//  See the LICENSE file at the project root for license information.
//  See the CONTRIBUTORS file at the project root for a list of contributors.

#ifndef BRGeneric_h
#define BRGeneric_h

#include "support/BRInt.h" // UInt256
#include "support/BRSet.h" // BRSet
#include "support/BRKey.h" // BRKey
#include "BRGenericBase.h"
#include "BRGenericWalletManager.h"

#ifdef __cplusplus
extern "C" {
#endif

    // MARK: - Network

    extern BRGenericNetwork
    gwmNetworkCreate (const char * type);

    extern void
    gwmNetworkRelease (BRGenericNetwork network);

    extern BRGenericAddress
    gwmNetworkAddressCreate (BRGenericNetwork network, const char * address);

    extern void
    gwmNetworkAddressRelease (BRGenericNetwork network, BRGenericAddress address);

    // MARK: - Account

    extern BRGenericAccount
    gwmAccountCreate (const char *type,
                      UInt512 seed);

    extern BRGenericAccount
    gwmAccountCreateWithPublicKey (const char *type,
                                   BRKey publicKey);

    extern BRGenericAccount
    gwmAccountCreateWithSerialization (const char *type,
                                       uint8_t *bytes,
                                       size_t   bytesCount);
    
    extern void
    gwmAccountRelease (BRGenericAccount account);

    extern const char *
    gwmAccountGetType (BRGenericAccount account);

    extern int
    gwmAccountHasType (BRGenericAccount account,
                       const char *type);

    extern BRGenericAddress
    gwmAccountGetAddress (BRGenericAccount account);

    extern uint8_t *
    gwmAccountGetSerialization (BRGenericAccount account, size_t *bytesCount);

     // Address

    extern char *
    gwmAddressAsString (BRGenericNetwork nid,
                        BRGenericAddress aid);

    extern int
    gwmAddressEqual (BRGenericNetwork nid,
                     BRGenericAddress aid1,
                     BRGenericAddress aid2);

    // Transfer

    extern BRGenericTransfer
    gwmTransferCreate (BRGenericWalletManager gwm,
                       BRGenericWallet wid,
                       BRGenericAddress target,
                       UInt256 amount);

    extern void
    gwmTransferRelease (BRGenericWalletManager gwm, BRGenericTransfer transfer);

    extern BRGenericAddress
    gwmTransferGetSourceAddress (BRGenericWalletManager gwm,
                                 BRGenericTransfer tid);

    extern BRGenericAddress
    gwmTransferGetTargetAddress (BRGenericWalletManager gwm,
                                 BRGenericTransfer tid);

    extern UInt256
    gwmTransferGetAmount (BRGenericWalletManager gwm,
                          BRGenericTransfer tid);

    extern UInt256
    gwmTransferGetFee (BRGenericWalletManager gwm,
                       BRGenericTransfer tid);

    extern BRGenericFeeBasis
    gwmTransferGetFeeBasis (BRGenericWalletManager gwm,
                            BRGenericTransfer tid);

    extern BRGenericHash
    gwmTransferGetHash (BRGenericWalletManager gwm,
                        BRGenericTransfer tid);

    extern BRArrayOf(BRGenericTransfer)
    gwmLoadTransfers (BRGenericWalletManager gwm);

    // Wallet


    /**
     * Create the PrimaryWallet for `gwm`
     */
    extern BRGenericWallet
    gwmWalletCreate (BRGenericWalletManager gwm);

    extern void
    gwmWalletRelease (BRGenericWalletManager gwm, BRGenericWallet wallet);

    extern UInt256
    gwmWalletGetBalance (BRGenericWalletManager gwm,
                          BRGenericWallet wallet);

    extern BRGenericAddress
    gwmWalletGetAddress (BRGenericWalletManager gwm,
                         BRGenericWallet wid);

    extern BRGenericFeeBasis
    gwmWalletGetDefaultFeeBasis (BRGenericWalletManager gwm,
                                 BRGenericWallet wid);

    extern void
    gwmWalletSetDefaultFeeBasis (BRGenericWalletManager gwm,
                                 BRGenericWallet wid,
                                 BRGenericFeeBasis bid);

    extern UInt256
    gwmWalletEstimateTransferFee (BRGenericWalletManager gwm,
                                  BRGenericWallet wid,
                                  UInt256 amount,
                                  BRGenericFeeBasis feeBasis,
                                  int *overflow);

    extern void
    gwmWalletSubmitTransfer (BRGenericWalletManager gwm,
                             BRGenericWallet wid,
                             BRGenericTransfer tid,
                             UInt512 seed);

#endif /* BRGeneric_h */
