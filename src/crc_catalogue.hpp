// THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.

#ifndef CRCXX_CRC_CATALOGUE_HPP
#define CRCXX_CRC_CATALOGUE_HPP

#include "crc_algorithm.hpp"

namespace crcxx {

  namespace algorithms {

    ///
    /// CRC-3/GSM
    ///
    using CRC3_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 3,
      /* Poly    = */ 0x3,
      /* Init    = */ 0x0,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x7,
      /* Check   = */ 0x4,
      /* Residue = */ 0x2
    >;

    ///
    /// CRC-3/ROHC
    ///
    using CRC3_ROHC = ::crcxx::crc_algorithm<
      /* Width   = */ 3,
      /* Poly    = */ 0x3,
      /* Init    = */ 0x7,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0,
      /* Check   = */ 0x6,
      /* Residue = */ 0x0
    >;

    ///
    /// CRC-4/G-704
    ///
    using CRC4_G_704 = ::crcxx::crc_algorithm<
      /* Width   = */ 4,
      /* Poly    = */ 0x3,
      /* Init    = */ 0x0,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0,
      /* Check   = */ 0x7,
      /* Residue = */ 0x0
    >;

    ///
    /// CRC-4/ITU is an alias for CRC-4/G-704
    ///
    using CRC4_ITU = CRC4_G_704;

    ///
    /// CRC-4/INTERLAKEN
    ///
    using CRC4_INTERLAKEN = ::crcxx::crc_algorithm<
      /* Width   = */ 4,
      /* Poly    = */ 0x3,
      /* Init    = */ 0xf,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xf,
      /* Check   = */ 0xb,
      /* Residue = */ 0x2
    >;

    ///
    /// CRC-5/EPC-C1G2
    ///
    using CRC5_EPC_C1G2 = ::crcxx::crc_algorithm<
      /* Width   = */ 5,
      /* Poly    = */ 0x09,
      /* Init    = */ 0x09,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x00,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-5/EPC is an alias for CRC-5/EPC-C1G2
    ///
    using CRC5_EPC = CRC5_EPC_C1G2;

    ///
    /// CRC-5/G-704
    ///
    using CRC5_G_704 = ::crcxx::crc_algorithm<
      /* Width   = */ 5,
      /* Poly    = */ 0x15,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x07,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-5/ITU is an alias for CRC-5/G-704
    ///
    using CRC5_ITU = CRC5_G_704;

    ///
    /// CRC-5/USB
    ///
    using CRC5_USB = ::crcxx::crc_algorithm<
      /* Width   = */ 5,
      /* Poly    = */ 0x05,
      /* Init    = */ 0x1f,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x1f,
      /* Check   = */ 0x19,
      /* Residue = */ 0x06
    >;

    ///
    /// CRC-6/CDMA2000-A
    ///
    using CRC6_CDMA2000_A = ::crcxx::crc_algorithm<
      /* Width   = */ 6,
      /* Poly    = */ 0x27,
      /* Init    = */ 0x3f,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x0d,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-6/CDMA2000-B
    ///
    using CRC6_CDMA2000_B = ::crcxx::crc_algorithm<
      /* Width   = */ 6,
      /* Poly    = */ 0x07,
      /* Init    = */ 0x3f,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x3b,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-6/DARC
    ///
    using CRC6_DARC = ::crcxx::crc_algorithm<
      /* Width   = */ 6,
      /* Poly    = */ 0x19,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x26,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-6/G-704
    ///
    using CRC6_G_704 = ::crcxx::crc_algorithm<
      /* Width   = */ 6,
      /* Poly    = */ 0x03,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x06,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-6/ITU is an alias for CRC-6/G-704
    ///
    using CRC6_ITU = CRC6_G_704;

    ///
    /// CRC-6/GSM
    ///
    using CRC6_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 6,
      /* Poly    = */ 0x2f,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x3f,
      /* Check   = */ 0x13,
      /* Residue = */ 0x3a
    >;

    ///
    /// CRC-7/MMC
    ///
    using CRC7_MMC = ::crcxx::crc_algorithm<
      /* Width   = */ 7,
      /* Poly    = */ 0x09,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x75,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-7/ROHC
    ///
    using CRC7_ROHC = ::crcxx::crc_algorithm<
      /* Width   = */ 7,
      /* Poly    = */ 0x4f,
      /* Init    = */ 0x7f,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x53,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-7/UMTS
    ///
    using CRC7_UMTS = ::crcxx::crc_algorithm<
      /* Width   = */ 7,
      /* Poly    = */ 0x45,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x61,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/AUTOSAR
    ///
    using CRC8_AUTOSAR = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x2f,
      /* Init    = */ 0xff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xff,
      /* Check   = */ 0xdf,
      /* Residue = */ 0x42
    >;

    ///
    /// CRC-8/BLUETOOTH
    ///
    using CRC8_BLUETOOTH = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0xa7,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x26,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/CDMA2000
    ///
    using CRC8_CDMA2000 = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x9b,
      /* Init    = */ 0xff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xda,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/DARC
    ///
    using CRC8_DARC = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x39,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x15,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/DVB-S2
    ///
    using CRC8_DVB_S2 = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0xd5,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xbc,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/GSM-A
    ///
    using CRC8_GSM_A = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x1d,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x37,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/GSM-B
    ///
    using CRC8_GSM_B = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x49,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xff,
      /* Check   = */ 0x94,
      /* Residue = */ 0x53
    >;

    ///
    /// CRC-8/I-432-1
    ///
    using CRC8_I_432_1 = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x07,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x55,
      /* Check   = */ 0xa1,
      /* Residue = */ 0xac
    >;

    ///
    /// CRC-8/ITU is an alias for CRC-8/I-432-1
    ///
    using CRC8_ITU = CRC8_I_432_1;

    ///
    /// CRC-8/I-CODE
    ///
    using CRC8_I_CODE = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x1d,
      /* Init    = */ 0xfd,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x7e,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/LTE
    ///
    using CRC8_LTE = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x9b,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xea,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/MAXIM-DOW
    ///
    using CRC8_MAXIM_DOW = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x31,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xa1,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/MAXIM is an alias for CRC-8/MAXIM-DOW
    ///
    using CRC8_MAXIM = CRC8_MAXIM_DOW;

    ///
    /// DOW-CRC is an alias for CRC-8/MAXIM-DOW
    ///
    using CRC8_DOW_CRC = CRC8_MAXIM_DOW;

    ///
    /// CRC-8/MIFARE-MAD
    ///
    using CRC8_MIFARE_MAD = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x1d,
      /* Init    = */ 0xc7,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x99,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/NRSC-5
    ///
    using CRC8_NRSC_5 = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x31,
      /* Init    = */ 0xff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xf7,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/OPENSAFETY
    ///
    using CRC8_OPENSAFETY = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x2f,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x3e,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/ROHC
    ///
    using CRC8_ROHC = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x07,
      /* Init    = */ 0xff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xd0,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/SAE-J1850
    ///
    using CRC8_SAE_J1850 = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x1d,
      /* Init    = */ 0xff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xff,
      /* Check   = */ 0x4b,
      /* Residue = */ 0xc4
    >;

    ///
    /// CRC-8/SMBUS
    ///
    using CRC8_SMBUS = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x07,
      /* Init    = */ 0x00,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0xf4,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/TECH-3250
    ///
    using CRC8_TECH_3250 = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x1d,
      /* Init    = */ 0xff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x97,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-8/AES is an alias for CRC-8/TECH-3250
    ///
    using CRC8_AES = CRC8_TECH_3250;

    ///
    /// CRC-8/EBU is an alias for CRC-8/TECH-3250
    ///
    using CRC8_EBU = CRC8_TECH_3250;

    ///
    /// CRC-8/WCDMA
    ///
    using CRC8_WCDMA = ::crcxx::crc_algorithm<
      /* Width   = */ 8,
      /* Poly    = */ 0x9b,
      /* Init    = */ 0x00,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00,
      /* Check   = */ 0x25,
      /* Residue = */ 0x00
    >;

    ///
    /// CRC-10/ATM
    ///
    using CRC10_ATM = ::crcxx::crc_algorithm<
      /* Width   = */ 10,
      /* Poly    = */ 0x233,
      /* Init    = */ 0x000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0x199,
      /* Residue = */ 0x000
    >;

    ///
    /// CRC-10/I-610 is an alias for CRC-10/ATM
    ///
    using CRC10_I_610 = CRC10_ATM;

    ///
    /// CRC-10/CDMA2000
    ///
    using CRC10_CDMA2000 = ::crcxx::crc_algorithm<
      /* Width   = */ 10,
      /* Poly    = */ 0x3d9,
      /* Init    = */ 0x3ff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0x233,
      /* Residue = */ 0x000
    >;

    ///
    /// CRC-10/GSM
    ///
    using CRC10_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 10,
      /* Poly    = */ 0x175,
      /* Init    = */ 0x000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x3ff,
      /* Check   = */ 0x12a,
      /* Residue = */ 0x0c6
    >;

    ///
    /// CRC-11/FLEXRAY
    ///
    using CRC11_FLEXRAY = ::crcxx::crc_algorithm<
      /* Width   = */ 11,
      /* Poly    = */ 0x385,
      /* Init    = */ 0x01a,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0x5a3,
      /* Residue = */ 0x000
    >;

    ///
    /// CRC-11/UMTS
    ///
    using CRC11_UMTS = ::crcxx::crc_algorithm<
      /* Width   = */ 11,
      /* Poly    = */ 0x307,
      /* Init    = */ 0x000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0x061,
      /* Residue = */ 0x000
    >;

    ///
    /// CRC-12/CDMA2000
    ///
    using CRC12_CDMA2000 = ::crcxx::crc_algorithm<
      /* Width   = */ 12,
      /* Poly    = */ 0xf13,
      /* Init    = */ 0xfff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0xd4d,
      /* Residue = */ 0x000
    >;

    ///
    /// CRC-12/DECT
    ///
    using CRC12_DECT = ::crcxx::crc_algorithm<
      /* Width   = */ 12,
      /* Poly    = */ 0x80f,
      /* Init    = */ 0x000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0xf5b,
      /* Residue = */ 0x000
    >;

    ///
    /// X-CRC-12 is an alias for CRC-12/DECT
    ///
    using CRC12_X = CRC12_DECT;

    ///
    /// CRC-12/GSM
    ///
    using CRC12_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 12,
      /* Poly    = */ 0xd31,
      /* Init    = */ 0x000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xfff,
      /* Check   = */ 0xb34,
      /* Residue = */ 0x178
    >;

    ///
    /// CRC-12/UMTS
    ///
    using CRC12_UMTS = ::crcxx::crc_algorithm<
      /* Width   = */ 12,
      /* Poly    = */ 0x80f,
      /* Init    = */ 0x000,
      /* Refin   = */ false,
      /* Refout  = */ true,
      /* Xorout  = */ 0x000,
      /* Check   = */ 0xdaf,
      /* Residue = */ 0x000
    >;

    ///
    /// CRC-12/3GPP is an alias for CRC-12/UMTS
    ///
    using CRC12_3GPP = CRC12_UMTS;

    ///
    /// CRC-13/BBC
    ///
    using CRC13_BBC = ::crcxx::crc_algorithm<
      /* Width   = */ 13,
      /* Poly    = */ 0x1cf5,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x04fa,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-14/DARC
    ///
    using CRC14_DARC = ::crcxx::crc_algorithm<
      /* Width   = */ 14,
      /* Poly    = */ 0x0805,
      /* Init    = */ 0x0000,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x082d,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-14/GSM
    ///
    using CRC14_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 14,
      /* Poly    = */ 0x202d,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x3fff,
      /* Check   = */ 0x30ae,
      /* Residue = */ 0x031e
    >;

    ///
    /// CRC-15/CAN
    ///
    using CRC15_CAN = ::crcxx::crc_algorithm<
      /* Width   = */ 15,
      /* Poly    = */ 0x4599,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x059e,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-15/MPT1327
    ///
    using CRC15_MPT1327 = ::crcxx::crc_algorithm<
      /* Width   = */ 15,
      /* Poly    = */ 0x6815,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0001,
      /* Check   = */ 0x2566,
      /* Residue = */ 0x6815
    >;

    ///
    /// CRC-16/ARC
    ///
    using CRC16_ARC = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0x0000,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xbb3d,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/LHA is an alias for CRC-16/ARC
    ///
    using CRC16_LHA = CRC16_ARC;

    ///
    /// CRC-IBM is an alias for CRC-16/ARC
    ///
    using CRC16_CRC_IBM = CRC16_ARC;

    ///
    /// CRC-16/CDMA2000
    ///
    using CRC16_CDMA2000 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0xc867,
      /* Init    = */ 0xffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x4c06,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/CMS
    ///
    using CRC16_CMS = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0xffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xaee7,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/DDS-110
    ///
    using CRC16_DDS_110 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0x800d,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x9ecf,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/DECT-R
    ///
    using CRC16_DECT_R = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x0589,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0001,
      /* Check   = */ 0x007e,
      /* Residue = */ 0x0589
    >;

    ///
    /// R-CRC-16 is an alias for CRC-16/DECT-R
    ///
    using CRC16_R = CRC16_DECT_R;

    ///
    /// CRC-16/DECT-X
    ///
    using CRC16_DECT_X = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x0589,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x007f,
      /* Residue = */ 0x0000
    >;

    ///
    /// X-CRC-16 is an alias for CRC-16/DECT-X
    ///
    using CRC16_X = CRC16_DECT_X;

    ///
    /// CRC-16/DNP
    ///
    using CRC16_DNP = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x3d65,
      /* Init    = */ 0x0000,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0xea82,
      /* Residue = */ 0x66c5
    >;

    ///
    /// CRC-16/EN-13757
    ///
    using CRC16_EN_13757 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x3d65,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0xc2b7,
      /* Residue = */ 0xa366
    >;

    ///
    /// CRC-16/GENIBUS
    ///
    using CRC16_GENIBUS = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0xffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0xd64e,
      /* Residue = */ 0x1d0f
    >;

    ///
    /// CRC-16/DARC is an alias for CRC-16/GENIBUS
    ///
    using CRC16_DARC = CRC16_GENIBUS;

    ///
    /// CRC-16/EPC is an alias for CRC-16/GENIBUS
    ///
    using CRC16_EPC = CRC16_GENIBUS;

    ///
    /// CRC-16/EPC-C1G2 is an alias for CRC-16/GENIBUS
    ///
    using CRC16_EPC_C1G2 = CRC16_GENIBUS;

    ///
    /// CRC-16/I-CODE is an alias for CRC-16/GENIBUS
    ///
    using CRC16_I_CODE = CRC16_GENIBUS;

    ///
    /// CRC-16/GSM
    ///
    using CRC16_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0xce3c,
      /* Residue = */ 0x1d0f
    >;

    ///
    /// CRC-16/IBM-3740
    ///
    using CRC16_IBM_3740 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0xffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x29b1,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/AUTOSAR is an alias for CRC-16/IBM-3740
    ///
    using CRC16_AUTOSAR = CRC16_IBM_3740;

    ///
    /// CRC-16/CCITT-FALSE is an alias for CRC-16/IBM-3740
    ///
    using CRC16_CCITT_FALSE = CRC16_IBM_3740;

    ///
    /// CRC-16/IBM-SDLC
    ///
    using CRC16_IBM_SDLC = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0xffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0x906e,
      /* Residue = */ 0xf0b8
    >;

    ///
    /// CRC-16/ISO-HDLC is an alias for CRC-16/IBM-SDLC
    ///
    using CRC16_ISO_HDLC = CRC16_IBM_SDLC;

    ///
    /// CRC-16/ISO-IEC-14443-3-B is an alias for CRC-16/IBM-SDLC
    ///
    using CRC16_ISO_IEC_14443_3_B = CRC16_IBM_SDLC;

    ///
    /// CRC-16/X-25 is an alias for CRC-16/IBM-SDLC
    ///
    using CRC16_X_25 = CRC16_IBM_SDLC;

    ///
    /// CRC-B is an alias for CRC-16/IBM-SDLC
    ///
    using CRC16_CRC_B = CRC16_IBM_SDLC;

    ///
    /// X-25 is an alias for CRC-16/IBM-SDLC
    ///
    using CRC16_X_25 = CRC16_IBM_SDLC;

    ///
    /// CRC-16/ISO-IEC-14443-3-A
    ///
    using CRC16_ISO_IEC_14443_3_A = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0xc6c6,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xbf05,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-A is an alias for CRC-16/ISO-IEC-14443-3-A
    ///
    using CRC16_CRC_A = CRC16_ISO_IEC_14443_3_A;

    ///
    /// CRC-16/KERMIT
    ///
    using CRC16_KERMIT = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0x0000,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x2189,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/CCITT is an alias for CRC-16/KERMIT
    ///
    using CRC16_CCITT = CRC16_KERMIT;

    ///
    /// CRC-16/CCITT-TRUE is an alias for CRC-16/KERMIT
    ///
    using CRC16_CCITT_TRUE = CRC16_KERMIT;

    ///
    /// CRC-16/V-41-LSB is an alias for CRC-16/KERMIT
    ///
    using CRC16_V_41_LSB = CRC16_KERMIT;

    ///
    /// CRC-CCITT is an alias for CRC-16/KERMIT
    ///
    using CRC16_CRC_CCITT = CRC16_KERMIT;

    ///
    /// CRC-16/LJ1200
    ///
    using CRC16_LJ1200 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x6f63,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xbdf4,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/MAXIM-DOW
    ///
    using CRC16_MAXIM_DOW = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0x0000,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0x44c2,
      /* Residue = */ 0xb001
    >;

    ///
    /// CRC-16/MAXIM is an alias for CRC-16/MAXIM-DOW
    ///
    using CRC16_MAXIM = CRC16_MAXIM_DOW;

    ///
    /// CRC-16/MCRF4XX
    ///
    using CRC16_MCRF4XX = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0xffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x6f91,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/MODBUS
    ///
    using CRC16_MODBUS = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0xffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x4b37,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/NRSC-5
    ///
    using CRC16_NRSC_5 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x080b,
      /* Init    = */ 0xffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xa066,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/OPENSAFETY-A
    ///
    using CRC16_OPENSAFETY_A = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x5935,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x5d38,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/OPENSAFETY-B
    ///
    using CRC16_OPENSAFETY_B = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x755b,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x20fe,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/PROFIBUS
    ///
    using CRC16_PROFIBUS = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1dcf,
      /* Init    = */ 0xffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0xa819,
      /* Residue = */ 0xe394
    >;

    ///
    /// CRC-16/IEC-61158-2 is an alias for CRC-16/PROFIBUS
    ///
    using CRC16_IEC_61158_2 = CRC16_PROFIBUS;

    ///
    /// CRC-16/RIELLO
    ///
    using CRC16_RIELLO = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0xb2aa,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x63d0,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/SPI-FUJITSU
    ///
    using CRC16_SPI_FUJITSU = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0x1d0f,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xe5cc,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/AUG-CCITT is an alias for CRC-16/SPI-FUJITSU
    ///
    using CRC16_AUG_CCITT = CRC16_SPI_FUJITSU;

    ///
    /// CRC-16/T10-DIF
    ///
    using CRC16_T10_DIF = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8bb7,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xd0db,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/TELEDISK
    ///
    using CRC16_TELEDISK = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0xa097,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x0fb3,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/TMS37157
    ///
    using CRC16_TMS37157 = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0x89ec,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x26b1,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/UMTS
    ///
    using CRC16_UMTS = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0xfee8,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/BUYPASS is an alias for CRC-16/UMTS
    ///
    using CRC16_BUYPASS = CRC16_UMTS;

    ///
    /// CRC-16/VERIFONE is an alias for CRC-16/UMTS
    ///
    using CRC16_VERIFONE = CRC16_UMTS;

    ///
    /// CRC-16/USB
    ///
    using CRC16_USB = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x8005,
      /* Init    = */ 0xffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffff,
      /* Check   = */ 0xb4c8,
      /* Residue = */ 0xb001
    >;

    ///
    /// CRC-16/XMODEM
    ///
    using CRC16_XMODEM = ::crcxx::crc_algorithm<
      /* Width   = */ 16,
      /* Poly    = */ 0x1021,
      /* Init    = */ 0x0000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000,
      /* Check   = */ 0x31c3,
      /* Residue = */ 0x0000
    >;

    ///
    /// CRC-16/ACORN is an alias for CRC-16/XMODEM
    ///
    using CRC16_ACORN = CRC16_XMODEM;

    ///
    /// CRC-16/LTE is an alias for CRC-16/XMODEM
    ///
    using CRC16_LTE = CRC16_XMODEM;

    ///
    /// CRC-16/V-41-MSB is an alias for CRC-16/XMODEM
    ///
    using CRC16_V_41_MSB = CRC16_XMODEM;

    ///
    /// ZMODEM is an alias for CRC-16/XMODEM
    ///
    using CRC16_ZMODEM = CRC16_XMODEM;

    ///
    /// CRC-17/CAN-FD
    ///
    using CRC17_CAN_FD = ::crcxx::crc_algorithm<
      /* Width   = */ 17,
      /* Poly    = */ 0x1685b,
      /* Init    = */ 0x00000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00000,
      /* Check   = */ 0x04f03,
      /* Residue = */ 0x00000
    >;

    ///
    /// CRC-21/CAN-FD
    ///
    using CRC21_CAN_FD = ::crcxx::crc_algorithm<
      /* Width   = */ 21,
      /* Poly    = */ 0x102899,
      /* Init    = */ 0x000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0x0ed841,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/BLE
    ///
    using CRC24_BLE = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x00065b,
      /* Init    = */ 0x555555,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0xc25a56,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/FLEXRAY-A
    ///
    using CRC24_FLEXRAY_A = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x5d6dcb,
      /* Init    = */ 0xfedcba,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0x7979bd,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/FLEXRAY-B
    ///
    using CRC24_FLEXRAY_B = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x5d6dcb,
      /* Init    = */ 0xabcdef,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0x1f23b8,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/INTERLAKEN
    ///
    using CRC24_INTERLAKEN = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x328b63,
      /* Init    = */ 0xffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffffff,
      /* Check   = */ 0xb4f3e6,
      /* Residue = */ 0x144e63
    >;

    ///
    /// CRC-24/LTE-A
    ///
    using CRC24_LTE_A = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x864cfb,
      /* Init    = */ 0x000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0xcde703,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/LTE-B
    ///
    using CRC24_LTE_B = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x800063,
      /* Init    = */ 0x000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0x23ef52,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/OPENPGP
    ///
    using CRC24_OPENPGP = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x864cfb,
      /* Init    = */ 0xb704ce,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x000000,
      /* Check   = */ 0x21cf02,
      /* Residue = */ 0x000000
    >;

    ///
    /// CRC-24/OS-9
    ///
    using CRC24_OS_9 = ::crcxx::crc_algorithm<
      /* Width   = */ 24,
      /* Poly    = */ 0x800063,
      /* Init    = */ 0xffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffffff,
      /* Check   = */ 0x200fa5,
      /* Residue = */ 0x800fe3
    >;

    ///
    /// CRC-30/CDMA
    ///
    using CRC30_CDMA = ::crcxx::crc_algorithm<
      /* Width   = */ 30,
      /* Poly    = */ 0x2030b9c7,
      /* Init    = */ 0x3fffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x3fffffff,
      /* Check   = */ 0x04c34abf,
      /* Residue = */ 0x34efa55a
    >;

    ///
    /// CRC-31/PHILIPS
    ///
    using CRC31_PHILIPS = ::crcxx::crc_algorithm<
      /* Width   = */ 31,
      /* Poly    = */ 0x04c11db7,
      /* Init    = */ 0x7fffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x7fffffff,
      /* Check   = */ 0x0ce9e46c,
      /* Residue = */ 0x4eaf26f1
    >;

    ///
    /// CRC-32/AIXM
    ///
    using CRC32_AIXM = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x814141ab,
      /* Init    = */ 0x00000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00000000,
      /* Check   = */ 0x3010bf7f,
      /* Residue = */ 0x00000000
    >;

    ///
    /// CRC-32Q is an alias for CRC-32/AIXM
    ///
    using CRC32_Q = CRC32_AIXM;

    ///
    /// CRC-32/AUTOSAR
    ///
    using CRC32_AUTOSAR = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0xf4acfb13,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffffffff,
      /* Check   = */ 0x1697d06a,
      /* Residue = */ 0x904cddbf
    >;

    ///
    /// CRC-32/BASE91-D
    ///
    using CRC32_BASE91_D = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0xa833982b,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffffffff,
      /* Check   = */ 0x87315576,
      /* Residue = */ 0x45270551
    >;

    ///
    /// CRC-32D is an alias for CRC-32/BASE91-D
    ///
    using CRC32_D = CRC32_BASE91_D;

    ///
    /// CRC-32/BZIP2
    ///
    using CRC32_BZIP2 = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x04c11db7,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffffffff,
      /* Check   = */ 0xfc891918,
      /* Residue = */ 0xc704dd7b
    >;

    ///
    /// B-CRC-32 is an alias for CRC-32/BZIP2
    ///
    using CRC32_B = CRC32_BZIP2;

    ///
    /// CRC-32/AAL5 is an alias for CRC-32/BZIP2
    ///
    using CRC32_AAL5 = CRC32_BZIP2;

    ///
    /// CRC-32/DECT-B is an alias for CRC-32/BZIP2
    ///
    using CRC32_DECT_B = CRC32_BZIP2;

    ///
    /// CRC-32/CD-ROM-EDC
    ///
    using CRC32_CD_ROM_EDC = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x8001801b,
      /* Init    = */ 0x00000000,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00000000,
      /* Check   = */ 0x6ec2edc4,
      /* Residue = */ 0x00000000
    >;

    ///
    /// CRC-32/CKSUM
    ///
    using CRC32_CKSUM = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x04c11db7,
      /* Init    = */ 0x00000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffffffff,
      /* Check   = */ 0x765e7680,
      /* Residue = */ 0xc704dd7b
    >;

    ///
    /// CRC-32/POSIX is an alias for CRC-32/CKSUM
    ///
    using CRC32_POSIX = CRC32_CKSUM;

    ///
    /// CRC-32/ISCSI
    ///
    using CRC32_ISCSI = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x1edc6f41,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffffffff,
      /* Check   = */ 0xe3069283,
      /* Residue = */ 0xb798b438
    >;

    ///
    /// CRC-32/BASE91-C is an alias for CRC-32/ISCSI
    ///
    using CRC32_BASE91_C = CRC32_ISCSI;

    ///
    /// CRC-32/CASTAGNOLI is an alias for CRC-32/ISCSI
    ///
    using CRC32_CASTAGNOLI = CRC32_ISCSI;

    ///
    /// CRC-32/INTERLAKEN is an alias for CRC-32/ISCSI
    ///
    using CRC32_INTERLAKEN = CRC32_ISCSI;

    ///
    /// CRC-32C is an alias for CRC-32/ISCSI
    ///
    using CRC32_C = CRC32_ISCSI;

    ///
    /// CRC-32/ISO-HDLC
    ///
    using CRC32_ISO_HDLC = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x04c11db7,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffffffff,
      /* Check   = */ 0xcbf43926,
      /* Residue = */ 0xdebb20e3
    >;

    ///
    /// CRC-32/ADCCP is an alias for CRC-32/ISO-HDLC
    ///
    using CRC32_ADCCP = CRC32_ISO_HDLC;

    ///
    /// CRC-32/V-42 is an alias for CRC-32/ISO-HDLC
    ///
    using CRC32_V_42 = CRC32_ISO_HDLC;

    ///
    /// CRC-32/XZ is an alias for CRC-32/ISO-HDLC
    ///
    using CRC32_XZ = CRC32_ISO_HDLC;

    ///
    /// PKZIP is an alias for CRC-32/ISO-HDLC
    ///
    using CRC32_PKZIP = CRC32_ISO_HDLC;

    ///
    /// CRC-32/JAMCRC
    ///
    using CRC32_JAMCRC = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x04c11db7,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0x00000000,
      /* Check   = */ 0x340bc6d9,
      /* Residue = */ 0x00000000
    >;

    ///
    /// CRC-32/MPEG-2
    ///
    using CRC32_MPEG_2 = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x04c11db7,
      /* Init    = */ 0xffffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00000000,
      /* Check   = */ 0x0376e6e7,
      /* Residue = */ 0x00000000
    >;

    ///
    /// CRC-32/XFER
    ///
    using CRC32_XFER = ::crcxx::crc_algorithm<
      /* Width   = */ 32,
      /* Poly    = */ 0x000000af,
      /* Init    = */ 0x00000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x00000000,
      /* Check   = */ 0xbd0be338,
      /* Residue = */ 0x00000000
    >;

    ///
    /// CRC-40/GSM
    ///
    using CRC40_GSM = ::crcxx::crc_algorithm<
      /* Width   = */ 40,
      /* Poly    = */ 0x0004820009,
      /* Init    = */ 0x0000000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffffffffff,
      /* Check   = */ 0xd4164fc646,
      /* Residue = */ 0xc4ff8071ff
    >;

    ///
    /// CRC-64/ECMA-182
    ///
    using CRC64_ECMA_182 = ::crcxx::crc_algorithm<
      /* Width   = */ 64,
      /* Poly    = */ 0x42f0e1eba9ea3693,
      /* Init    = */ 0x0000000000000000,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0x0000000000000000,
      /* Check   = */ 0x6c40df5f0b497347,
      /* Residue = */ 0x0000000000000000
    >;

    ///
    /// CRC-64/GO-ISO
    ///
    using CRC64_GO_ISO = ::crcxx::crc_algorithm<
      /* Width   = */ 64,
      /* Poly    = */ 0x000000000000001b,
      /* Init    = */ 0xffffffffffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffffffffffffffff,
      /* Check   = */ 0xb90956c775a41001,
      /* Residue = */ 0x5300000000000000
    >;

    ///
    /// CRC-64/WE
    ///
    using CRC64_WE = ::crcxx::crc_algorithm<
      /* Width   = */ 64,
      /* Poly    = */ 0x42f0e1eba9ea3693,
      /* Init    = */ 0xffffffffffffffff,
      /* Refin   = */ false,
      /* Refout  = */ false,
      /* Xorout  = */ 0xffffffffffffffff,
      /* Check   = */ 0x62ec59e3f1a4f00a,
      /* Residue = */ 0xfcacbebd5931a992
    >;

    ///
    /// CRC-64/XZ
    ///
    using CRC64_XZ = ::crcxx::crc_algorithm<
      /* Width   = */ 64,
      /* Poly    = */ 0x42f0e1eba9ea3693,
      /* Init    = */ 0xffffffffffffffff,
      /* Refin   = */ true,
      /* Refout  = */ true,
      /* Xorout  = */ 0xffffffffffffffff,
      /* Check   = */ 0x995dc9bbdf1939fa,
      /* Residue = */ 0x49958c9abd7d353f
    >;

    ///
    /// CRC-64/GO-ECMA is an alias for CRC-64/XZ
    ///
    using CRC64_GO_ECMA = CRC64_XZ;

  }

}

#endif // CRCXX_CRC_CATALOGUE_HPP
